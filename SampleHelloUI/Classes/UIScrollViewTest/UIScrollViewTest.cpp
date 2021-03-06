

#include "UIScrollViewTest.h"

const char* font_UIScrollViewTest =
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
"Marker Felt";
#else
"cocosgui/Marker Felt.ttf";
#endif

// UIScrollViewTest_Vertical

UIScrollViewTest_Vertical::UIScrollViewTest_Vertical()
: m_pDisplayValueLabel(NULL)
{
}

UIScrollViewTest_Vertical::~UIScrollViewTest_Vertical()
{
}

bool UIScrollViewTest_Vertical::init()
{
    if (UIScene::init())
    {
        CCSize widgetSize = m_pWidget->getSize();
        
        // Add a label in which the scrollview alert will be displayed
        m_pDisplayValueLabel = UILabel::create();
        m_pDisplayValueLabel->setText("Move by vertical direction");
        m_pDisplayValueLabel->setFontName(font_UIScrollViewTest);
        m_pDisplayValueLabel->setFontSize(32);
        m_pDisplayValueLabel->setAnchorPoint(ccp(0.5f, -1));
        m_pDisplayValueLabel->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f + m_pDisplayValueLabel->getContentSize().height * 1.5));
        m_pUiLayer->addWidget(m_pDisplayValueLabel);
        
        // Add the alert
        UILabel *alert = UILabel::create();
        alert->setText("ScrollView");
        alert->setFontName(font_UIScrollViewTest);
        alert->setFontSize(30);
        alert->setColor(ccc3(159, 168, 176));
        alert->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getSize().height * 2.925));
        m_pUiLayer->addWidget(alert);
        
        Layout *background = dynamic_cast<Layout*>(m_pUiLayer->getWidgetByName("background_Panel"));
        
        // Create the scrollview by vertical
        UIScrollView* scrollView = UIScrollView::create();
        scrollView->setTouchEnabled(true);
        scrollView->setSize(CCSizeMake(280, 150));        
        CCSize backgroundSize = background->getContentSize();
        scrollView->setPosition(ccp((widgetSize.width - backgroundSize.width) / 2 +
                               (backgroundSize.width - scrollView->getSize().width) / 2,
                               (widgetSize.height - backgroundSize.height) / 2 +
                               (backgroundSize.height - scrollView->getSize().height) / 2));
        m_pUiLayer->addWidget(scrollView);
        
        UIImageView* imageView = UIImageView::create();
        imageView->setTexture("cocosgui/ccicon.png");
        
        float innerWidth = scrollView->getSize().width;
        float innerHeight = scrollView->getSize().height + imageView->getSize().height;
        
        scrollView->setInnerContainerSize(CCSizeMake(innerWidth, innerHeight));                
        
        UIButton* button = UIButton::create();
        button->setTouchEnabled(true);
        button->loadTextures("cocosgui/animationbuttonnormal.png", "cocosgui/animationbuttonpressed.png", "");
        button->setPosition(ccp(innerWidth / 2, scrollView->getInnerContainerSize().height - button->getSize().height / 2));
        scrollView->addChild(button);
        
        UITextButton* textButton = UITextButton::create();
        textButton->setTouchEnabled(true);
        textButton->loadTextures("cocosgui/backtotopnormal.png", "cocosgui/backtotoppressed.png", "");
        textButton->setTitleText("Text Button");
        textButton->setPosition(ccp(innerWidth / 2, button->getBottomInParent() - button->getSize().height));
        scrollView->addChild(textButton);
        
        UIButton* button_scale9 = UIButton::create();
        button_scale9->setTouchEnabled(true);
        button_scale9->setScale9Enabled(true);
        button_scale9->loadTextures("cocosgui/button.png", "cocosgui/buttonHighlighted.png", "");
        button_scale9->setSize(CCSizeMake(100, button_scale9->getContentSize().height));
        button_scale9->setPosition(ccp(innerWidth / 2, textButton->getBottomInParent() - textButton->getSize().height));
        scrollView->addChild(button_scale9);
        
        imageView->setPosition(ccp(innerWidth / 2, imageView->getSize().height / 2));
        scrollView->addChild(imageView);
        
        return true;
    }
    
    return false;
}

// UIScrollViewTest_Horizontal

