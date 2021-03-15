#include <jni.h>
#include <string>

//#include "people/People.h"
#include <people.h>
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from Simon";
    People people;

    return env->NewStringUTF(people.getString().c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_getstring(JNIEnv *env, jobject thiz) {
    // TODO: implement getstring()
}