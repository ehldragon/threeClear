#ifndef  _THREE_CLEAR_LOCK_SPRITE_H_
#define  _THREE_CLEAR_LOCK_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"

/**
 * 笼子精灵
 * 可填充其他element，可被消除，不可以下落，内填充的element不可以下落
 */
class TCLock : public TCElementBase{
private:

private:
	TCLock();
	
public:
	CREATE_FUNC(TCLock);
	~TCLock();

	bool init();
	bool clear();

	virtual bool allowMoveIn();
	virtual bool canMove();
private:

};

#endif