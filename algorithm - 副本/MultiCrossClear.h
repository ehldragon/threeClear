#ifndef  _MULTI_CROSS_CLEAR_H_
#define  _MULTI_CROSS_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* 多重十字消除算法
/*两个四连消生成的炸弹，或一个三三连消组合四连消炸弹进行
/*多行多列消除
/************************************************************************/
class MultiCrossClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(MultiCrossClear);
private:
	CCArray* scan(TCTile *tileSrc, TCTile *tileDst);
};

#endif