UIScrollViewTest_Horizontal::UIScrollViewTest_Horizontal()
: m_pDisplayValueLabel(NULL)
{
}

UIScrollViewTest_Horizontal::~UIScrollViewTest_Horizontal()
{
}

bool UIScrollViewTest_Horizontal::init()
{
    if (UIScene::init())
    {
        CCSize widgetSize = m_pWidget->getSize();
        
        // Add a label in which the scrollview alert will be displayed
        m_pDisplayValueLabel = UILabel::create();
        m_pDisplayValueLabel->setText("Move by horizontal direction");
        m_pDisplayValueLabel->setFontName(font_UIScrollViewTest);
        m_pDisplayValueLabel->setFontSize(32);
        m_pDisplayValueLabel->setAnchorPoint(ccp(0.5f, -1));
        m_pDisplayValueLabel->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f + m_pDisplayValueLabel->getContentSize().height * 1.5));
        m_pUiLayer->addWidget(m_pDisplayValueLabel);            
        
        UILabel *alert = UILabel::create();
        alert->setText("ScrollView");
        alert->setFontName(font_UIScrollViewTest);
        alert->setFontSize(30);
        alert->setColor(ccc3(159, 168, 176));
        alert->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getSize().height * 2.925));
        m_pUiLayer->addWidget(alert);
        
        Layout *background = dynamic_cast<Layout*>(m_pUiLayer->getWidgetByName("background_Panel"));
        
        // Create the scrollview by horizontal
        UIScrollView* scrollView = UIScrollView::create();        
        scrollView->setDirection(SCROLLVIEW_DIR_HORIZONTAL);
        scrollView->setTouchEnabled(true);
        scrollView->setSize(CCSizeMake(280, 150));
        scrollView->setInnerContainerSize(scrollView->getSize());
        CCSize backgroundSize = background->getContentSize();
        scrollView->setPosition(ccp((widgetSize.width - backgroundSize.width) / 2 +
                                    (backgroundSize.width - scrollView->getSize().width) / 2,
                                    (widgetSize.height - backgroundSize.height) / 2 +
                                    (backgroundSize.height - scrollView->getSize().height) / 2));
        m_pUiLayer->addWidget(scrollView);
        
        UIImageView* imageView = UIImageView::create();
        imageView->setTexture("cocosgui/ccicon.png");
        
        float innerWidth = scrollView->getSize().width + imageView->getSize().width;
        float innerHeight = scrollView->getSize().height;
        
        scrollView->setInnerContainerSize(CCSizeMake(innerWidth, innerHeight));
        
        UIButton* button = UIButton::create();
        button->setTouchEnabled(true);
        button->loadTextures("cocosgui/animationbuttonnormal.png", "cocosgui/animationbuttonpressed.png", "");
        button->setPosition(ccp(button->getSize().width / 2,
                                scrollView->getInnerContainerSize().height - button->getSize().height / 2));
        scrollView->addChild(button);
        
        UITextButton* textButton = UITextButton::create();
        textButton->setTouchEnabled(true);
        textButton->loadTextures("cocosgui/backtotopnormal.png", "cocosgui/backtotoppressed.png", "");
        textButton->setTitleText("Text Button");
        textButton->setPosition(ccp(button->getRightInParent() + button->getSize().width / 2,
                                    button->getBottomInParent() - button->getSize().height / 2));
        scrollView->addChild(textButton);
        
        UIButton* button_scale9 = UIButton::create();
        button_scale9->setTouchEnabled(true);
        button_scale9->setScale9Enabled(true);
        button_scale9->loadTextures("cocosgui/button.png", "cocosgui/buttonHighlighted.png", "");
        button_scale9->setSize(CCSizeMake(100, button_scale9->getContentSize().height));
        button_scale9->setPosition(ccp(textButton->getRightInParent() + textButton->getSize().width / 2,
                                       textButton->getBottomInParent() - textButton->getSize().height / 2));
        scrollView->addChild(button_scale9);                
                
        imageView->setPosition(ccp(innerWidth - imageView->getSize().width / 2,
                                   button_scale9->getBottomInParent() - button_scale9->getSize().height / 2));
        scrollView->addChild(imageView);                
        
        return true;
    }
    
    return false;
}