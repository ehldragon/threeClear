#ifndef  _THREE_CLEAR_ICE_SPRITE_H_
#define  _THREE_CLEAR_ICE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearSpriteBase.h"

class ThreeClearIceSprite : public ThreeClearSpriteBase{
private:

	int m_times;

private:
	ThreeClearIceSprite();
	
public:
	CREATE_FUNC(ThreeClearIceSprite);
	~ThreeClearIceSprite();

	bool init();

	bool clear();

private:

};

#endif