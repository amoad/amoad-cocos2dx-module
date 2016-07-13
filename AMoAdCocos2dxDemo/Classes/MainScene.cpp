#include "MainScene.h"
#include "DisplayScene.h"
#include "InterstitialScene.h"
#include "NativeHtmlScene.h"
#include "Bundle.h"
#include "FormScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
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

    auto bg = LayerColor::create(Color4B(49, 77, 120, 255), width, height);
    bg->setPosition(Vec2(left, bottom));
    this->addChild(bg, 0);

    //title
    auto label = Label::createWithSystemFont("AMoAd Cocos2dx Module Demo", "Arial", 11);
    label->setPosition(Vec2(centerX, top - label->getContentSize().height));
    this->addChild(label, 1);

    //Display AD
    auto displayLabel = Label::createWithSystemFont("Display", "Arial", 9);
    auto displayMenu = MenuItemLabel::create(displayLabel, [this](Ref *sender)
    {
        Bundle::getInstance()->ad_type = "display";
        Director::getInstance()->replaceScene(FormScene::createScene());
    });
    displayMenu->setPosition(Vec2(centerX, bottom + 60));

    //Interstitial AD
    auto interstitialLabel = Label::createWithSystemFont("Inerstitial", "Arial", 9);
    auto interstitialMenu = MenuItemLabel::create(interstitialLabel, [this](Ref *sender)
    {
        Bundle::getInstance()->ad_type = "interstitial";
        Director::getInstance()->replaceScene(FormScene::createScene());
    });
    interstitialMenu->setPosition(Vec2(centerX, bottom + 40));

    //NativeHtml AD
    auto nativeHtmlLabel = Label::createWithSystemFont("NativeHtml", "Arial", 9);
    auto nativeHtmlMenu = MenuItemLabel::create(nativeHtmlLabel, [this](Ref *sender)
    {
        Bundle::getInstance()->ad_type = "nativehtml";
        Director::getInstance()->replaceScene(FormScene::createScene());
    });
    nativeHtmlMenu->setPosition(Vec2(centerX, bottom + 20));

    Menu* adMenu = Menu::create(displayMenu, interstitialMenu, nativeHtmlMenu, NULL);
    adMenu->setPosition(Point::ZERO);
    this->addChild(adMenu);

    return true;
}

void MainScene::exit(Ref* pSender)
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
