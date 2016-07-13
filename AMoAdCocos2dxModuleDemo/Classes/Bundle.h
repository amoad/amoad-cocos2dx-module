#ifndef __BUNDLE_SCENE_H__
#define __BUNDLE_SCENE_H__

#include "cocos2d.h"

class Bundle
{
private:
    Bundle();
    static Bundle* instance;
public:
    static Bundle* getInstance();
    std::string sid;
    std::string ad_type;
};

#endif
