#ifndef  _THREE_CLEAR_STONE_SPRITE_H_
#define  _THREE_CLEAR_STONE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearSpriteBase.h"

class ThreeClearStoneSprite : public ThreeClearSpriteBase{
private:

private:
	ThreeClearStoneSprite();
	
public:
	~ThreeClearStoneSprite();
	CREATE_FUNC(ThreeClearStoneSprite);

	bool init();

	bool clear();

private:

};

#endif