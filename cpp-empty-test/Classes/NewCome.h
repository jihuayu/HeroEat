#pragma once
#include "cocos2d.h"
#include "mine.h"
class NewCome : public cocos2d::Scene
{
public:
	virtual bool init() override;

	static cocos2d::Scene* scene();

	void update1(float delta);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	bool isKeyPressed(EventKeyboard::KeyCode keyCode);

	int nowtag;

	CREATE_FUNC(NewCome);
	CCDictionary *strings; //词典类，加载xml文件用
};

