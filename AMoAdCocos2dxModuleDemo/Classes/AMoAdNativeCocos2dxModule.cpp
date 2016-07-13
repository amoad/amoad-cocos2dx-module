//
//  AMoAdNativeCocos2dxModule.cpp
//
//  Created by AMoAd on 2016/02/01.
//
#include "AMoAdNativeCocos2dxModule.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

#define AMOAD_COCOS2DX_MODULE_CLASS_NAME "com/amoad/cocos2dx/AMoAdNativeCocos2dxModule"

void AMoAdNativeCocos2dxModule::load(const char* cSid, const char* cTag, int x, int y, int width, int height)
{
  AMoAdNativeCocos2dxModule::load(cSid, cTag, x, y, width, height, "{}");
}

void AMoAdNativeCocos2dxModule::load(const char* cSid, const char* cTag, int x, int y, int width, int height, const char* cOption)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "load", "(Ljava/lang/String;Ljava/lang/String;IIIILjava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jstring option = jniMethodInfo.env->NewStringUTF(cOption);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag, x, y, width, height, option);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(option);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::remove(const char* cSid, const char* cTag)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "remove", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::reload(const char* cSid, const char* cTag)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "reload", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::show(const char* cSid, const char* cTag)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "show", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::hide(const char* cSid, const char* cTag)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "hide", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::startRotation(const char* cSid, const char* cTag, int seconds)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "startRotation", "(Ljava/lang/String;Ljava/lang/String;I)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag, seconds);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::stopRotation(const char* cSid, const char* cTag)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "stopRotation", "(Ljava/lang/String;Ljava/lang/String;)V")) {
    jstring sid = jniMethodInfo.env->NewStringUTF(cSid);
    jstring tag = jniMethodInfo.env->NewStringUTF(cTag);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, sid, tag);
    jniMethodInfo.env->DeleteLocalRef(sid);
    jniMethodInfo.env->DeleteLocalRef(tag);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

void AMoAdNativeCocos2dxModule::setHtmlUrlString(const char* cHtmlUrlString)
{
  cocos2d::JniMethodInfo jniMethodInfo;
  if (cocos2d::JniHelper::getStaticMethodInfo(jniMethodInfo, AMOAD_COCOS2DX_MODULE_CLASS_NAME, "setHtmlUrlString", "(Ljava/lang/String;)V")) {
    jstring htmlUrlString = jniMethodInfo.env->NewStringUTF(cHtmlUrlString);
    jniMethodInfo.env->CallStaticVoidMethod(jniMethodInfo.classID, jniMethodInfo.methodID, htmlUrlString);
    jniMethodInfo.env->DeleteLocalRef(htmlUrlString);
    jniMethodInfo.env->DeleteLocalRef(jniMethodInfo.classID);
  }
}

