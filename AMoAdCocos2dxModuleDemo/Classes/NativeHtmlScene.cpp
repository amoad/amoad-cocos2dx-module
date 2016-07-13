#include "MainScene.h"
#include "NativeHtmlScene.h"
#include "AMoAdNativeCocos2dxModule.h"
#include "Bundle.h"

USING_NS_CC;

Scene* NativeHtmlScene::createScene()
{
    auto scene = Scene::create();
    auto layer = NativeHtmlScene::create();
    scene->addChild(layer);
    return scene;
}

bool NativeHtmlScene::init()
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
    auto label = Label::createWithSystemFont("NativeHtml AD", "Arial", 14);
    label->setPosition(Vec2(centerX, top - label->getContentSize().height));
    this->addChild(label, 1);

    //show
    auto showLabel = Label::createWithSystemFont("Show", "Arial", 9);
    auto showMenu = MenuItemLabel::create(showLabel, [this](Ref *sender)
    {
        this->show();
    });
    showMenu->setPosition(Vec2(centerX, top - label->getContentSize().height - 20));

    //hide
    auto hideLabel = Label::createWithSystemFont("Hide", "Arial", 9);
    auto hideMenu = MenuItemLabel::create(hideLabel, [this](Ref *sender)
    {
        this->hide();
    });
    hideMenu->setPosition(Vec2(centerX, top - label->getContentSize().height - 40));

    //reload
    auto reloadLabel = Label::createWithSystemFont("Reload", "Arial", 9);
    auto reloadMenu = MenuItemLabel::create(reloadLabel, [this](Ref *sender)
    {
        this->reload();
    });
    reloadMenu->setPosition(Vec2(centerX, top - label->getContentSize().height - 60));

    //exit
    auto exitLabel = Label::createWithSystemFont("Exit", "Arial", 9);
    auto exitMenu = MenuItemLabel::create(exitLabel, [this](Ref *sender)
    {
        this->exit(this);
    });
    exitMenu->setPosition(Vec2(centerX, top - label->getContentSize().height - 80));

    //ad
    auto sid = Bundle::getInstance()->sid.c_str();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    AMoAdNativeCocos2dxModule::load(sid, "ad01", 100, 300, 140, 120, "{\"border\": \"dotted 2px #0000ff\"}");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    AMoAdNativeCocos2dxModule::load(sid, "ad01", 100, 300, 140, 120, "{\"border\": \"dotted 2px #0000ff\"}");
#endif

    Menu* adMenu = Menu::create(showMenu, hideMenu, reloadMenu, exitMenu, NULL);
    adMenu->setPosition(Point::ZERO);
    this->addChild(adMenu);

    return true;
}

void NativeHtmlScene::show()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdNativeCocos2dxModule::show(sid, "ad01");
}
void NativeHtmlScene::hide()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdNativeCocos2dxModule::hide(sid, "ad01");
}
void NativeHtmlScene::reload()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdNativeCocos2dxModule::reload(sid, "ad01");
}
void NativeHtmlScene::exit(Ref* pSender)
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdNativeCocos2dxModule::remove(sid, "ad01");

    auto director = Director::getInstance();
    auto scene = MainScene::createScene();
    director->replaceScene(scene);
}
