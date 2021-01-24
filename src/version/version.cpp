#include <selfupdate/version/version.hpp>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

namespace SelfUpdate { namespace Version {

    std::vector<std::string> split(const std::string& s, char delimiter)
    {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
    }

    // Create a version object from a given filename
    SelfUpdate::Version::VersionData::VersionData(std::string filename)
    {
        // TODO: When I have time, replace this with Boost::Split
        // TODO: Also test this because this is assuming the filename never changes
        auto firstSplit = split(filename, '_');
        auto secondSplit = split(firstSplit.back(), '.');
        major_ = std::stoi(secondSplit[0]);
        minor_ = std::stoi(secondSplit[1]);
        patch_ = std::stoi(secondSplit[2]);   
    }

}} // End of namespaces