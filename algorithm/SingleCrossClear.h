#ifndef  _SINGLE_CROSS_CLEAR_H_
#define  _SINGLE_CROSS_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* ʮ�������㷨
/*�������������ɵ�ը���������
/*ʮ������������һ�У�����һ��
/************************************************************************/
class SingleCrossClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(SingleCrossClear);
private:
	CCArray* scan(TCTile *triggerTile);
};

#endif