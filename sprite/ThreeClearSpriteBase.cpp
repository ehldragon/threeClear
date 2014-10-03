#include "ThreeClearSpriteBase.h"

ThreeClearSpriteBase::ThreeClearSpriteBase()
{

}

ThreeClearSpriteBase::~ThreeClearSpriteBase()
{

}

bool ThreeClearSpriteBase::init()
{
	if(!CCSprite::init()){
		return false;
	}

	return true;
}

bool ThreeClearSpriteBase::clearOver()
{
	runAction(CCRemoveSelf::create(true));
	return TRUE;
}
