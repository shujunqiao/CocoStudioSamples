
#include "cocos-ext.h"
#include "UIScene.h"
#include "UISceneManager.h"

UIScene::UIScene()
: m_pSceneTitle(NULL)
, m_pUiLayer(NULL)
{
    
}

UIScene::~UIScene()
{
	
}

bool UIScene::init()
{
    if (CCLayer::init())
    {
        m_pUiLayer = UILayer::create();
        m_pUiLayer->scheduleUpdate();
        addChild(m_pUiLayer);
        
        m_pWidget = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/UITest/UITest.json"));
        m_pUiLayer->addWidget(m_pWidget);
        
        m_pSceneTitle = dynamic_cast<UILabel*>(m_pUiLayer->getWidgetByName("UItest"));
        
        UILabel *back_label = dynamic_cast<UILabel*>(m_pUiLayer->getWidgetByName("back"));
        back_label->setVisible(false);
//        back_label->addReleaseEvent(this, coco_releaseselector(UIScene::toExtensionsMainLayer));
        
        UIButton *left_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("left_Button"));
        left_button->addReleaseEvent(this, coco_releaseselector(UIScene::previousCallback));
        
        UIButton *middle_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("middle_Button"));
        middle_button->addReleaseEvent(this, coco_releaseselector(UIScene::restartCallback));
        
        UIButton *right_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("right_Button"));
        right_button->addReleaseEvent(this, coco_releaseselector(UIScene::nextCallback));
        
        // exit button
        UIButton* exit_button = UIButton::create();
        exit_button->setTouchEnabled(true);
        exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
        exit_button->setPosition(ccp(m_pUiLayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
        exit_button->addReleaseEvent(this, coco_releaseselector(UIScene::menuCloseCallback));
        m_pUiLayer->addWidget(exit_button);
        
        return true;
    }
    return false;
}

void UIScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void UIScene::previousCallback(CCObject* sender)
{
	m_pUiLayer->unscheduleUpdate();
	m_pUiLayer->removeFromParent();
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->previousUIScene());
}

void UIScene::restartCallback(CCObject* sender)
{
	m_pUiLayer->unscheduleUpdate();
	m_pUiLayer->removeFromParent();
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->currentUIScene());
}

void UIScene::nextCallback(CCObject* sender)
{
	m_pUiLayer->unscheduleUpdate();
	m_pUiLayer->removeFromParent();
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->nextUIScene());
}
