#include <jni.h>
#include <string>
#include "CppStudent.hpp"


CppStudent* jgetInstance(JNIEnv *env, jobject instance) {
    jclass jcls = env->GetObjectClass(instance);
    jfieldID jInstanceFiledID = env->GetFieldID(jcls, "nativeInstance", "Ljava/lang/Object;" );
    jobject jInstance = env->GetObjectField(instance, jInstanceFiledID);
    return (CppStudent*) env->GetDirectBufferAddress(jInstance);
}

extern "C" {

JNIEXPORT jobject JNICALL
Java_brianyeh_multipleinstance_Student_nativeCreateInstance(
        JNIEnv *env,
        jobject instance,
        jstring id_,
        jstring name_)
{
    const char *id = env->GetStringUTFChars(id_, 0);
    const char *name = env->GetStringUTFChars(name_, 0);

    CppStudent *cppStudent = new CppStudent(id, name);

    env->ReleaseStringUTFChars(id_, id);
    env->ReleaseStringUTFChars(name_, name);
    return env->NewDirectByteBuffer(cppStudent, 0);
}

JNIEXPORT jstring JNICALL
Java_brianyeh_multipleinstance_Student_nativeGetName(JNIEnv *env, jobject instance) {
    CppStudent *cppStudent = jgetInstance(env, instance);
    std::string result = cppStudent->getName();
    return env->NewStringUTF(result.c_str());
}

JNIEXPORT jstring JNICALL
Java_brianyeh_multipleinstance_Student_nativeGetID(JNIEnv *env, jobject instance) {
    CppStudent *cppStudent = jgetInstance(env, instance);
    std::string result = cppStudent->getID();
    return env->NewStringUTF(result.c_str());
}

JNIEXPORT void JNICALL
Java_brianyeh_multipleinstance_Student_nativeRelease(JNIEnv *env, jobject instance) {
    CppStudent *cppStudent = jgetInstance(env, instance);
    delete cppStudent;
}

} // extern "C"

