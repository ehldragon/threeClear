#ifndef  _CLEAR_ALGORITHM_H_
#define  _CLEAR_ALGORITHM_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "../ThreeClearConstants.h"
USING_NS_CC;

typedef TCTile* (*MatrixPtr)[MAP_COL_COUNT];
/************************************************************************/
/* 消除算法的基类，每种情况的消除算法集成该基类去实现								*/
/************************************************************************/
class ClearAlgorithm : public CCObject{
public:
	ClearAlgorithm();
	virtual ~ClearAlgorithm();

	virtual bool init();

	/** 
	 * 判断一个行列对应的瓦块，是否是可以被的消除的
	 */
	bool canTileClear(int row, int col);

	/** 
	 * 是否是合法的行列索引
	 */
	 bool isValidRowCol(int row, int col);

	 /*判断矩阵中一个瓦块是否出界，是否可以被消除，类型是否与指定瓦块相同*/
	 bool isTypeSameWith(int row, int col, TCTile *originalTile);

	/**扫描一个矩阵中的可消除的所有瓦块
	*返回数组，存有所有需要被消除的瓦块。如果返回空，说明没有可消除的
	*触发点瓦块为两个交换后的瓦块，主要用于滑动操作后的扫描
	*/
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);

	/**扫描一个矩阵中的可消除的所有瓦块
	*返回数组，存有所有需要被消除的瓦块。如果返回空，说明没有可消除的
	*/
	virtual CCArray* scanClearTiles(TCTile *triggerTile);

	void setMatrix(MatrixPtr newMatrix);
protected:
	/**递归扫描所有有特殊效果的点爆破后，还需要被消除的点
	*注释：在滑动交换后获取被消除的瓦块后，其中可能包含有特殊效果的瓦块（消除一行，一列等），还需要以各个点为起点进行一次递归扫描
	*，才能全部获取到需要被消除的点。
	*/
	void scanSuperTiles(CCArray *clearTilesArray);

	/*以一个瓦块为起点进行递归扫描特殊点*/
	void scanSuperTile(TCTile *startTile, CCArray *rootArray);

	/*获取一个特殊瓦块被消除时，相关联需要被消除的瓦块*/
	CCArray* getRelates(TCTile *tile, CCArray *rootArray);

	CCArray* getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd, CCArray *rootArray);
	CCArray* getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd);

	CCArray* getMatrixSurrond(int rowBegin, int colBegin, CCArray *rootArray);

	/*将瓦块对象插入指定的数组中，保证不能有重复的*/
	void addTileToArray(CCArray *array, CCObject *object);

	/*将数组插入指定的数组中，保证不能有重复的*/
	void addArrayToArray(CCArray *srcArray,CCArray *dstArray);

protected:
// 	/**作为触发点的两个瓦块，从此开始扫描*/
// 	TCTile *tileSrc;
// 	TCTile *tileDst;
 	/**瓦块矩阵*/
 	TCTile* (*matrix)[MAP_COL_COUNT];
};

#endif