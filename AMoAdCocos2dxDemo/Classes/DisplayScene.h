#ifndef __DISPLAY_SCENE_H__
#define __DISPLAY_SCENE_H__

#include "cocos2d.h"

class DisplayScene : public cocos2d::Layer
{
private:

public:
    virtual void show();
    virtual void hide();
    static cocos2d::Scene* createScene();
    virtual bool init();
    void exit(cocos2d::Ref* pSender);
    CREATE_FUNC(DisplayScene);
};

#endif
