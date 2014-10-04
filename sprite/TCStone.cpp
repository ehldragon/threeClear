#include "TCStone.h"

TCStone::TCStone()
{

}

TCStone::~TCStone()
{

}

TCStone* TCStone::create()
{
	TCStone *stoneSprite = new TCStone();
	if (stoneSprite && stoneSprite->initWithFile("threeclear/stone.png"))
	{
		stoneSprite->autorelease();
		return stoneSprite;
	}
	CC_SAFE_DELETE(stoneSprite);
	return NULL;
}

bool TCStone::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

bool TCStone::clear()
{
	return false;
}

