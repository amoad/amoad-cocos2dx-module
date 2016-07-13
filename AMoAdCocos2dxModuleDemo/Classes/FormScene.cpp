#include "MainScene.h"
#include "DisplayScene.h"
#include "InterstitialScene.h"
#include "NativeHtmlScene.h"
#include "FormScene.h"
#include "Bundle.h"
#include <iostream>
#include <string>
#include <regex>

USING_NS_CC;
static Label *errorLabel;
static EditBox *form;
Scene* FormScene::createScene()
{
    auto scene = Scene::create();
    auto layer = FormScene::create();
    scene->addChild(layer);
    return scene;
}

bool FormScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    int width = visibleSize.width;
    int height = visibleSize.height;
    int left = origin.x;
    int top = origin.y + height;
    int bottom = origin.y;
    int centerX = left + width / 2;

    //bg
    auto bg = LayerColor::create(Color4B(49, 77, 120, 255), width, height);
    bg->setPosition(Vec2(left, bottom));
    this->addChild(bg, 0);

    //title
    auto label = Label::createWithSystemFont("管理画面から発行されたsidを入力してください", "Arial", 7);
    label->setPosition(Vec2(centerX, top - label->getContentSize().height - 20));
    this->addChild(label, 1);

    //errorMsg
    errorLabel = Label::createWithSystemFont("", "Arial", 7);
    errorLabel->setPosition(Vec2(left + width / 2, top - label->getContentSize().height - 40));
    errorLabel->setColor(Color3B::RED);
    this->addChild(errorLabel);

    //form
    form = EditBox::create(Size(width, 15), "");
    form->setPosition(Vec2(left, top - label->getContentSize().height - 60));
    form->setAnchorPoint(Vec2(0, 0));
    form->setFont("arial.ttf", 7);
    form->setFontColor(Color4B::WHITE);
    form->setPlaceholderFontColor(Color4B::WHITE);
    form->setPlaceHolder("Enter sid...");
    form->setInputMode(EditBox::InputMode::SINGLE_LINE);
    form->setReturnType(EditBox::KeyboardReturnType::DONE);
    form->setDelegate(this);
    form->touchDownAction(NULL, Widget::TouchEventType::ENDED);
    this->addChild(form);

    //prev
    auto prevLabel = Label::createWithSystemFont("Prev", "Arial", 9);
    auto prevMenu = MenuItemLabel::create(prevLabel, [this](Ref *sender)
    {
        this->exit(this);
    });
    prevMenu->setPosition(Vec2(left + width / 7, top - label->getContentSize().height - 80));
    
    //clear
    auto clearLabel = Label::createWithSystemFont("Clear", "Arial", 9);
    auto clearMenu = MenuItemLabel::create(clearLabel, [this](Ref *sender)
    {
        this->clearField();
    });
    clearMenu->setPosition(Vec2(left + width / 5  + width / 4, top - label->getContentSize().height - 80));

    //next
    auto nextLabel = Label::createWithSystemFont("Next", "Arial", 9);
    auto nextMenu = MenuItemLabel::create(nextLabel, [this](Ref *sender)
    {
        this->next();
    });
    nextMenu->setPosition(Vec2(left + width / 2 + width / 4, top - label->getContentSize().height - 80));

    Menu* adMenu = Menu::create(clearMenu, prevMenu, nextMenu, NULL);
    adMenu->setPosition(Point::ZERO);
    this->addChild(adMenu);

    return true;
}
void FormScene::clearField()
{
    form->setText("");
    this->setErrorMsg("");
}
void FormScene::setErrorMsg(const char *msg)
{
    errorLabel->setString(msg);
}

void FormScene::editBoxEditingDidBegin(EditBox* editBox)
{
}

void FormScene::editBoxEditingDidEnd(EditBox* editBox)
{
    Bundle::getInstance()->sid = editBox->getText();
}

void FormScene::editBoxTextChanged(EditBox* editBox, const std::string& text)
{
}

void FormScene::editBoxReturn(EditBox* editBox)
{
}

void FormScene::next()
{
    auto sid = Bundle::getInstance()->sid;
    if (std::regex_match(sid, std::regex("[a-f0-9]{64}")))
    {
        setErrorMsg("");
        Bundle::getInstance()->sid = sid;
    } else
    {
        setErrorMsg("sid不正です");
        return;
    }

    auto adtype = Bundle::getInstance()->ad_type;
    if (adtype.compare("display") == 0)
    {
        Director::getInstance()->replaceScene(DisplayScene::createScene());
    } else if (adtype.compare("interstitial") == 0)
    {
        Director::getInstance()->replaceScene(InterstitialScene::createScene());
    } else if (adtype.compare("nativehtml") == 0)
    {
        Director::getInstance()->replaceScene(NativeHtmlScene::createScene());
    }
}
void FormScene::exit(Ref* pSender)
{
    Director::getInstance()->replaceScene(MainScene::createScene());
}
