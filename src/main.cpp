// Project Includes
#include <selfupdate/version/version.hpp>
#include <selfupdate/update/update.hpp>

// curl includes
#include <curl/curl.h>

// CPP Includes
#include <iostream>

// Relative path includes
#include "include/selfupdate/config.h"

void printDetails()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "Project Name: " << PROJECT_NAME << std::endl;
    std::cout << "Version: " << PROJECT_VERSION << std::endl;
}

int main()
{
    printDetails();
    
    // On startup look for update
    auto currentVersionData = SelfUpdate::Version::VersionData(
      std::stoi(PROJECT_VERSION_MAJOR),
      std::stoi(PROJECT_VERSION_MINOR),
      std::stoi(PROJECT_VERSION_PATCH));
    // TODO for now just get it working with one file downloaded a few times
    // -- Then worry about writing it to the correct filename - SelfUpdate_<Version>
    // -- Then impliment the rest of update: 
    //     1. operator() - so that the class can be passed into a thread and run in backgroun
    //     2. CheckUpdates() - once updates are downloaded parse each object and compare against current
    //     3. Update() - which starts new version, ends current version.
    auto updater = SelfUpdate::Update::Updater(
        "https://github.com/gotbordom/SelfUpdate/raw/main/build/Versions/SelfUpdate_1.0.0", 
        "./Version/", // TODO: Import std::filesystem::path to ensure this works as a correct path
        currentVersionData);

    return 0;
}
