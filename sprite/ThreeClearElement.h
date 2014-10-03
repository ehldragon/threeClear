#ifndef  _THREE_CLEAR_ELEMENT_H_
#define  _THREE_CLEAR_ELEMENT_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearSpriteBase.h"

/** 
 * 瓦片中的元素（可消除的元素）
 */
class ThreeClearElement : public ThreeClearSpriteBase{
private:
	/**可消除的元素类型*/
	int m_element;

	/**普通状态，横行全消状态，竖行全消状态，爆炸状态*/
	int m_state;
	
private:
	ThreeClearElement();
	
public:
	~ThreeClearElement();
	CREATE_FUNC(ThreeClearElement);

	bool init();

	bool clear();

	/** 
	 * 获取可消除元素类型
	 */
	int getElement();

private:

};

#endif