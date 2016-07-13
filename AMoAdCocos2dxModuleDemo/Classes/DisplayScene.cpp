#include "MainScene.h"
#include "DisplayScene.h"
#include "AMoAdCocos2dxModule.h"
#include "Bundle.h"

USING_NS_CC;

Scene* DisplayScene::createScene()
{
    auto scene = Scene::create();
    auto layer = DisplayScene::create();
    scene->addChild(layer);
    return scene;
}

bool DisplayScene::init()
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
    auto label = Label::createWithSystemFont("Display AD", "Arial", 14);
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

    //exit
    auto exitLabel = Label::createWithSystemFont("Exit", "Arial", 9);
    auto exitMenu = MenuItemLabel::create(exitLabel, [this](Ref *sender)
    {
        this->exit(this);
    });
    exitMenu->setPosition(Vec2(centerX, top - label->getContentSize().height - 60));

    //ad
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::registerInlineAd(sid,
                                          AMoAdCocos2dxModule::AdSize::B320x50,
                                          AMoAdCocos2dxModule::HorizontalAlign::Center,
                                          AMoAdCocos2dxModule::VerticalAlign::Bottom,
                                          AMoAdCocos2dxModule::AdjustMode::Responsive,
                                          0,
                                          0,
                                          5000);

    Menu* adMenu = Menu::create(showMenu, hideMenu, exitMenu, NULL);
    adMenu->setPosition(Point::ZERO);
    this->addChild(adMenu);

    return true;
}

void DisplayScene::show()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::show(sid);
}
void DisplayScene::hide()
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::hide(sid);
}
void DisplayScene::exit(Ref* pSender)
{
    auto sid = Bundle::getInstance()->sid.c_str();
    AMoAdCocos2dxModule::dispose(sid);

    auto director = Director::getInstance();
    auto scene = MainScene::createScene();
    director->replaceScene(scene);
}
