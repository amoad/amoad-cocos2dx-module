#include "MainScene.h"
#include "InterstitialScene.h"
#include "AMoAdCocos2dxModule.h"
#include "Bundle.h"

USING_NS_CC;

Scene* InterstitialScene::createScene()
{
    auto scene = Scene::create();
    auto layer = InterstitialScene::create();
    scene->addChild(layer);
    return scene;
}

bool InterstitialScene::init()
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
    int centerY = bottom + height / 2;

    //bg
    auto bg = LayerColor::create(Color4B(49, 77, 120, 255), width, height);
    bg->setPosition(Vec2(left, bottom));
    this->addChild(bg, 0);

    //title
    auto label = Label::createWithSystemFont("Interstitial AD", "Arial", 14);
    label->setPosition(Vec2(centerX, top - label->getContentSize().height));
    this->addChild(label, 1);

    //show
    auto showLabel = Label::createWithSystemFont("Show", "Arial", 9);
    auto showMenu = MenuItemLabel::create(showLabel, [this](Ref *sender)
    {
        this->show();
    });
    showMenu->setPosition(Vec2(centerX, centerY));

    //exit
    auto exitLabel = Label::createWithSystemFont("Exit", "Arial", 9);
    auto exitMenu = MenuItemLabel::create(exitLabel, [this](Ref *sender)
    {
        this->exit(this);
    });
    exitMenu->setPosition(Vec2(centerX, centerY - 20));

    //ad
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::registerInterstitialAd(sid, 10 * 1000);
    AMoAdCocos2dxModule::loadInterstitialAd(sid);

    Menu* adMenu = Menu::create(showMenu, exitMenu, NULL);
    adMenu->setPosition(Point::ZERO);
    this->addChild(adMenu);

    return true;
}

void InterstitialScene::show()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::showInterstitialAd(sid);
}
void InterstitialScene::exit(Ref* pSender)
{
    auto director = Director::getInstance();
    auto scene = MainScene::createScene();
    director->replaceScene(scene);
}
