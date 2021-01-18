


# set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_subdirectory(./googletest)


# set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(./rapidjson)


add_subdirectory(./tinyxml2)


add_subdirectory(./fmt EXCLUDE_FROM_ALL)
# find_package(fmt)

set(ExternalLib   fmt::fmt-header-only CACHE STRING "" FORCE)