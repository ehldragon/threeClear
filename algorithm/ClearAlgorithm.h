#ifndef  _CLEAR_ALGORITHM_H_
#define  _CLEAR_ALGORITHM_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "../ThreeClearConstants.h"
USING_NS_CC;

typedef TCTile* (*MatrixPtr)[MAP_COL_COUNT];
/************************************************************************/
/* �����㷨�Ļ��࣬ÿ������������㷨���ɸû���ȥʵ��								*/
/************************************************************************/
class ClearAlgorithm : public CCObject{
public:
	ClearAlgorithm();
	virtual ~ClearAlgorithm();

	virtual bool init();

	/** 
	 * �ж�һ�����ж�Ӧ���߿飬�Ƿ��ǿ��Ա���������
	 */
	bool canTileClear(int row, int col);

	/** 
	 * �Ƿ��ǺϷ�����������
	 */
	 bool isValidRowCol(int row, int col);

	 /*�жϾ�����һ���߿��Ƿ���磬�Ƿ���Ա������������Ƿ���ָ���߿���ͬ*/
	 bool isTypeSameWith(int row, int col, TCTile *originalTile);

	/**ɨ��һ�������еĿ������������߿�
	*�������飬����������Ҫ���������߿顣������ؿգ�˵��û�п�������
	*�������߿�Ϊ������������߿飬��Ҫ���ڻ����������ɨ��
	*/
	virtual CCArray* scanClearTiles(TCTile *tileSrc, TCTile *tileDst);

	/**ɨ��һ�������еĿ������������߿�
	*�������飬����������Ҫ���������߿顣������ؿգ�˵��û�п�������
	*/
	virtual CCArray* scanClearTiles(TCTile *triggerTile);

	void setMatrix(MatrixPtr newMatrix);
protected:
	/**�ݹ�ɨ������������Ч���ĵ㱬�ƺ󣬻���Ҫ�������ĵ�
	*ע�ͣ��ڻ����������ȡ���������߿�����п��ܰ���������Ч�����߿飨����һ�У�һ�еȣ�������Ҫ�Ը�����Ϊ������һ�εݹ�ɨ��
	*������ȫ����ȡ����Ҫ�������ĵ㡣
	*/
	void scanSuperTiles(CCArray *clearTilesArray);

	/*��һ���߿�Ϊ�����еݹ�ɨ�������*/
	void scanSuperTile(TCTile *startTile, CCArray *rootArray);

	/*��ȡһ�������߿鱻����ʱ���������Ҫ���������߿�*/
	CCArray* getRelates(TCTile *tile, CCArray *rootArray);

	CCArray* getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd, CCArray *rootArray);
	CCArray* getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd);

	CCArray* getMatrixSurrond(int rowBegin, int colBegin, CCArray *rootArray);

	/*���߿�������ָ���������У���֤�������ظ���*/
	void addTileToArray(CCArray *array, CCObject *object);

	/*���������ָ���������У���֤�������ظ���*/
	void addArrayToArray(CCArray *srcArray,CCArray *dstArray);

protected:
// 	/**��Ϊ������������߿飬�Ӵ˿�ʼɨ��*/
// 	TCTile *tileSrc;
// 	TCTile *tileDst;
 	/**�߿����*/
 	TCTile* (*matrix)[MAP_COL_COUNT];
};

#endif