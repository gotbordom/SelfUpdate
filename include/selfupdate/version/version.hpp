#ifndef VERSION_3886f3db_1d98_4946_8f43_60a0dd8f80b4
#define VERSION_3886f3db_1d98_4946_8f43_60a0dd8f80b4

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

namespace SelfUpdate { namespace Version {

class VersionData
{
public:
    // Create a version object from a given filename
    VersionData();
    VersionData(std::string filename);    
    VersionData(int major, int minor, int patch)
        : major_(major), minor_(minor), patch_(patch) 
    {}

    // Get the full version as a string
    std::string getVersionString()
    {
        return std::to_string(major_) + "." 
            + std::to_string(minor_) + "."
            + std::to_string(patch_);
    }

    // Get the major version number
    int getMajor()
    {
        return major_;
    }

    void setMajor(int major)
    {
        major_ = major;
    }
    
    // Get the minor version number
    int getMinor()
    {
        return minor_;
    }

    void setMinor(int minor)
    {
        minor_ = minor;
    }

    // Get the patch number
    int getPatch()
    {
        return patch_;
    }

    void setPatch(int patch)
    {
        patch_ = patch;
    }

    // Check equality of two version objects
    bool operator==(const VersionData &rhs)
    {
        bool isMajorEQ = major_ >= rhs.major_;
        bool isMinorEQ = minor_ >= rhs.minor_; 
        bool isPatchEQ = patch_ >= rhs.patch_;

        return (isPatchEQ && isMinorEQ && isMajorEQ);
    }

    // Check inequaity of two version objects
    bool operator!=(const VersionData &rhs)
    {
        return !operator==(rhs);
    }

    // Greater than equal operator
    bool operator>=(const VersionData &rhs)
    {
        // Major * 100 + minor * 10 + patch assumes a fixed amount for each 
        // so ... something else...
        bool isMajorGTE = major_ >= rhs.major_;
        bool isMinorGTE = minor_ >= rhs.minor_; 
        bool isPatchGTE = patch_ >= rhs.patch_;

        return (isPatchGTE && isMinorGTE && isMajorGTE);
    }

    // Less than operator
    bool operator<(const VersionData &rhs)
    {
        return !operator>=(rhs);
    }

private:
    int major_;
    int minor_;
    int patch_;

};

}} // end of namespace SelfUpdate::Version

#endif // End of include guard