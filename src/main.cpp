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
    auto updater = SelfUpdate::Update::Updater("SomeGitUrl", currentVersionData);

    return 0;
}
