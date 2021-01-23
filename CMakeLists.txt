# Adding build flags 
option(BUILD_SELF_UPDATE_UNIT_TESTS "Build Self Update App Unit Tests" OFF) # Turn on later when I have them
option(BUILD_SELF_UPDATE_BENCHMARKS "Build Self Update App Benchmarks" OFF)

# Setup building on UNIX or Windows (Currenly I dont have a IOS or IOS VM)
if (UNIX)
  set( GCC_CPP_14_FLAGS "--std=C++14" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_CPP_14_FLAGS}" )
endif(UNIX) 

if(WIN32)
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_UNICODE -DUNICODE" )
endif(WIN32)

### Setup srcs
set(SOURCES
  src/main.cpp
)

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

### Setup library
add_library( self-update STATIC ${SOURCES} )

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

