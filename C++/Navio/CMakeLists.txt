cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

project(Navio2)
set(PACKAGE_VERSION 1.0.0)

# Collect all source files
file(GLOB_RECURSE COMMON_SOURCES "Common/*.cpp")
file(GLOB_RECURSE NAVIO2_SOURCES "Navio2/*.cpp")

# Create a static library
add_library(navio2 STATIC ${COMMON_SOURCES} ${NAVIO2_SOURCES})

# Specify include directories
target_include_directories(navio2 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

# Specify installation paths
include(GNUInstallDirs)
install(TARGETS navio2
    EXPORT Navio2Targets
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install header files to the include directory
install(DIRECTORY Common/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Navio2)
install(DIRECTORY Navio2/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Navio2)

# Create a Config.cmake file for find_package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    Navio2ConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/Navio2Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/Navio2/cmake
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/Navio2Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/Navio2ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/Navio2/cmake
)

# Install the export set for use with the install-tree
install(EXPORT Navio2Targets
    FILE Navio2Targets.cmake
    NAMESPACE Navio2::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/Navio2/cmake
)
