#ifndef  _THREE_CLEAR_TILE_H_
#define  _THREE_CLEAR_TILE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "../ThreeClearConstants.h"
#include "TCElementBase.h"


/**
 * 地图中的瓦片
 * 可以抽象成是一种容器。可显示，也可不显示（地图中镂空部分）；内含一个元素（可消除，或不可消除）
 */
class TCTile : public CCSprite{
public:
	CREATE_FUNC(TCTile);
	static TCTile* create(int showValue, TCElementBase *element);
	~TCTile();

	bool init();

	/** 
	 * 元素是否可以掉入此瓦片中
	 */
	bool isEmpty();

	/** 
	 *判断瓦片是否是可移动交换element
	 */
	bool canMove();

	/** 
	 *判断瓦片是否是可消除
	 */
	bool canClear();
	/**
	* 清除操作
	*/
	bool clear();
	
	/*** 获取能够移动的对象*/
	TCElementBase* getMoveElement();

	////////////////
	int getRow();
	int getCol();
 	int getShow();
	void setShow(int value);
	void setElement(TCElementBase *element);
 	TCElementBase* getElement();

	/**
	*设置所在矩阵中的位置
	*/
	void setMatrix(int row, int col);

private:
	bool initWithShowValue(int showValue);
	TCTile();
	/**所在行*/
	int m_row;

	/**所在列*/
	int m_col;

	/**标识瓦片显示方式：镂空不显示，显示等等*/
	int m_show;

	/**可消除元素对象,包括:陷阱（笼子，冰块等）、元素内容*/
	TCElementBase* m_element;

	/**传送门目的地tile，如果为null就是不传送的意思*/
	TCTile* m_transferToTile;

};

#endif