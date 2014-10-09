#include "ThreeClearScene.h"

#include "ThreeClearMap.h"

ThreeClearScene::ThreeClearScene()
{

}

ThreeClearScene::~ThreeClearScene()
{

}

bool ThreeClearScene::init()
{
	if(!CCScene::init()){
		return false;
	}

	ThreeClearMap* map = ThreeClearMap::create();
	addChild(map, 0, 1);

	return true;
}