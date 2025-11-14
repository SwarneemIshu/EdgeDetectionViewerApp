package com.example.edgedetectionviewer

import android.graphics.Bitmap

class NativeLib {
    external fun processBitmap(bitmap: Bitmap)
    companion object {
        init { System.loadLibrary("native-lib") }
    }
}
