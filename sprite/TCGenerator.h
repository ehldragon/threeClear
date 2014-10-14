#ifndef  _TC_GENERATOR_H_
#define  _TC_GENERATOR_H_

/************************************************************************/
/* ������Ԫ�ص�������                                                                     */
/************************************************************************/
#include "cocos2d.h"
#include "TCElementBase.h"
USING_NS_CC;

class TCGenerator:public CCObject
{
public:
	/*��������������������*/
	static TCGenerator* sharedGenerator();
	/*��ȡһ��element*/
	TCElementBase *getElement();
	/*��ȡ���element*/
	CCArray *getElements(int count);
private:
	/*������private�Ĺ��캯�������Է�ֹ���౻�̳�*/
	TCGenerator();
	bool init();
	/*�������һ��element*/
	TCElementBase *generate();
	/*�����*/
	void enqueue(TCElementBase *element);
	/*������*/
	TCElementBase* dequeue();
	/*������Ԫ������*/
	void checkQueue();

private:
	/*���У����д��element*/
	CCArray *m_queue;
};
#endif	//_TC_GENERATOR_H_