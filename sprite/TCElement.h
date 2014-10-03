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
	int m_element;

	/**��ͨ״̬������ȫ��״̬������ȫ��״̬����ը״̬*/
	int m_state;
	
private:
	TCElement();
	
public:
	~TCElement();
	CREATE_FUNC(TCElement);

	bool init();

	bool clear();

	/** 
	 * ��ȡ������Ԫ������
	 */
	int getElementValue();

private:

};

#endif