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

	virtual bool init();

	/**�Ƿ�������������element��Ĭ�Ϸ���false*/
	virtual bool allowMoveIn();

	/**�Ƿ���Ա�������Ĭ�Ϸ���true*/
	virtual bool canClear();

	/**�Ƿ���������ƶ�,Ĭ�Ϸ���true*/
	virtual bool canMove();

	/**�ڻ���������ʱ����ȡ�ĸ�����Ӧ�ñ�ִ�С�Ĭ����this����
	*���ڱ�����˵��ʵ����Ӧ�����Լ��������������ں���element
	*/
	virtual TCElementBase* getMoveElement();

	/**�ڻ���������ʱ�����ö���Ӧ�ñ�ִ��
	*���ڱ�����˵��ʵ����Ӧ�����Լ��������������ں���element
	*/
	virtual void setMoveElement(TCElementBase *element);

	/**��ȡ���Ա�������Ԫ��,Ĭ����this
	*���ڱ�����˵��ʵ����Ӧ�����ں���element
	*/
	virtual TCElementBase* getClearElement();

	/**  ��ȡ������Ԫ������,Ĭ��-1��
	 * ���ڱ�ʶ�ɱ�����element�����࣬��ɫ
	 */
	virtual int getClearType();
	virtual void setClearType(int type);
	/**  ��ȡ������Ԫ�س�������,Ĭ��-1��
	 * ���ڱ�ʶ�ɱ�����element�ĳ���Ч����һ�У�һ�У���Χ��
	 */
	virtual int getSuperClearType();
	virtual void setSuperClearType(int superType);

	/**  �ж���ָ���ɱ�����Ԫ�ص������Ƿ���ͬ��������ɫ�Ƿ���ͬ,
	 *	Ĭ�Ϸ���false
	 */
	virtual bool isTypeEqualTo(TCElementBase *element);

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