#include <jni.h>
#include <stdio.h>
#include "com_whalefall_learncases_callc_HelloJNI.h" // 包含生成的头文件

JNIEXPORT jstring JNICALL Java_com_whalefall_learncases_callc_HelloJNI_sayHello
        (JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "Hello from C!");
}
