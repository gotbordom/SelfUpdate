#ifndef UPDATE_d2530f58_468a_40ca_bc96_b67a15863183
#define UPDATE_d2530f58_468a_40ca_bc96_b67a15863183

#include <selfupdate/version/version.hpp>

//cpp headers
#include <algorithm>
#include <fstream>
#include <functional>
#include <list>
#include <memory>

// curl includes
#include <curl/curl.h>

namespace SelfUpdate { namespace Update {

class Updater
{
public:

    // Default constructor
    Updater();

    // Constructor that takes Url and VersionData
    Updater(std::string url, std::string versionDir, SelfUpdate::Version::VersionData currentVersionData)
        : url_(url), currentVersionData_(currentVersionData)
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }

    // Destructor needs to call curl cleanup
    ~Updater() { curl_global_cleanup(); }
    
    // create curl "easy handle" - this is for syncronous file download
    // TODO: Learn more about curl and switch to async filedownload
    using EasyHandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;
    EasyHandle CreateEasyHandle()
    {
        auto curl = EasyHandle(curl_easy_init(), curl_easy_cleanup);
        if (!curl)
        {
            throw std::runtime_error("Failed to create CURL object.");
        }
        return curl;
    }

    size_t write_to_file(void* contents, size_t size, size_t nmemb, void* userp)
    {
        size_t realsize = size * nmemb;
        auto file = reinterpret_cast<std::ofstream*>(userp);
        file->write(reinterpret_cast<const char*>(contents), realsize);
        return realsize;
    }
    
    void save_to_file(CURL* curl)
    {
        static std::ofstream file(versionDir_ + "/downloaded_data", std::ios::binary);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_file);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, reinterpret_cast<void*>(&file));
    }

    void set_ssl(CURL* curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    }

    void AcquireUpdates()
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
            std::cerr << e.what() << '\n';
        }
        
        for (auto& handle : handles)
        {
            /* set options */
            curl_easy_setopt(handle.get(), CURLOPT_URL, url_);
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

private:
    std::string url_;
    std::string versionDir_;
    SelfUpdate::Version::VersionData currentVersionData_;
};



}} // end of namespace selfupdate::update
#endif // End include guard