# SelfUpdate
The goal here is learning about auto updating applications

# Developer
Name:  Anthony
Email: Anthony.Tracy@colorado.edu

# Version Definition
Major    - For larger overhauls, things like Changing workflows, etc.
Minor    - For adding features, things like new buttons, etc.
SubMinor - For fixing bugs, logic

# The idea (First stages)
Start with something simple: An app that prints "Hello World: Your Current Version is: Major.Minor.SubMinor
1. On Startup:
   1.1 GetVersion()
       Is it the same as newest in versions subDir?
          True - Cleanup curr directory to remove older version and check that old version did shut down correctly
          False - Start newest version, verify it is running, kill self
2. Open some type of UI
   2.1 Print: Hello World! Your current software version is: Major.Minor.Subminor

# The next Idea (Second stage) - I don't want to think about this fully till stage one has UTs and is working
