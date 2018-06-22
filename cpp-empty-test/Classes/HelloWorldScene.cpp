/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "mine.h"
#include <string>
USING_NS_CC;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
Scene* HelloWorld::scene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	srand(unsigned int(time(0)));
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto m1 = Hero::create(Vec2(100, 100), "1.png", "zd.png");
	int x = 0, y = 656;
	for (x = 0; x <= 640; x += 16) {
		auto temp = Sprite::create("bai.png");
		temp->setPosition(Vec2(x, y));
		addChild(temp);
	}
	for (y = 656; y >= 0; y -= 16) {
		auto temp = Sprite::create("bai.png");
		temp->setPosition(Vec2(x, y));
		addChild(temp);
	}

	this->addChild(m1, 1, 110);
	object.push_back(m1);
	this->scheduleUpdate();
	schedule(schedule_selector(HelloWorld::updateCustom), 0.2f, kRepeatForever, 0.0f);
	schedule(schedule_selector(HelloWorld::update3), 1.0f, kRepeatForever, 1.0f);
	schedule(schedule_selector(HelloWorld::update2), 15.0f, kRepeatForever, 5.0f);
	schedule(schedule_selector(HelloWorld::update1), 20.0f, 10, 30.0f);
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	for (int i = 0; i < 10; i++)
	{
		auto temp = Sprite::create("zhi.png");

		while (1)
		{
			int x = rand() % 620 + 16;
			int y = rand() % 620 + 16;
			temp->setPosition(Vec2(x, y));
			if (!isImpact(temp, Vec2(0.1, 0.1)))
			{
				break;
			}
		}
		object.push_back(temp);
		addChild(temp);
	}


	strings = Dictionary::createWithContentsOfFile("a.xml");
	strings->retain();
	auto label1 = Label::create("", "Arial", 24);
	label1->setPosition(100, 740);
	addChild(label1,1,111);
	auto label2 = Label::create("", "Arial", 24);
	label2->setPosition(110, 710);
	addChild(label2, 1, 112);
	auto label3 = Label::create("", "Arial", 24);
	label3->setPosition(125, 680);
	addChild(label3, 1, 113);
	auto label4 = Label::create("", "Arial", 24);
	label4->setPosition(720, 650);
	addChild(label4, 1, 114);
	auto label5 = Label::create("", "Arial", 24);
	label5->setPosition(730, 620);
	addChild(label5, 1, 115);
	auto label6 = Label::create("", "Arial", 24);
	label6->setPosition(720, 590);
	addChild(label6, 1, 116);
	auto label7 = Label::create("", "Arial", 24);
	label7->setPosition(720, 560);
	addChild(label7, 1, 117);
	auto label8 = Label::create("", "Arial", 24);
	label8->setPosition(740, 530);
	addChild(label8, 1, 118);
	return true;
}

bool HelloWorld::isKeyPressed(EventKeyboard::KeyCode keyCode) {
	if (keys[keyCode]) {
		return true;
	}
	else {
		return false;
	}
}

void HelloWorld::updateCustom(float delta) {
	//Node::update(delta);
	auto label = static_cast<Hero*>(getChildByTag(110));
	auto J = EventKeyboard::KeyCode::KEY_J;
	if (isKeyPressed(J)) {
		attack(label);
	}
}

void HelloWorld::update1(float delta) {
	//Node::update(delta);
	for (int i = 0; i < 5; i++)
	{
		auto temp = Sprite::create("zhi.png");
		while (1)
		{
			int x = rand() % 620 + 16;
			int y = rand() % 620 + 16;
			temp->setPosition(Vec2(x, y));
			if (!isImpact(temp, Vec2(0.1, 0.1)))
			{
				break;
			}; 
			if (!isImpact2(temp, Vec2(0.1, 0.1)))
			{
				break;
			};
		}
		object.push_back(temp);
		addChild(temp);
	}
}

void HelloWorld::update2(float delta) {
	//Node::update(delta);
	for (int i = 0; i < 5; i++)
	{
		auto temp = Sprite::create("lv.png");
		while (1)
		{
			int x = rand() % 620 + 16;
			int y = rand() % 620 + 16;
			temp->setPosition(Vec2(x, y));
			if (!isImpact(temp, Vec2(0.1, 0.1)))
			{
				break;
			}
		}
		supply.push_back(temp);
		addChild(temp);
	}
}

