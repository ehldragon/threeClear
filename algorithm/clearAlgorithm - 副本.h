#ifndef  _CLEAR_ALGORITHM_H_
#define  _CLEAR_ALGORITHM_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "../ThreeClearConstants.h"
USING_NS_CC;

/************************************************************************/
/* �����㷨�Ļ��࣬ÿ������������㷨���ɸû���ȥʵ��								*/
/************************************************************************/
class clearAlgorithm : public CCObject{
public:
	clearAlgorithm();
	virtual ~clearAlgorithm();

	virtual bool init();

	/**ɨ��һ�������еĿ������������߿�
	*�������飬����������Ҫ���������߿顣������ؿգ�˵��û�п�������
	*/
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst, TCTile* (*matrix)[MAP_COL_COUNT]) = 0;

private:
// 	/**��Ϊ������������߿飬�Ӵ˿�ʼɨ��*/
// 	TCTile *tileSrc;
// 	TCTile *tileDst;
// 	/**�߿����*/
// 	TCTile (*matrix)[MAP_COL_COUNT];
};

#endif