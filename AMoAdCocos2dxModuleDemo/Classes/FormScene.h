#ifndef __FORM_SCENE_H__
#define __FORM_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d::ui;

class FormScene : public cocos2d::Layer, public EditBoxDelegate
{
public:
    virtual void next();
    virtual void clearField();
    virtual void setErrorMsg(const char *msg);
    static cocos2d::Scene* createScene();
    virtual bool init();
    void exit(cocos2d::Ref* pSender);
    CREATE_FUNC(FormScene);

    //文字を入力し始めると実行される
    virtual void editBoxEditingDidBegin(EditBox* editBox);
    //文字の入力が終わると実行される
    virtual void editBoxEditingDidEnd(EditBox* editBox);
    //文字の入力中に実行される
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
    //returnを押したら実行される
    virtual void editBoxReturn(EditBox* editBox);
};

#endif
