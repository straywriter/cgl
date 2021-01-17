
add_subdirectory(./googletest)
add_subdirectory(./rapidjson)


# add_subdirectory(./fmt)


add_subdirectory(./fmt EXCLUDE_FROM_ALL)
# find_package(fmt)

set(ExternalLib   fmt::fmt-header-only CACHE STRING "" FORCE)