// Project Includes
#include <selfupdate/version/version.hpp>

// CPP Includes
#include <iostream>

// Relative path includes
#include "include/selfupdate/config.h"

void runSomeTests()
{
    // TODO: When I have more time make this an actual app
    // and move these simple tests to an actual test directory and setup unit tests
    std::cout << "Testing Constructor from Ints: " << std::endl;
    auto versionDataFromInts = SelfUpdate::Version::VersionData(
        std::stoi(PROJECT_VERSION_MAJOR), 
        std::stoi(PROJECT_VERSION_MINOR), 
        std::stoi(PROJECT_VERSION_PATCH));
    std::cout << "Major: " << versionDataFromInts.getMajor() << std::endl;
    std::cout << "Minor: " << versionDataFromInts.getMinor() << std::endl;
    std::cout << "Patch: " << versionDataFromInts.getPatch() << std::endl;

    std::cout << "Testing Constructor from String: " << std::endl;
    std::string filename = "ThisIsATest_1.0.1";
    auto versionDataFromStr = SelfUpdate::Version::VersionData(filename);
    std::cout << "Major: " << versionDataFromStr.getMajor() << std::endl;
    std::cout << "Minor: " << versionDataFromStr.getMinor() << std::endl;
    std::cout << "Patch: " << versionDataFromStr.getPatch() << std::endl;

    std::cout << "Testing equality operators" << std::endl;
    std::cout << "FromStr >= FromInts: " 
        << std::to_string(versionDataFromStr >= versionDataFromInts) << std::endl;

    
}

void printDetails()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "Project Name: " << PROJECT_NAME << std::endl;
    std::cout << "Version: " << PROJECT_VERSION << std::endl;
}

int main()
{

    // On startup look ofr update

    std::cout << "Running some tests:" << std::endl;
    runSomeTests();

    return 0;
}