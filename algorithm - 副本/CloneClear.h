#ifndef  _CLONE_CLEAR_H_
#define  _CLONE_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* 毁灭性消除算法
/*一个五消生成的炸弹组合其他类型
/*矩阵中的相关同色瓦块均被消除
/************************************************************************/
class CloneClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(CloneClear);
};

#endif