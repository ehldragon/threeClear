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

	/**可消除的元素超级状态类型
	*普通状态，横全消，竖全消
	*默认值-1
	*/
	int m_superType;
	
private:
	TCElement();
	
public:
	~TCElement();
	static TCElement* create();
	static TCElement* create(int type);
	static TCElement* TCElement::create(int type, int superType);

	bool init();

	virtual int getClearType();
	virtual void setClearType(int superType);
	virtual int getSuperClearType();
	virtual void setSuperClearType(int superType);
	virtual bool isTypeEqualTo(TCElementBase *);
	virtual bool clear();

private:

};

#endif