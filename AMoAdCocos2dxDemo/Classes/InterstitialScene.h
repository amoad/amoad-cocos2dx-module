#ifndef __INTERSTITIAL_SCENE_H__
#define __INTERSTITIAL_SCENE_H__

#include "cocos2d.h"

class InterstitialScene : public cocos2d::Layer
{
public:
    virtual void show();
    static cocos2d::Scene* createScene();
    virtual bool init();
    void exit(cocos2d::Ref* pSender);
    CREATE_FUNC(InterstitialScene);
};

#endif
