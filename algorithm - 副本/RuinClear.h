#ifndef  _RUIN_CLEAR_H_
#define  _RUIN_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* �����������㷨
/*�������������ɵ�ը���������
/*ȫ�������е��߿��������
/************************************************************************/
class RuinClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(RuinClear);
};

#endif