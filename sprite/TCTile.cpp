#include "TCTile.h"

TCTile::TCTile()
:m_row(0)
,m_col(0)
,m_show(0)
,m_element(NULL)
{
	
}

TCTile::~TCTile()
{
	CC_SAFE_RELEASE_NULL(m_element);
}

bool TCTile::init()
{
	if(!CCSprite::init()){
		return false;
	}
	return true;
}

bool TCTile::isEmpty()
{
	if(m_show != TILE_SHOW_DEFAULT)
	{
		return false;
	}
	if(m_element != NULL)
	{
		return m_element->allowMoveIn();
	}
	return true;
}

int TCTile::getShow()
{
	return m_show;
}

void TCTile::setElement(TCElementBase *element)
{
	element->retain();
	if(m_element != NULL)
	{
		m_element->release();
	}
	m_element = element;
}

TCElementBase* TCTile::getElement()
{
	return m_element;
}

bool TCTile::clear()
{
	if(m_element != NULL)
	{
		return m_element->canClear();
	}
	return true;
}

void TCTile::setMatrix(int row, int col)
{
	m_row = row;
	m_col = col;
}

void TCTile::setShow(int value)
{
	m_show = value;
}



