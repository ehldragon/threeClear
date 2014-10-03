#ifndef  _THREE_CLEAR_LOCK_SPRITE_H_
#define  _THREE_CLEAR_LOCK_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearSpriteBase.h"

class ThreeClearLockSprite : public ThreeClearSpriteBase{
private:

private:
	ThreeClearLockSprite();
	
public:
	CREATE_FUNC(ThreeClearLockSprite);
	~ThreeClearLockSprite();

	bool init();
	bool clear();

private:

};

#endif