#pragma once
#include <string>
#include <jni.h>
#include <string>
jstring str2jstring(JNIEnv* env, const char* pat) {
	//����java String�� strClass
	jclass strClass = (env)->FindClass("Ljava/lang/String;");
	//��ȡString(byte[],String)�Ĺ�����,���ڽ�����byte[]����ת��Ϊһ����String
	jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	//����byte����
	jbyteArray bytes = (env)->NewByteArray(strlen(pat));
	//��char* ת��Ϊbyte����
	(env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	// ����String, ������������,����byte����ת����Stringʱ�Ĳ���
	jstring encoding = (env)->NewStringUTF("GB2312");
	//��byte����ת��Ϊjava String,�����
	return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);
}

std::string jstring2str(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("GB2312");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*)malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	std::string stemp(rtn);
	free(rtn);
	return stemp;
}
jstring char2jstring(JNIEnv* env, const char* pat) {
	//����java String�� strClass
	jclass strClass = (env)->FindClass("Ljava/lang/String;");
	//��ȡString(byte[],String)�Ĺ�����,���ڽ�����byte[]����ת��Ϊһ����String
	jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	//����byte����
	jbyteArray bytes = (env)->NewByteArray(strlen(pat));
	//��char* ת��Ϊbyte����
	(env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	// ����String, ������������,����byte����ת����Stringʱ�Ĳ���
	jstring encoding = (env)->NewStringUTF("GB2312");
	//��byte����ת��Ϊjava String,�����
	return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);
}

char* jstring2Char(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("GB2312");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*)malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;
}
LPCWSTR char2LPCWSTR(const char* szStr) {
	size_t len = strlen(szStr);
	WCHAR* wszClassName = (WCHAR*)malloc(sizeof(WCHAR) * len);
	memset(wszClassName, 0, sizeof(WCHAR) * len);
	MultiByteToWideChar(CP_ACP, 0, szStr, len + 1, wszClassName, sizeof(WCHAR) * (len + 1));
	return (LPCWSTR)wszClassName;
}
LPCWSTR jstring2LPCWSTR(JNIEnv* env, jstring jstr) {
	char* c = jstring2Char(env, jstr);
	std::string s = c;
	printf(s.c_str());
	printf("\r\n");
	return char2LPCWSTR(c);
}