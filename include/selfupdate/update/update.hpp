#ifndef UPDATE_d2530f58_468a_40ca_bc96_b67a15863183
#define UPDATE_d2530f58_468a_40ca_bc96_b67a15863183

#include <selfupdate/version/version.hpp>

namespace SelfUpdate {
  namespace Update {

    class Updater
    {
    public:
      Updater(std::string url, SelfUpdate::Version::VersionData currVersion)
        : url_(url), currVersion_(currVersion) 
      {}

      // Get the URL that is being checked for updates
      std::string getUrl()
      {
        return url_;
      }

      // Get the current verion data used by the updater
      SelfUpdate::Version::VersionData getCurrentVersionData()
      {
        return currVersion_;
      }

      // Check for updates method

      // Update method

    private:
      std::string url_;
      SelfUpdate::Version::VersionData currVersion_;
    };
  }
} // end of namespace selfupdate::update
#endif // End include guard