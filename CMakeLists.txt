cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 11)
# add_definitions(-std=c++11)
# C++ generic library
project(cgl)


if(MSVC)
  set(variables CMAKE_CXX_FLAGS_DEBUG 
                CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_RELWITHDEBINFO 
                CMAKE_CXX_FLAGS_MINSIZEREL)
  foreach(variable ${variables})
    if(${variable} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
    endif()
  endforeach()
endif()
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /Zc:__cplusplus")
endif()



add_subdirectory(./External)

add_subdirectory(./Include)

add_subdirectory(./Src)

file(GLOB_RECURSE IncludeFile ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h CACHE STRING "" FORCE)


# test
enable_testing()
add_subdirectory(./Test)