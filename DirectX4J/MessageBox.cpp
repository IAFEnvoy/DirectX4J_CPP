#include "pch.h"

#include <string>
#include <Windows.h>
#include "iafenvoy_dxfw4j_utils_MessageBox.h"
#include "jni_helper_define.h"

JNIEXPORT jint JNICALL Java_iafenvoy_dxfw4j_utils_MessageBox_show(JNIEnv* env, jclass, jstring text, jstring title, jlong ctx) {
	LPCWSTR caption = jstring2LPCWSTR(env, title);
	LPCWSTR message = jstring2LPCWSTR(env, text);
	return MessageBoxW(NULL, message, caption, ctx);
}