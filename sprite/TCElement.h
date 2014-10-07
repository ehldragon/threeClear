#ifndef  _THREE_CLEAR_ELEMENT_H_
#define  _THREE_CLEAR_ELEMENT_H_

#include "cocos2d.h"
USING_NS_CC;

#include "TCElementBase.h"

/** 
 * 
 */
class TCElement : public TCElementBase{
private:
	/**��������Ԫ������*/
	int m_type;

	/**��������Ԫ�س���״̬����
	*��ͨ״̬����ȫ������ȫ��
	*Ĭ��ֵ-1
	*/
	int m_superType;
	
private:
	TCElement();
	
public:
	~TCElement();
	static TCElement* create();
	static TCElement* create(int type);

	bool init();

	virtual int getClearType();
	virtual bool isTypeEqualTo(TCElementBase *);
	virtual bool clear();

private:

};

#endif