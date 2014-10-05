#ifndef  _THREE_CLEAR_TILE_H_
#define  _THREE_CLEAR_TILE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "../ThreeClearConstants.h"
#include "TCElementBase.h"


/**
 * ��ͼ�е���Ƭ
 * ���Գ������һ������������ʾ��Ҳ�ɲ���ʾ����ͼ���οղ��֣����ں�һ��Ԫ�أ����������򲻿�������
 */
class TCTile : public CCSprite{
public:
	CREATE_FUNC(TCTile);
	static TCTile* create(int showValue, TCElementBase *element);
	~TCTile();

	bool init();

	/** 
	 * Ԫ���Ƿ���Ե������Ƭ��
	 */
	bool isEmpty();

	/** 
	 *�ж���Ƭ�Ƿ��ǿ��ƶ�����element
	 */
	bool canMove();

	/** 
	 *�ж���Ƭ�Ƿ��ǿ�����
	 */
	bool canClear();
	/**
	* �������
	*/
	bool clear();
	
	/*** ��ȡ�ܹ��ƶ��Ķ���*/
	TCElementBase* getMoveElement();

	////////////////
	int getRow();
	int getCol();
 	int getShow();
	void setShow(int value);
	void setElement(TCElementBase *element);
 	TCElementBase* getElement();

	/**
	*�������ھ����е�λ��
	*/
	void setMatrix(int row, int col);

private:
	bool initWithShowValue(int showValue);
	TCTile();
	/**������*/
	int m_row;

	/**������*/
	int m_col;

	/**��ʶ��Ƭ��ʾ��ʽ���οղ���ʾ����ʾ�ȵ�*/
	int m_show;

	/**������Ԫ�ض���,����:���壨���ӣ�����ȣ���Ԫ������*/
	TCElementBase* m_element;

	/**������Ŀ�ĵ�tile�����Ϊnull���ǲ����͵���˼*/
	TCTile* m_transferToTile;

};

#endif