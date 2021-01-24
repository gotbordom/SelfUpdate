#ifndef UPDATE_d2530f58_468a_40ca_bc96_b67a15863183
#define UPDATE_d2530f58_468a_40ca_bc96_b67a15863183

#include <selfupdate/version/version.hpp>

#include <algorithm>
#include <fstream>
#include <functional>
#include <list>
#include <memory>

// curl includes
#include <curl/curl.h>

namespace SelfUpdate { namespace Update {


// TODO: I got tired and auto piloted. I need to move most of this into the cpp
class Updater
{
public:
    // Constructor that takes Url and VersionData
    Updater(std::string url, std::string versionDir, SelfUpdate::Version::VersionData currentVersionData)
        : url_(url), currentVersionData_(currentVersionData)
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }

    // Destructor needs to call curl cleanup
    ~Updater() { curl_global_cleanup(); }

    std::string getUrl()
    {
        return url_;
    }

    std::string getVersionDir()
    {
        return versionDir_;
    }

    SelfUpdate::Version::VersionData getCurrentVersionData()
    {
        return currentVersionData_;
    }

    // helper method for creating "easy handles"
    using EasyHandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;
    EasyHandle CreateEasyHandle();

    // Callback method to be used in save_to_file
    static size_t write_to_file(void* contents, size_t size, size_t nmemb, void* userp);

    // Method to use a CURL object to save a file
    void save_to_file(CURL* curl);

    void set_ssl(CURL* curl);

    void AcquireUpdates();

private:
    std::string url_;
    std::string versionDir_;
    SelfUpdate::Version::VersionData currentVersionData_;
};



}} // end of namespace selfupdate::update
#endif // End include guard