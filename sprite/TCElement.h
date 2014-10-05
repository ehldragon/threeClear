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
	/**可消除的元素类型*/
	int m_type;

	/**普通状态，横行全消状态，竖行全消状态，爆炸状态*/
	int m_state;
	
private:
	TCElement();
	
public:
	~TCElement();
	static TCElement* create();
	static TCElement* create(int type);

	bool init();

	virtual int getClearType();
	virtual bool clear();

private:

};

#endif