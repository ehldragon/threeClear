#ifndef  _CLONE_CLEAR_H_
#define  _CLONE_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* �����������㷨
/*һ���������ɵ�ը�������������
/*�����е����ͬɫ�߿��������
/************************************************************************/
class CloneClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	CREATE_FUNC(CloneClear);
};

#endif