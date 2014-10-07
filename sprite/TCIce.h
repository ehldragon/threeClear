#ifndef  _THREE_CLEAR_ICE_SPRITE_H_
#define  _THREE_CLEAR_ICE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"
/**
 * 冰块精灵
 * 可填充其他element，可被消除，不可以下落，内填充的element可以下落
 */
class TCIce : public TCElementBase{
private:
	/**冰块的消除次数。即冰块的生命力，需要被消除几次*/
	byte m_times;

private:
	TCIce();
	
public:
	static TCIce* create();
	static TCIce* create(int times);
	~TCIce();

	bool init();

	virtual bool clear();

	virtual bool allowMoveIn();
	virtual bool canMove();
	virtual int getClearType();

private:

};

#endif