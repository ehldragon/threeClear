#ifndef  _THREE_CLEAR_SPRITE_BASE_H_
#define  _THREE_CLEAR_SPRITE_BASE_H_

#include "cocos2d.h"
USING_NS_CC;

/** 
 * 所有可消除元素的基类
 */
class ThreeClearSpriteBase : public CCSprite{

public:
	ThreeClearSpriteBase();
	virtual ~ThreeClearSpriteBase();



	bool init();

	virtual bool clear()=0;

	virtual bool clearOver();

private:

};

#endif