#ifndef  _THREE_CLEAR_ELEMENT_H_
#define  _THREE_CLEAR_ELEMENT_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearSpriteBase.h"

/** 
 * ��Ƭ�е�Ԫ�أ���������Ԫ�أ�
 */
class ThreeClearElement : public ThreeClearSpriteBase{
private:
	/**��������Ԫ������*/
	int m_element;

	/**��ͨ״̬������ȫ��״̬������ȫ��״̬����ը״̬*/
	int m_state;
	
private:
	ThreeClearElement();
	
public:
	~ThreeClearElement();
	CREATE_FUNC(ThreeClearElement);

	bool init();

	bool clear();

	/** 
	 * ��ȡ������Ԫ������
	 */
	int getElement();

private:

};

#endif