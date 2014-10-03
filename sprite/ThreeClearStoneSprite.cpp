#include "ThreeClearStoneSprite.h"

ThreeClearStoneSprite::ThreeClearStoneSprite()
{

}

ThreeClearStoneSprite::~ThreeClearStoneSprite()
{

}

bool ThreeClearStoneSprite::init()
{
	if(!ThreeClearSpriteBase::init()){
		return false;
	}

	return true;
}

bool ThreeClearStoneSprite::clear()
{
	return false;
}
