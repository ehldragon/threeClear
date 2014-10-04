#ifndef  _THREE_CLEAR_MAP_H_
#define  _THREE_CLEAR_MAP_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearConstants.h"

#include "sprite/TCTile.h"

/** 
 * 游戏格子地图，所有消除元素都在地图数组中
 */
class ThreeClearMap : public CCLayer{
private:
	/**地图瓦片数组*/
	TCTile* m_map[MAP_ROW_COUNT][MAP_COL_COUNT];

	/**选中的行列索引*/
	CCPoint m_selectedPoint;
	int m_selectedRow;
	int m_selectedCol;

private:
	ThreeClearMap();
	bool testInit();
	bool mapInit();

	/** 
	 * 交换
	 */
	void swap(int srcRow, int srcCol, int dstRow, int dstCol);

	/** 
	 * 是否是合法的行列索引
	 */
	bool isValidRowCol(int row, int col);

	/** 
	 * 判断一个行列对应的瓦块，是否是可以被移动交换的
	 */
	bool canTileSwap(int row, int col);
public:
	CREATE_FUNC(ThreeClearMap);
	~ThreeClearMap();

	bool init();
	
	/** 
	 * 掉落检测（优先于消除检测）（在一个消除过程完成后，检测元素是否应该向下掉落，并发起掉落）
	 * TODO 实现期间可以使用按钮出发这个逻辑
	 * return 是否可以往下掉
	 */
	bool checkMoveDown();

	/** 
	 * 消除检测（递归算法判断并发起消除）
	 * TODO 实现期间可以使用按钮出发这个逻辑
	 * return 是否可以消除
	 */
	bool checkClear();

	/** 
	 * 根据矩阵的行列，获取瓦片的坐标
	 * return 坐标
	 */
	CCPoint getPoint(int row, int col);

	
private:
	// 触摸事件：按下
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

	// 触摸事件：移动
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

};

#endif