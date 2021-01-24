# SelfUpdate
The goal here is learning about auto updating applications

# Developer
Name:  Anthony
Email: Anthony.Tracy@colorado.edu

# Version Definition
Major - For larger overhauls, things like Changing workflows, etc.
Minor - For adding features, things like new buttons, etc.
Patch - For fixing bugs, logic, etc.

# How to compile
So far it has been tested with Windows 10 and Ubuntu 16.
Windows:
Install Visual Studio compiler (this has been tested with VS14)
cd (path/to/superDirectory)/build/
cmake ..
cmake --build
cd <path/to/superDirectory>/build/Debug/
./SelfUpdate<VersionNumber>.exe

Windows:
cd (path/to/superDirectory)/build/
cmake ..
make -j4
cd <path/to/superDirectory>/build/
./SelfUpdate<VersionNumber>.exe


# The idea (First stages)
Start with something simple: An app that prints "Hello World: Your Current Version is: Major.Minor.SubMinor
1. On Startup:
   1.1 Start Updater
       - Checks if there is a newer version in a local subdirectory "versions"
          False - Cleanup curr directory to remove older version and check that old version did shut down correctly
          True - Start newest version, verify it is running, kill self
       - Updater should be a on it's own thread and checking for updates at some time interval from github repo (since it's free, 
         in production it would be bettter to have a CI system like teamcity pushing artifacts with recent builds which this would instead check)
       - Let updater using something like libcurl (since it can be compiled from source for linux, windows, etc)
       -  
       
2. Open some type of UI
   2.1 Print: Hello World! Your current software version is: Major.Minor.Subminor
       - While the app is running the background thread will be running Updater which query the webpage every N hours (N is undecided atm)
       - If a newer version occurs, ask user if they would like to update 
         - If Yes - Have the app call updater.update() with just downloads the newer version into the version subdirectory, starts it,
           and ends itself
         - If no - let user keep doing what they are doing, the updater will ask again later (like windows) 
           -- NOTE: This could get annoying, perhaps have a flag that indicates user declined update. Just meaning when they close the app it will update on next startup
# The next Idea (Second stage) - I don't want to think about this fully till stage one has UTs and is working
