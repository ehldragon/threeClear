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

private:
	ThreeClearMap();
	bool testInit();
	bool mapInit();

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

};

#endif