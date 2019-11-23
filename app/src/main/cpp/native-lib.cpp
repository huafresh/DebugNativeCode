#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>

#include "ExampleService.h"
#include "binder_ndk.h"

using namespace std;


#define logD(...) __android_log_print(ANDROID_LOG_DEBUG, "@@@hua", __VA_ARGS__, NULL)

#include <sub/add.h>

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_hua_debugnativecode_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    int added = add(3, 2);

    logD("2 + 32 = %i", added);

    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_hua_debugnativecode_MainActivity_sendBinder(JNIEnv *env, jclass type) {

    // TODO
    callme(2, 1);

}

JNIEXPORT void JNICALL
Java_com_hua_debugnativecode_MainActivity_addService(JNIEnv *env, jclass type) {

    // TODO
    callme(1, 1);
}

}
