#include "NewCome.h"
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
	return true;

}
