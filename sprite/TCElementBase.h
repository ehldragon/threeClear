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

	virtual bool init();

	/**是否允许填充进其他element，默认返回false*/
	virtual bool allowMoveIn();

	/**是否可以被消除，默认返回true*/
	virtual bool canClear();

	/**是否自身可以移动,默认返回true*/
	virtual bool canMove();

	/**在滑动、下落时，获取哪个对象应该被执行。默认是this本身
	*对于冰块来说，实际上应该是自己本身不动，交换内含的element
	*/
	virtual TCElementBase* getMoveElement();

	/**在滑动、下落时，设置对象应该被执行
	*对于冰块来说，实际上应该是自己本身不动，交换内含的element
	*/
	virtual void setMoveElement(TCElementBase *element);

	/**获取可以被消除的元素,默认是this
	*对于冰块来说，实际上应该是内含的element
	*/
	virtual TCElementBase* getClearElement();

	/**  获取可消除元素类型,默认-1。
	 * 用于标识可被消除element的种类，花色
	 */
	virtual int getClearType();
	virtual void setClearType(int type);
	/**  获取可消除元素超级类型,默认-1。
	 * 用于标识可被消除element的超级效果：一行，一列，周围等
	 */
	virtual int getSuperClearType();
	virtual void setSuperClearType(int superType);

	/**  判断与指定可被消除元素的类型是否相同，即：花色是否相同,
	 *	默认返回false
	 */
	virtual bool isTypeEqualTo(TCElementBase *element);

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