cmake_minimum_required(VERSION 3.10.2)
project("edgedetectionviewer")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use current source dir (this CMakeLists is in app/src/main/cpp)
set(OPENCV_CPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# show include path at configure time (helpful for debugging)
message(STATUS "OPENCV_CPP_DIR = ${OPENCV_CPP_DIR}")

add_library(native-lib SHARED native-lib.cpp)

# Make sure the native target can find headers
target_include_directories(native-lib PRIVATE
        ${OPENCV_CPP_DIR}
        ${OPENCV_CPP_DIR}/opencv4
)

# import OpenCV shared lib (.so) from jniLibs
add_library(opencv_java4 SHARED IMPORTED)
set_target_properties(opencv_java4 PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/arm64-v8a/libopencv_java4.so)

find_library(log-lib log)
find_library(jnigraphics-lib jnigraphics)

target_link_libraries(native-lib opencv_java4 ${log-lib} ${jnigraphics-lib})
