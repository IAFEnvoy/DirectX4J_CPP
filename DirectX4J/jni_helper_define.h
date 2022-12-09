#pragma once
#include <jni.h>
#include <string>
#include <windows.h>

jstring str2jstring(JNIEnv* env, const char* pat);
std::string jstring2str(JNIEnv* env, jstring jstr);
jstring char2jstring(JNIEnv* env, const char* pat);
char* jstring2Char(JNIEnv* env, jstring jstr);
LPCWSTR char2LPCWSTR(char* szStr);
LPCWSTR jstring2LPCWSTR(JNIEnv* env, jstring jstr);