void HelloWorld::update3(float delta) 
{
	auto label = static_cast<Label*>(getChildByTag(111));
	auto label2 = static_cast<Label*>(getChildByTag(112));
	auto label3 = static_cast<Label*>(getChildByTag(113));
	auto label4 = static_cast<Label*>(getChildByTag(114));
	auto label5 = static_cast<Label*>(getChildByTag(115));
	auto label6 = static_cast<Label*>(getChildByTag(116));
	auto label7 = static_cast<Label*>(getChildByTag(117));
	auto label8 = static_cast<Label*>(getChildByTag(118));
	auto hero = static_cast<Hero*>(getChildByTag(110));
	static int time;
	time++;
	char* str = new char[100];
	char* str3 = new char[10];

	auto str1 = ((String*)strings->objectForKey("yinxiong"));
	strcpy(str, str1->getCString());
	label4->setString(str);

	str1 = ((String*)strings->objectForKey("hp"));
	sprintf(str3, "%.0f", hero->getHP());
	strcpy(str, str1->getCString());
	strcpy(str + strlen(str), str3);
	label5->setString(str);

	str1 = ((String*)strings->objectForKey("attack"));
	sprintf(str3, "%.0f", hero->getAttack());
	strcpy(str, str1->getCString());
	strcpy(str + strlen(str), str3);
	label6->setString(str);

	str1 = ((String*)strings->objectForKey("speed"));
	sprintf(str3, "%.0f", hero->getSpeed());
	strcpy(str, str1->getCString());
	strcpy(str + strlen(str), str3);
	label7->setString(str);

	 str1 = ((String*)strings->objectForKey("zdnumber"));
	sprintf(str3, "%d", hero->getZdnember());
	strcpy(str, str1->getCString());
	strcpy(str + strlen(str), str3);
	label8->setString(str);

	 str1 = ((String*)strings->objectForKey("time"));
	sprintf(str3, "%d", time);
	auto str2 = ((String*)strings->objectForKey("s"));
	strcpy(str, str1->getCString());
	strcpy(str + strlen(str), str3);
	strcpy(str + strlen(str), str2->getCString());
	label->setString(str);
	auto time1 = (time - 5) % 15;
	if (time < 5)
	{
		auto str1 = ((String*)strings->objectForKey("supply"));
		sprintf(str3, "%d", 5 - time);
		strcpy(str, str1->getCString());
		strcpy(str + strlen(str), str3);
		strcpy(str + strlen(str), str2->getCString());
		label2->setString(str);
	}
	else if (time1 >= 10) {
		auto str1 = ((String*)strings->objectForKey("supply"));
		sprintf(str3, "%d", 15-time1);
		strcpy(str, str1->getCString());
		strcpy(str + strlen(str), str3);
		strcpy(str + strlen(str), str2->getCString());
		label2->setString(str);
	}
	else
	{
		auto str1 = ((String*)strings->objectForKey("supplyarrival"));
		strcpy(str, str1->getCString());
		label2->setString(str);
	}
	auto time2 = (time - 30) % 15;
	if (time < 30)
	{
		auto str1 = ((String*)strings->objectForKey("zhangai"));
		sprintf(str3, "%d", 30 - time);
		strcpy(str, str1->getCString());
		strcpy(str + strlen(str), str3);
		strcpy(str + strlen(str), str2->getCString());
		label3->setString(str);
	}
	else if (time1 >= 20) {
		auto str1 = ((String*)strings->objectForKey("zhangai"));
		sprintf(str3, "%d", 15 - time1);
		strcpy(str, str1->getCString());
		strcpy(str + strlen(str), str3);
		strcpy(str + strlen(str), str2->getCString());
		label3->setString(str);
	}
	else
	{
		auto str1 = ((String*)strings->objectForKey("zhangaiarrival"));
		strcpy(str, str1->getCString());
		label3->setString(str);
	}
}

