#include "ThreeClearIceSprite.h"

ThreeClearIceSprite::ThreeClearIceSprite()
:m_times(1)
{

}

ThreeClearIceSprite::~ThreeClearIceSprite()
{

}

bool ThreeClearIceSprite::init()
{
	if(!ThreeClearSpriteBase::init()){
		return false;
	}

	return true;
}

bool ThreeClearIceSprite::clear()
{
	return false;
}
