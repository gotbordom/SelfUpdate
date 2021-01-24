cmake_minimum_required(VERSION 3.11)

set(PROJECT_VERSION 1.0.0)

project(SelfUpdate VERSION ${PROJECT_VERSION})

# Configured header
configure_file(include/selfupdate/config.h.in include/selfupdate/config.h) 

# Add curl submodule
set(HTTP_ONLY ON)
set(CMAKE_USE_OPENSSL OFF)
set(BUILD_CURL_EXE OFF)
set(CURL_STATICLIB ON)
set(CURL_ZLIB OFF)
set(CMAKE_USE_LIBSSH2 OFF)  
add_subdirectory(curl)

##############
# UPDATER
##############
set(update_SRCS
  include/selfupdate/update/update.hpp
  src/update/update.cpp
)
source_group(update FILES ${update_SRCS})
set(SOURCES ${SOURCES} ${update_SRCS})

##############
# VERSION
##############

set(version_SRCS 
  include/selfupdate/version/version.hpp
)
source_group(version FILES ${version_SRCS})
set(SOURCES ${SOURCES} ${version_SRCS})

### Add the exe
include_directories(include)

set(exeName SelfUpdate_${PROJECT_VERSION})
set(SOURCES src/main.cpp ${SOURCES})
add_executable(${exeName} ${SOURCES})
target_link_libraries(${exeName} curl)

### Setup Unit Tests
# Once I have some add a library for them with the source group from above

# Make a macro for making a unit test... use google tests...

### Setup benchmarks
# Likely won't actually have any for this project. If I do see comments for unit tests

### Setup install binaries
# Shouldn't need this for this project


# Inlcude Directories
include_directories(${PROJECT_BINARY_DIR})

