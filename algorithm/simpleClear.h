#ifndef  _SIMPLE_CLEAR_H_
#define  _SIMPLE_CLEAR_H_

#include "ClearAlgorithm.h"
/************************************************************************/
/* ��ͨ�����㷨
��ͨelement �� A
���������ɵ�Ϊ�� B
�����������ɵ�Ϊ��C
���������ɵ�Ϊ:D

A���A A���B A���C�������
/************************************************************************/
class SimpleClear: public ClearAlgorithm{
public:
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);
	virtual CCArray* scanClearTiles(TCTile *triggerTile);
	CREATE_FUNC(SimpleClear);
private:

	CCArray* SimpleClear::scan(TCTile *triggerTile);
	/*ɨ���С����еĿ������߿飬��һ���߿���Ϊ�е㣬��������ɨ��*/
	CCArray *scanRowWith(TCTile *triggerTile);
	CCArray *scanColWith(TCTile *triggerTile);
};

#endif