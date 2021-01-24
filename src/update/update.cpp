#include <selfupdate/update/update.hpp>

//cpp headers
#include <algorithm>
#include <fstream>
#include <functional>
#include <list>
#include <memory>

// curl includes
#include <curl/curl.h>

namespace SelfUpdate { namespace Update {

    // create curl "easy handle" - this is for syncronous file download
    // TODO: Learn more about curl and switch to async filedownload
    using EasyHandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;
    EasyHandle SelfUpdate::Update::Updater::CreateEasyHandle()
    {
        auto curl = EasyHandle(curl_easy_init(), curl_easy_cleanup);
        if (!curl)
        {
            throw std::runtime_error("Failed to create CURL object.");
        }
        return curl;
    }

    // Method to write out data using curl
    size_t SelfUpdate::Update::Updater::write_to_file(
        void* contents, size_t size, size_t nmemb, void* userp)
    {
        size_t realsize = size * nmemb;
        auto file = reinterpret_cast<std::ofstream*>(userp);
        file->write(reinterpret_cast<const char*>(contents), realsize);
        return realsize;
    }
    
    
    void SelfUpdate::Update::Updater::save_to_file(CURL* curl)
    {
        // TODO: Once I have this actually writting to Version/destination_data
        //  then pull the filename from the curl obj... somehow
        static std::ofstream file(
            getVersionDir() + "destination_data", std::ios::binary);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, 
            SelfUpdate::Update::Updater::write_to_file);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, reinterpret_cast<void*>(&file));
    }

    // Turn off ssl verification
    void SelfUpdate::Update::Updater::set_ssl(CURL* curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    }

    void SelfUpdate::Update::Updater::AcquireUpdates()
    {
        // Setup handles
        // TODO: I would rather query how many files are in the directory
        std::list<EasyHandle> handles(3);
        try
        {
            std::for_each(handles.begin(), handles.end(), [](auto& handle) 
            {
                handle = CreateEasyHandle(); 
            });
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        for (auto& handle : handles)
        {
            /* set options */
            curl_easy_setopt(handle.get(), CURLOPT_URL, getUrl());
            set_ssl(handle.get());
            save_to_file(handle.get());
            /* Perform the request, res will get the return code */
            auto res = curl_easy_perform(handle.get());
            /* Check for errors */
            if (res != CURLE_OK)
            {
                std::cerr << "curl_easy_perform() failed:" <<
                    curl_easy_strerror(res) << std::endl;
            }
        }

    }

}}