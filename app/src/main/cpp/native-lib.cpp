#include <jni.h>
#include <android/bitmap.h>
#include <android/log.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

using namespace cv;

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-lib", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "native-lib", __VA_ARGS__))

extern "C"
JNIEXPORT void JNICALL
Java_com_example_edgedetectionviewer_NativeLib_processBitmap(JNIEnv *env, jobject /* this */, jobject bitmap) {
    if (bitmap == nullptr) {
        LOGE("bitmap is null");
        return;
    }

    AndroidBitmapInfo info;
    void* pixels = nullptr;
    if (AndroidBitmap_getInfo(env, bitmap, &info) < 0) {
        LOGE("AndroidBitmap_getInfo failed");
        return;
    }

    if (info.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        // ideally expect ARGB_8888; fail gracefully
        LOGE("Bitmap format is not RGBA_8888");
        return;
    }

    if (AndroidBitmap_lockPixels(env, bitmap, &pixels) < 0) {
        LOGE("AndroidBitmap_lockPixels failed");
        return;
    }

    // create Mat header pointing to bitmap pixels (RGBA)
    Mat src(info.height, info.width, CV_8UC4, pixels);
    Mat gray, edges, rgbaOut;

    // Convert RGBA to Gray
    cvtColor(src, gray, COLOR_RGBA2GRAY);

    // Canny
    Canny(gray, edges, 100, 200);

    // Convert single-channel edges to RGBA for display (white edges on black background)
    cvtColor(edges, rgbaOut, COLOR_GRAY2RGBA);

    // copy back to bitmap memory
    rgbaOut.copyTo(src);

    AndroidBitmap_unlockPixels(env, bitmap);
}
