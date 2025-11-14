# EdgeDetectionViewer (Android + Web)

A real-time Canny Edge Detection application built using:

- **Android (Kotlin)**git 
- **CameraX**
- **OpenCV (native C++ via JNI)**
- **NDK + CMake**
- **TypeScript (Web Companion Dashboard – optional)**

This project demonstrates how to process camera frames on-device using native OpenCV for maximum speed and accuracy.

## 🚀 Features Implemented

### ✅ Android App Features
- Real-time **CameraX** camera preview
- Frame conversion **ImageProxy → Bitmap → Mat**
- Native **OpenCV Canny Edge Detection** using JNI
- Optimized **NDK/C++** processing for fast edge detection
- Output displayed in an **ImageView**
- Clean modular architecture (Kotlin → JNI → C++)
- Works fully offline

### 🌐 Web Features 
If using the Web companion:
- Real-time frame viewer (TypeScript + Canvas)
- WebSocket-based communication
- Display processed frames from Android device
- Dashboard (FPS, logs, controls)

## Output Images
![Image](https://github.com/user-attachments/assets/aace6319-690b-4954-a2cb-fc0e4a046f30)
![Image](https://github.com/user-attachments/assets/23282a57-a607-4d6d-8f54-2d57aeeabb2f)