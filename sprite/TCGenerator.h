#ifndef  _TC_GENERATOR_H_
#define  _TC_GENERATOR_H_

/************************************************************************/
/* 被消除元素的生成器                                                                     */
/************************************************************************/
#include "cocos2d.h"
#include "TCElementBase.h"
USING_NS_CC;

class TCGenerator:public CCObject
{
public:
	/*单例，返回生成器对象*/
	static TCGenerator* sharedGenerator();
	/*获取一个element*/
	TCElementBase *getElement();
	/*获取多个element*/
	CCArray *getElements(int count);
private:
	/*声明称private的构造函数，可以防止该类被继承*/
	TCGenerator();
	bool init();
	/*随机生成一个element*/
	TCElementBase *generate();
	/*入队列*/
	void enqueue(TCElementBase *element);
	/*出队列*/
	TCElementBase* dequeue();
	/*检查队列元素数量*/
	void checkQueue();

private:
	/*队列，其中存放element*/
	CCArray *m_queue;
};
#endif	//_TC_GENERATOR_H_