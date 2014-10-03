#ifndef  _THREE_CLEAR_SPRITE_BASE_H_
#define  _THREE_CLEAR_SPRITE_BASE_H_

#include "cocos2d.h"
USING_NS_CC;

/** 
 * 所有可消除元素的基类
 */
class TCElementBase : public CCSprite{

public:
	TCElementBase();

	virtual ~TCElementBase();

	bool init();

	/**是否可以被消除，默认返回true*/
	virtual bool canClear();

	/**是否允许填充进其他element，默认返回false*/
	virtual bool allowMoveIn();

	/**是否自身可以移动,默认返回true*/
	virtual bool canMove();

	/**消除处理*/
	virtual bool clear()=0;

	virtual bool clearOver();

	//////////
	void setFillingElement(TCElementBase *element);
	TCElementBase* getFillingElement();
protected:
	/**被填充进来的其他element*/
	TCElementBase *fillingElement;
private:

};

#endif