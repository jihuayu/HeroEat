#pragma once
#include "cocos2d.h"
#include <string>
#include <vector>
USING_NS_CC;
namespace cocos2d {
	class Hero : public Node
	{
	public:
		enum box
		{
			HPWater,
			AttackWater,
			SpeedWater,
			ZdNemberWater,
			BadWater,
		};
		std::vector<box> state;
		float HP;
		float Attack;
		float Speed;
		int ZdNember;
		std::string PathZd;
		std::vector<Node*>Zd;
		Hero(){};
		static Hero* create(Vec2 _Position, std::string _Path, std::string _PathZd)
		{
			
			auto temp = new Hero();
			auto SprHero = Sprite::create(_Path);
			temp->PathZd = _PathZd;
			temp->addChild(SprHero, 10);
			temp->setPosition(_Position);
			temp->HP = 100.0f;
			temp->Attack = 5.0f;
			temp->Speed = 2.0f;
			temp->ZdNember = 1;
			return temp;
		}
		float getHP()const
		{
			return HP;
		}
		float getSpeed()const
		{
			return Speed;
		
		}
		float getAttack()const
		{
			return Attack;
		}
		int getZdnember()const
		{
			return ZdNember;
		}
		void beHit(float _HP)
		{
			HP -= _HP;
		}
		void get(box thisBox)
		{
			if (thisBox == HPWater)
			{
				HP += 25;
			}
			else if (thisBox == AttackWater)
			{
				Attack *= 1.2;
				state.push_back(AttackWater);
			}
			else if (thisBox == SpeedWater)
			{
				Speed *= 1.2;
				state.push_back(SpeedWater);
			}
			else if (thisBox == ZdNemberWater)
			{
				ZdNember++;
				state.push_back(ZdNemberWater);
			}
			else if (thisBox == BadWater)
			{
				beHit(random(10,30));
			}
		}
	};
}