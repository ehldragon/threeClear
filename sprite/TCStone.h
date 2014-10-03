#ifndef  _THREE_CLEAR_STONE_SPRITE_H_
#define  _THREE_CLEAR_STONE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"

/**
 * 石头精灵
 * 不可以填充其他element，可被消除，可下落
 */

class TCStone : public TCElementBase{
private:

private:
	TCStone();
	
public:
	~TCStone();
	static TCStone* create();

	bool init();

	virtual bool clear();
private:

};

#endif