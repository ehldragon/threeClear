#ifndef  _THREE_CLEAR_TILE_H_
#define  _THREE_CLEAR_TILE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "ThreeClearConstants.h"
#include "sprite/ThreeClearSpriteBase.h"
#include "sprite/ThreeClearElement.h"
#include "sprite/ThreeClearLockSprite.h"

/**
 * ��ͼ�е���Ƭ
 */
class ThreeClearTile : public CCSprite{
private:
	/**������*/
	int m_row;

	/**������*/
	int m_col;

	/**��ʾ����*/
	int m_show;

	/**�Ƿ񱻷���*/
	bool m_isFull;

	/**�Ƿ�����-���Ӿ���*/
	ThreeClearLockSprite* m_lockSprite;

	/**����Ԫ�أ������谭�������ģ�����˫�ر���ʯͷ*/
	int m_trap;
	ThreeClearSpriteBase* m_trapSprite;
	
	/**������Ԫ�ض���*/
	ThreeClearElement* m_element;

	/**������Ŀ�ĵ�tile�����Ϊnull���ǲ����͵���˼*/
	ThreeClearTile* m_tranformTile;

private:
	ThreeClearTile();

public:
	CREATE_FUNC(ThreeClearTile);
	~ThreeClearTile();

	bool init();

	/** 
	 * Ԫ���Ƿ���Ե������Ƭ��
	 */
	bool isEmpty();

	int getShow();
	int getTrap();
	ThreeClearElement* getElement();
	void setLock(bool isLock);
	CCSprite* getLockSprite();

	bool clear();

	void set(int row, int col, int show);
	void setTrap(int trap);
public:


};

#endif