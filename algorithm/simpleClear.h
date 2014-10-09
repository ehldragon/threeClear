#ifndef  _SIMPLE_CLEAR_H_
#define  _SIMPLE_CLEAR_H_

#include "clearAlgorithm.h"
/************************************************************************/
/* ��ͨ�����㷨A
��ͨelement �� A
���������ɵ�Ϊ�� B
�����������ɵ�Ϊ��C
���������ɵ�Ϊ:D

A���A A���B A���C�������
/************************************************************************/
class simpleClear: public clearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	virtual CCArray* scanClearTiles(TCTile *triggerTile);
	CREATE_FUNC(simpleClear);
private:

	CCArray* simpleClear::scan(TCTile *triggerTile);
	/*ɨ���С����еĿ������߿飬��һ���߿���Ϊ�е㣬��������ɨ��*/
	CCArray *scanRowWith(TCTile *triggerTile);
	CCArray *scanColWith(TCTile *triggerTile);
};

#endif