#ifndef  _THREE_CLEAR_TILE_H_
#define  _THREE_CLEAR_TILE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearConstants.h"
#include "sprite/ThreeClearSpriteBase.h"
#include "sprite/ThreeClearElement.h"
#include "sprite/ThreeClearLockSprite.h"

/**
 * 地图中的瓦片
 */
class ThreeClearTile : public CCSprite{
private:
	/**所在行*/
	int m_row;

	/**所在列*/
	int m_col;

	/**显示变量*/
	int m_show;

	/**是否被封死*/
	bool m_isFull;

	/**是否有锁-笼子精灵*/
	ThreeClearLockSprite* m_lockSprite;

	/**陷阱元素，用来阻碍我消除的，冰，双重冰，石头*/
	int m_trap;
	ThreeClearSpriteBase* m_trapSprite;
	
	/**可消除元素对象*/
	ThreeClearElement* m_element;

	/**传送门目的地tile，如果为null就是不传送的意思*/
	ThreeClearTile* m_tranformTile;

private:
	ThreeClearTile();

public:
	CREATE_FUNC(ThreeClearTile);
	~ThreeClearTile();

	bool init();

	/** 
	 * 元素是否可以掉入此瓦片中
	 */
	bool isEmpty();

	int getShow();
	int getTrap();
	ThreeClearElement* getElement();
	void setLock(bool isLock);
	CCSprite* getLockSprite();

	bool clear();

	void set(int row, int col, int show);
	void setTrap(int trap);
public:


};

#endif