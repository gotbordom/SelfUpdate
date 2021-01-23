cmake_minimum_required(VERSION 3.11)
project(SelfUpdate VERSION 1.0.0)

# Configured header
configure_file(include/selfupdate/config.h.in include/selfupdate/config.h) 

# Adding build flags 
option(BUILD_SELF_UPDATE_UNIT_TESTS "Build Self Update App Unit Tests" OFF) # Turn on later when I have them
option(BUILD_SELF_UPDATE_BENCHMARKS "Build Self Update App Benchmarks" OFF)

### Set source groups

##############
# BENCHMARKS
##############

##############
# TESTS
##############

##############
# UI
##############

##############
# UPDATE
##############

##############
# UTILS
##############

##############
# VERSION
##############

### Add the exe
add_executable(SelfUpdate src/main.cpp)

### Setup library
# Likely won't need these either... but might as well put it here for future use

### Setup dependancies
# Don't really have any atm
# target_link_libraries()

### Exporting includes
# Shouldn't need to for this project

### Setup Unit Tests
# Once I have some add a library for them with the source group from above

# Make a macro for making a unit test... use google tests...

### Setup benchmarks
# Likely won't actually have any for this project. If I do see comments for unit tests

### Setup install binaries
# Shouldn't need this for this project


# Inlcude Directories
include_directories(${PROJECT_BINARY_DIR})

