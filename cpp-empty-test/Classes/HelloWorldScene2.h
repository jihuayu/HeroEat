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

#ifndef __HELLOWORLD2_SCENE_H__
#define __HELLOWORLD2_SCENE_H__

#include "cocos2d.h"
#include "mine.h"
class Game2 : public cocos2d::Scene
{
public:
	virtual bool init() override;

	void update1(float delta);

	void update2(float delta);

	void update3(float delta);

	void updateCustom(float delta);

	void update(float delta);

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	void labelMove(cocos2d::Node* label, cocos2d::Vec2 Position, int Direction);

	void attack(cocos2d::Hero* hero);

	cocos2d::Node*  isImpact(cocos2d::Node*, Vec2 move, Node* ignore = NULL);

	cocos2d::Node* isImpact2(cocos2d::Node* thisObject, Vec2 move, Node* ignore = NULL);

	static cocos2d::Scene* scene();

	// a selector callback
	//void menuCloseCallback(Ref* sender);

	// implement the "static create()" method manually
	CREATE_FUNC(Game2);
	CCDictionary *strings; //词典类，加载xml文件用

	const char *label_strings;//const char *类型的数据
private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	std::vector<cocos2d::Node*> object;
	std::vector<cocos2d::Node*> supply;
};

#endif // __HELLOWORLD_SCENE_H__
