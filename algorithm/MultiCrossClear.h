#ifndef  _MULTI_CROSS_CLEAR_H_
#define  _MULTI_CROSS_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* ����ʮ�������㷨
/*�������������ɵ�ը������һ�����������������ը������
/*���ж�������
/************************************************************************/
class MultiCrossClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(MultiCrossClear);
};

#endif