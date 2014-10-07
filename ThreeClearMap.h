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

	/*滑动交换时，前后两个瓦块*/
	TCTile *m_srcSwapTile;
	TCTile *m_dstSwapTile;

	/*容器，存放所有应该被消除的瓦块*/
	CCArray *m_clearTileArray;

	/*容器，存放所有触发点消除的瓦块，即：用这个瓦块开始扫描消除的其他瓦块*/
	CCArray *m_triggerTileArray;

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

	void reverse(int srcRow, int srcCol, int dstRow, int dstCol);
	/** 
	 * 是否是合法的行列索引
	 */
	bool isValidRowCol(int row, int col);

	/** 
	 * 判断一个行列对应的瓦块，是否是可以被移动交换的
	 */
	bool canTileSwap(int row, int col);

	/** 
	 * 判断一个行列对应的瓦块，是否是可以被的消除的
	 */
	bool canTileClear(int row, int col);

	/*扫描是否有符合条件，可以被消除的瓦块*/
	bool scanClear();

	/*扫描行、列中的可消除瓦块，以一个瓦块作为中点，左右上下扫描*/
	CCArray *scanRowWith(TCTile *triggerTile);
	CCArray *scanColWith(TCTile *triggerTile);

	/*判断矩阵中一个瓦块是否出界，是否可以被消除，类型是否与指定瓦块相同*/
	bool isTypeSameWith(int row, int col, TCTile *originalTile);
	/*消除瓦块*/
	void clearTiles();

	/*将瓦块对象插入指定的数组中，保证不能有重复的*/
	void addTileToArray(CCArray *array, CCObject *object);

	/*将数组插入指定的数组中，保证不能有重复的*/
	void addArrayToArray(CCArray *srcArray,CCArray *dstArray);
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

	//交换瓦块的element
	void swapElement();

};

#endif