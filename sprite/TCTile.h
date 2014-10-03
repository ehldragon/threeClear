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
	~TCTile();

	bool init();

	/** 
	 * Ԫ���Ƿ���Ե������Ƭ��
	 */
	bool isEmpty();

	/**
	* �������
	*/
	bool clear();

	////////////////
 	int getShow();
	void setShow(int value);
	void setElement(TCElementBase *element);
 	TCElementBase* getElement();
	/**
	*�������ھ����е�λ��
	*/
	void setMatrix(int row, int col);

private:

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