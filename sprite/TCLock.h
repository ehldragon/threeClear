#ifndef  _THREE_CLEAR_LOCK_SPRITE_H_
#define  _THREE_CLEAR_LOCK_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"

/**
 * ���Ӿ���
 * ���������element���ɱ����������������䣬������element����������
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