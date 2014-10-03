#ifndef  _THREE_CLEAR_ICE_SPRITE_H_
#define  _THREE_CLEAR_ICE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"
/**
 * ���龫��
 * ���������element���ɱ����������������䣬������element��������
 */
class TCIce : public TCElementBase{
private:
	/**��������������������������������Ҫ����������*/
	byte m_times;

private:
	TCIce();
	
public:
	CREATE_FUNC(TCIce);
	~TCIce();

	bool init();

	virtual bool clear();

	virtual bool allowMoveIn();
	virtual bool canMove();
private:

};

#endif