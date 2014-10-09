#ifndef  _SIMPLE_CLEAR_H_
#define  _SIMPLE_CLEAR_H_

#include "clearAlgorithm.h"
/************************************************************************/
/* 普通消除算法A
普通element ： A
四连消生成的为： B
三三连消生成的为：C
五连消生成的为:D

A组合A A组合B A组合C情况适用
/************************************************************************/
class simpleClear: public clearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	virtual CCArray* scanClearTiles(TCTile *triggerTile);
	CREATE_FUNC(simpleClear);
private:

	CCArray* simpleClear::scan(TCTile *triggerTile);
	/*扫描行、列中的可消除瓦块，以一个瓦块作为中点，左右上下扫描*/
	CCArray *scanRowWith(TCTile *triggerTile);
	CCArray *scanColWith(TCTile *triggerTile);
};

#endif