#ifndef  _THREE_CLEAR_STONE_SPRITE_H_
#define  _THREE_CLEAR_STONE_SPRITE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"

/**
 * ʯͷ����
 * �������������element���ɱ�������������
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