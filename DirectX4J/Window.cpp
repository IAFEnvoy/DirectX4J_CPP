#include "pch.h"

#include <string>
#include <unordered_map>
#include <Windows.h>
#include "iafenvoy_dxfw4j_utils_Window.h"
#include "jni_helper_define.h"
using namespace std;

extern HMODULE dllHModule;

class Window {
private:
	string id;
	WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
public:
	Window(string id) {
		this->id = id;
		wc.style = CS_VREDRAW | CS_HREDRAW;
		//wc.lpfnWndProc = (WNDPROC)WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = (HINSTANCE)dllHModule;
	}
};

unordered_map<string, Window*> instance;

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_setIcon(JNIEnv*, jobject) {

}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_setCursor(JNIEnv*, jobject) {

}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_setBackgroundColor(JNIEnv*, jobject, jint, jint, jint) {

}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_setTitle(JNIEnv*, jobject, jstring) {

}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_create(JNIEnv*, jobject) {

}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_show(JNIEnv*, jobject) {

}

JNIEXPORT jobjectArray JNICALL Java_iafenvoy_dxfw4j_utils_Window_getInstances(JNIEnv* env, jclass) {
	jobjectArray ret = env->NewObjectArray(instance.size(), (env)->FindClass("Ljava/lang/String;"), NULL);
	int index = 0;
	for (auto it = instance.begin(); it != instance.end(); ++it)
		env->SetObjectArrayElement(ret, index++, str2jstring(env, it->first.c_str()));
	return ret;
}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_createInstance(JNIEnv* env, jclass, jstring id) {
	string s = jstring2str(env, id);
	instance.emplace(s, new Window(s));
}

JNIEXPORT void JNICALL Java_iafenvoy_dxfw4j_utils_Window_deleteInstance(JNIEnv* env, jclass, jstring id) {
	instance.erase(jstring2str(env, id));
}