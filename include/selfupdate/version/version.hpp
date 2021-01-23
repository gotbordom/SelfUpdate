#ifndef VERSION_3886f3db_1d98_4946_8f43_60a0dd8f80b4
#define VERSION_3886f3db_1d98_4946_8f43_60a0dd8f80b4

#include <iostream>
#include <string>

namespace SelfUpdate { namespace Version {

class Version
{
public:
    // Create a version object from a given filename
    Version(const std::string filename);
    
    Version(int major, int minor, int patch)
        : major_(major), minor_(minor_), patch_(patch) 
    {}

    // Default destructor
    ~Version();

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

    // Get the minor version number
    int getMinor()
    {
        return minor_;
    }

    // Get the patch number
    int getPatch()
    {
        return patch_;
    }

    // Check equality of two version objects
    bool operator==(const Version &rhs)
    {
        // TODO: Atually implement this
        return true;
    }

    // Check inequaity of two version objects
    bool operator!=(const Version &rhs)
    {
        return !operator==(rhs);
    }

private:
    int major_;
    int minor_;
    int patch_;

};

}} // end of namespace SelfUpdate::Version

#endif // End of include guard