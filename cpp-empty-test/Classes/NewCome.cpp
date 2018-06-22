#include "NewCome.h"
#include "HelloWorldScene.h"
#include "HelloWorldScene2.h"
#include "AppMacros.h"
#include "mine.h"
#include <string>
USING_NS_CC;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
Scene* NewCome::scene()
{
	return NewCome::create();
}
bool NewCome::init()
{
	if (!Scene::init())
	{
		return false;
	}
	strings = Dictionary::createWithContentsOfFile("b.xml");
	auto label0 = Label::create("111", "Arial", 72);
	label0->setColor(Color3B(0, 0, 0XFF));
	label0->setString((((String*)strings->objectForKey("title"))->getCString()));
	label0->setPosition(500, 650);
	auto label1 = Label::create("111", "Arial", 48);
	label1->setColor(Color3B(0XFF, 0, 0));
	label1->setString((((String*)strings->objectForKey("danren"))->getCString()));
	label1->setPosition(500, 500);
	auto label2 = Label::create("111", "Arial", 48);
	label2->setColor(Color3B(0, 0XFF, 0));
	label2->setString((((String*)strings->objectForKey("suangren"))->getCString()));
	label2->setPosition(500, 400);
	auto label3 = Label::create("111", "Arial", 48);
	label3->setColor(Color3B(0, 0XFF, 0));
	label3->setString((((String*)strings->objectForKey("help"))->getCString()));
	label3->setPosition(500, 300);
	auto label4 = Label::create("111", "Arial", 48);
	label4->setColor(Color3B(0, 0XFF, 0));
	label4->setString((((String*)strings->objectForKey("exit"))->getCString()));
	label4->setPosition(500, 200);
	nowtag = 111;
	addChild(label1, 1, 111);
	addChild(label2, 1, 112);
	addChild(label3, 1, 113);
	addChild(label4, 1, 114);
	addChild(label0, 1, 110);

	//this->scheduleUpdate();
	schedule(schedule_selector(NewCome::update1), 0.1f, kRepeatForever, 0.0f);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		log("ttt");
		keys[keyCode] = true;
	};

	//listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
	//	keys[keyCode] = false;
	//};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void NewCome::update1(float delta)
{
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW,
		Enter = EventKeyboard::KeyCode::KEY_ENTER, Esc = EventKeyboard::KeyCode::KEY_ESCAPE;
	if (isKeyPressed(upArrow)) {
		log("up");
		keys[upArrow] = false;
		keys[Enter] = false;
		if (nowtag == 111)
		{
			return;
		}

		auto label1 = static_cast<Label*>(getChildByTag(nowtag));
		auto label2 = static_cast<Label*>(getChildByTag(nowtag - 1));
		label1->setColor(Color3B(0, 0XFF, 0));
		label2->setColor(Color3B(0XFF, 0, 0));
		nowtag--;
	}
	else if (isKeyPressed(downArrow)) {
		log("down");
		keys[downArrow] = false;
		keys[Enter] = false;
		if (nowtag == 114)
		{
			return;
		}

		auto label1 = static_cast<Label*>(getChildByTag(nowtag));
		auto label2 = static_cast<Label*>(getChildByTag(nowtag + 1));
		label1->setColor(Color3B(0, 0XFF, 0));
		label2->setColor(Color3B(0XFF, 0, 0));
		nowtag++;
	}
	else if (isKeyPressed(Enter)) {
		keys[Enter] = false;
		if (nowtag == 111) {
			auto myScene = HelloWorld::create();
			Director::getInstance()->replaceScene(myScene);
		}
		else if (nowtag == 112)
		{
			auto myScene = Game2::create();
			Director::getInstance()->replaceScene(myScene);
		}
		else if (nowtag == 113)
		{
			auto label1 = static_cast<Label*>(getChildByTag(115));
			if (label1)
			{
				return;
			}
			strings = Dictionary::createWithContentsOfFile("b.xml");
			auto label5 = Label::create((((String*)strings->objectForKey("help1")))->getCString(), "Arial", 48);
			label5->setColor(Color3B(0, 0, 0XFF));
			label5->setPosition(500, 450);
			addChild(label5, 1,115);
		}
		else if (nowtag == 114)
		{
			CCDirector::sharedDirector()->end();
			exit(0);
		}
	}
	else if (isKeyPressed(Esc))
	{
		keys[Esc] = false;
		auto label1 = static_cast<Label*>(getChildByTag(115));
		if (label1)
		{
			removeChild(label1);
		}
	}
	return;
}

bool NewCome::isKeyPressed(EventKeyboard::KeyCode keyCode) {
	if (keys[keyCode]) {
		log("1");
		return true;
	}
	else {
		return false;
	}
}