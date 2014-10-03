#ifndef  _THREE_CLEAR_SPRITE_BASE_H_
#define  _THREE_CLEAR_SPRITE_BASE_H_

#include "cocos2d.h"
USING_NS_CC;

/** 
 * ���п�����Ԫ�صĻ���
 */
class TCElementBase : public CCSprite{

public:
	TCElementBase();

	virtual ~TCElementBase();

	bool init();

	/**�Ƿ���Ա�������Ĭ�Ϸ���true*/
	virtual bool canClear();

	/**�Ƿ�������������element��Ĭ�Ϸ���false*/
	virtual bool allowMoveIn();

	/**�Ƿ���������ƶ�,Ĭ�Ϸ���true*/
	virtual bool canMove();

	/**��������*/
	virtual bool clear()=0;

	virtual bool clearOver();

	//////////
	void setFillingElement(TCElementBase *element);
	TCElementBase* getFillingElement();
protected:
	/**��������������element*/
	TCElementBase *fillingElement;
private:

};

#endif