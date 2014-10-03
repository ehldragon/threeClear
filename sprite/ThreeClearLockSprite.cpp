#include "ThreeClearLockSprite.h"



ThreeClearLockSprite::ThreeClearLockSprite()
{

}

ThreeClearLockSprite::~ThreeClearLockSprite()
{

}

bool ThreeClearLockSprite::init()
{
	if(!ThreeClearSpriteBase::init()){
		return false;
	}

	return true;
}

bool ThreeClearLockSprite::clear()
{
	return false;
}
