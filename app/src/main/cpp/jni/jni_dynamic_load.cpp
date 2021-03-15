//
// Created by Simon on 3/15/21.
//


#include <jni.h>
#include <jvm.h>
#include <base.h>

#define JAVA_CLASS "com/example/ndkdemo/load/JNIDynamicLoad"

jstring getMessage(JNIEnv *env, jobject jobj){
    return env->NewStringUTF("this is msg by dynamic load");
}

jint plus(JNIEnv *env, jobject jobj, int x, int y) {
    return x + y;
}

int registerNativeMethods(JNIEnv *env, const char* name,
                          const JNINativeMethod* methods,
                          jint nMethods) {
    jclass jcls;
    jcls = env->FindClass(name);
    if (jcls == nullptr) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(jcls, methods, nMethods) <0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static JNINativeMethod gMethods[] {
        {"getNativeString", "()Ljava/lang/String;", (void *)getMessage},
        {"sum","(II)I",(void *)plus}
};

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *unused) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK){
        return JNI_FALSE;
    }
//    LOGI("JNI OnLoad call");
    registerNativeMethods(env, JAVA_CLASS, gMethods, 2);
    return JNI_VERSION_1_6;
}