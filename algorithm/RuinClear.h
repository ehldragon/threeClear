#ifndef  _RUIN_CLEAR_H_
#define  _RUIN_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* 毁灭性消除算法
/*两个五连消生成的炸弹进行组合
/*全部矩阵中的瓦块均被消除
/************************************************************************/
class RuinClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(RuinClear);
};

#endif