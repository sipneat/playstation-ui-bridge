cmake_minimum_required(VERSION 3.4.1)
project(PlaystationUiBridge)

set (CMAKE_VERBOSE_MAKEFILE ON)

add_library(
    react-native-playstation-ui-bridge    STATIC
    ../cpp/PlaystationUiBridgeImpl.cpp
)

set_target_properties(
    react-native-playstation-ui-bridge PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(
    react-native-playstation-ui-bridge    PUBLIC
    ../cpp
)

target_link_libraries(
    react-native-playstation-ui-bridge    jsi
    reactnative
    react_codegen_PlaystationUiBridgeSpec
)
