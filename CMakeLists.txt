cmake_minimum_required(VERSION 3.10)
project(PmaXWireCut)
set(CMAKE_CXX_STANDARD 17)

# External libs
add_subdirectory(external/dxfrw)
add_subdirectory(external/clipper)
add_subdirectory(external/json)
add_subdirectory(external/inja)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/external/dxfrw/src)
include_directories(${PROJECT_SOURCE_DIR}/external/json/include)
include_directories(${PROJECT_SOURCE_DIR}/external/clipper/include)
include_directories(${PROJECT_SOURCE_DIR}/external/inja/include)

file(GLOB SOURCES src/*.cpp)
add_executable(PmaXWireCut ${SOURCES})

if (WIN32)
    target_link_libraries(PmaXWireCut PRIVATE drw clipper inja user32 gdi32)
endif()

# Packaging
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "PmaXWireCut")
set(CPACK_PACKAGE_VENDOR "IDEA CNC Co., Ltd.")
set(CPACK_PACKAGE_CONTACT "peerawaz@hotmail.com")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_GENERATOR "ZIP;NSIS")
install(TARGETS PmaXWireCut DESTINATION bin)
install(FILES README.md DESTINATION .)
include(CPack)
