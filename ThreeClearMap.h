#ifndef  _THREE_CLEAR_MAP_H_
#define  _THREE_CLEAR_MAP_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearConstants.h"

#include "sprite/TCTile.h"

/** 
 * ��Ϸ���ӵ�ͼ����������Ԫ�ض��ڵ�ͼ������
 */
class ThreeClearMap : public CCLayer{
private:
	/**��ͼ��Ƭ����*/
	TCTile* m_map[MAP_ROW_COUNT][MAP_COL_COUNT];

	/*��������ʱ��ǰ�������߿�*/
	TCTile *m_srcSwapTile;
	TCTile *m_dstSwapTile;

	/*�������������Ӧ�ñ��������߿�*/
	CCArray *m_clearTileArray;

	/*������������д������������߿飬����������߿鿪ʼɨ�������������߿�*/
	CCArray *m_triggerTileArray;

	/**ѡ�е���������*/
	CCPoint m_selectedPoint;
	int m_selectedRow;
	int m_selectedCol;

private:
	ThreeClearMap();
	bool testInit();
	bool mapInit();

	/** 
	 * ����
	 */
	void swap(int srcRow, int srcCol, int dstRow, int dstCol);

	void reverse(int srcRow, int srcCol, int dstRow, int dstCol);
	/** 
	 * �Ƿ��ǺϷ�����������
	 */
	bool isValidRowCol(int row, int col);

	/** 
	 * �ж�һ�����ж�Ӧ���߿飬�Ƿ��ǿ��Ա��ƶ�������
	 */
	bool canTileSwap(int row, int col);

	/** 
	 * �ж�һ�����ж�Ӧ���߿飬�Ƿ��ǿ��Ա���������
	 */
	bool canTileClear(int row, int col);

	/*ɨ���Ƿ��з������������Ա��������߿�*/
	bool scanClear();

	/*ɨ���С����еĿ������߿飬��һ���߿���Ϊ�е㣬��������ɨ��*/
	CCArray *scanRowWith(TCTile *triggerTile);
	CCArray *scanColWith(TCTile *triggerTile);

	/*�жϾ�����һ���߿��Ƿ���磬�Ƿ���Ա������������Ƿ���ָ���߿���ͬ*/
	bool isTypeSameWith(int row, int col, TCTile *originalTile);
	/*�����߿�*/
	void clearTiles();

	/*���߿�������ָ���������У���֤�������ظ���*/
	void addTileToArray(CCArray *array, CCObject *object);

	/*���������ָ���������У���֤�������ظ���*/
	void addArrayToArray(CCArray *srcArray,CCArray *dstArray);
public:
	CREATE_FUNC(ThreeClearMap);
	~ThreeClearMap();

	bool init();
	
	/** 
	 * �����⣨������������⣩����һ������������ɺ󣬼��Ԫ���Ƿ�Ӧ�����µ��䣬��������䣩
	 * TODO ʵ���ڼ����ʹ�ð�ť��������߼�
	 * return �Ƿ�������µ�
	 */
	bool checkMoveDown();

	/** 
	 * ������⣨�ݹ��㷨�жϲ�����������
	 * TODO ʵ���ڼ����ʹ�ð�ť��������߼�
	 * return �Ƿ��������
	 */
	bool checkClear();

	/** 
	 * ���ݾ�������У���ȡ��Ƭ������
	 * return ����
	 */
	CCPoint getPoint(int row, int col);

	
private:
	// �����¼�������
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

	// �����¼����ƶ�
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

	//�����߿��element
	void swapElement();

};

#endif