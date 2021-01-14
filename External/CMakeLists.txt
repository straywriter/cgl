
add_subdirectory(./googletest-release-1.10.0)


# add_subdirectory(./fmt)


add_subdirectory(./fmt EXCLUDE_FROM_ALL)
# find_package(fmt)

set(ExternalLib   fmt::fmt-header-only CACHE STRING "" FORCE)