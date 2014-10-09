#ifndef  _CLEAR_ALGORITHM_H_
#define  _CLEAR_ALGORITHM_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "../ThreeClearConstants.h"
USING_NS_CC;

/************************************************************************/
/* 消除算法的基类，每种情况的消除算法集成该基类去实现								*/
/************************************************************************/
class clearAlgorithm : public CCObject{
public:
	clearAlgorithm();
	virtual ~clearAlgorithm();

	virtual bool init();

	/**扫描一个矩阵中的可消除的所有瓦块
	*返回数组，存有所有需要被消除的瓦块。如果返回空，说明没有可消除的
	*/
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst, TCTile* (*matrix)[MAP_COL_COUNT]) = 0;

private:
// 	/**作为触发点的两个瓦块，从此开始扫描*/
// 	TCTile *tileSrc;
// 	TCTile *tileDst;
// 	/**瓦块矩阵*/
// 	TCTile (*matrix)[MAP_COL_COUNT];
};

#endif