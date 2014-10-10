#ifndef  _SINGLE_CROSS_CLEAR_H_
#define  _SINGLE_CROSS_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* 十字消除算法
/*两个四连消生成的炸弹进行组合
/*十字消除，消除一行，或者一列
/************************************************************************/
class SingleCrossClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(SingleCrossClear);
private:
	CCArray* scan(TCTile *triggerTile);
};

#endif