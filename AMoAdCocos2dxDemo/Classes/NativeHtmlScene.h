#ifndef __NATIVEHTML_SCENE_H__
#define __NATIVEHTML_SCENE_H__

#include "cocos2d.h"

class NativeHtmlScene : public cocos2d::Layer
{
public:
    virtual void show();
    virtual void hide();
    virtual void reload();
    static cocos2d::Scene* createScene();
    virtual bool init();
    void exit(cocos2d::Ref* pSender);
    CREATE_FUNC(NativeHtmlScene);
};

#endif
