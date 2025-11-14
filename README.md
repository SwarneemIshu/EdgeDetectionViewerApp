EdgeDetectionViewer is an Android app that performs **real-time Canny Edge Detection** using:

- **CameraX** (live camera preview)
- **OpenCV Android SDK**
- **JNI + C++ (native Canny processing)**
- **CMake**
- **Kotlin**

## Features
- Real-time camera feed
- Conversion of ImageProxy → Bitmap → Mat
- Native C++ Canny edge detection using OpenCV
- Displays processed frame using ImageView
- Full GPU/NDK optimized performance

## Tech Stack
- Kotlin
- CameraX
- OpenCV (`libopencv_java4.so`)
- `libc++_shared.so`
- JNI / C++
- CMake