void HelloWorld::update(float delta)
{
	srand(unsigned int(time(0)));
	auto label = static_cast<Hero*>(getChildByTag(110));
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	if (isKeyPressed(leftArrow)) {
		labelMove(label, Vec2(-HEROSPEED, 0.), 3);
	}
	else if (isKeyPressed(rightArrow)) {
		labelMove(label, Vec2(HEROSPEED, 0.), 1);
	}
	else if (isKeyPressed(upArrow)) {
		labelMove(label, Vec2(0., HEROSPEED), 0);
	}
	else if (isKeyPressed(downArrow)) {
		labelMove(label, Vec2(0., -HEROSPEED), 2);
	}
	for (int i = 0; i < label->Zd.size(); i++)
	{
		if (!label->Zd[i]->getActionByTag(111))
		{
			removeChild(label->Zd[i]);
			label->Zd.erase(label->Zd.begin() + i);
		}
		else if (isImpact(label->Zd[i], Vec2(0, 0), label))
		{
			removeChild(label->Zd[i]);
			label->Zd.erase(label->Zd.begin() + i);
		}
	}
	for (int i = 0; i < supply.size(); i++)
	{
		if (auto temp=isImpact(supply[i], Vec2(0.1, 0.1)))
		{
			int j = random(0,5) ;
			static_cast<Hero*>(temp)->get(Hero::box(j));
			removeChild(supply[i]);
			supply.erase(supply.begin() + i);
		}
	}
}

void HelloWorld::labelMove(Node* label, Vec2 Position, int Direction)
{
	label->setRotation(Direction * 90);
	if (isImpact(label, Position))
	{
		return;
	}
	if (label->getPositionX() + Position.x <= 16) {
		return;
	}
	if (label->getPositionY() + Position.y <= 16) {
		return;
	}
	if (label->getPositionX() + Position.x >= 640) {
		return;
	}
	if (label->getPositionY() + Position.y >= 640) {
		return;
	}
	auto move = MoveBy::create(1 / 60, Position);
	label->runAction(move);
}

void HelloWorld::attack(Hero* hero)
{
	auto Zd = Sprite::create(hero->PathZd);
	Zd->setPosition(hero->getPosition());
	if (hero->getZdnember() <= hero->Zd.size())
	{
		return;
	}
	Vec2 position;
	if (hero->getRotation() == 0)
	{
		position = Vec2(0, ZDRANGE);
	}
	if (hero->getRotation() == 90)
	{
		position = Vec2(ZDRANGE, 0);
	}
	if (hero->getRotation() == 180)
	{
		position = Vec2(0, -ZDRANGE);
	}
	if (hero->getRotation() == 270)
	{
		position = Vec2(-ZDRANGE, 0);
	}
	auto act = MoveBy::create(ZDRANGE / ZDSPEED / 60, position);
	act->setTag(111);
	Zd->runAction(act);
	addChild(Zd);
	hero->Zd.push_back(Zd);
}
bool collision(Rect rect1, Rect rect2)
{
	float lx = max(rect1.getMinX(), rect2.getMinX());
	float ly = max(rect1.getMinY(), rect2.getMinY());

	float rx = min(rect1.getMaxX(), rect2.getMaxX());
	float ry = min(rect1.getMaxY(), rect2.getMaxY());

	if (lx >= rx || ly >= ry)
		return false;
	else
		return true;
}
Node* HelloWorld::isImpact(Node* thisObject, Vec2 move, Node* ignore)
{
	for (auto i : object)
	{
		if (i->getPosition() == thisObject->getPosition() || ignore && ignore == i)
		{
			continue;
		}
		Rect objectA, objectB;
		if (move.x != 0 || move.y != 0) {
			objectA = Rect(thisObject->getPositionX() - 8 + move.x, thisObject->getPositionY() - 8 + move.y, 16 + move.x, 16 + move.y);
			objectB = Rect(i->getPositionX() - 8, i->getPositionY() - 8, 16, 16);
		}
		else {
			objectA = Rect(thisObject->getPositionX(), thisObject->getPositionY(), 1, 1);
			objectB = Rect(i->getPositionX() - 8, i->getPositionY() - 8, 16, 16);
		}
		if (collision(objectA, objectB))
		{
			return i;
		}
	}
	return NULL;
}

Node* HelloWorld::isImpact2(Node* thisObject, Vec2 move, Node* ignore)
{
	for (auto i : supply)
	{
		if (i->getPosition() == thisObject->getPosition() || ignore && ignore == i)
		{
			continue;
		}
		Rect objectA, objectB;
		if (move.x != 0 || move.y != 0) {
			objectA = Rect(thisObject->getPositionX() - 8 + move.x, thisObject->getPositionY() - 8 + move.y, 16 + move.x, 16 + move.y);
			objectB = Rect(i->getPositionX() - 8, i->getPositionY() - 8, 16, 16);
		}
		else {
			objectA = Rect(thisObject->getPositionX(), thisObject->getPositionY(), 1, 1);
			objectB = Rect(i->getPositionX() - 8, i->getPositionY() - 8, 16, 16);
		}
		if (collision(objectA, objectB))
		{
			return i;
		}
	}
	return NULL;
}