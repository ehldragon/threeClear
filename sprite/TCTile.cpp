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

TCTile* TCTile::create(int showValue, TCElementBase *element)
{
	TCTile *tile = new TCTile();
	if (tile && tile->initWithShowValue(showValue))
	{
		tile->autorelease();
		tile->setElement(element);
		return tile;
	}
	CC_SAFE_DELETE(tile);
	return NULL;
}

bool TCTile::initWithShowValue(int showValue)
{
	m_show = showValue;
	if(0 == showValue){
		return this->initWithFile("threeclear/show0.png");
	}
	else{
		return this->initWithFile("threeclear/show1.png");
	}
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

bool TCTile::canMove()
{
	//镂空的瓦块，以及没有element的空瓦块，都是不可以消除的。
	if(getShow() == TILE_SHOW_NONE ||  m_element == NULL)
	{
		return false;
	}
	//由element决定能否被移动交换
	return m_element->canMove();
}

bool TCTile::canClear()
{
	//镂空的瓦块，以及没有element的空瓦块，都是不可以交换的。
	if(getShow() == TILE_SHOW_NONE ||  m_element == NULL)
	{
		return false;
	}
	//由element决定能否被移动交换
	return m_element->canClear();
}

int TCTile::getRow(){
	return m_row;
}

int TCTile::getCol(){
	return m_col;
}

int TCTile::getShow()
{
	return m_show;
}

void TCTile::setElement(TCElementBase *element)
{
	if(element == NULL)
	{
		CC_SAFE_RELEASE_NULL(m_element);
		return;
	}
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
	if(0 == value){
		this->initWithFile("threeclear/show0.png");
	}
	else{
		this->initWithFile("threeclear/show1.png");
	}
}

TCElementBase* TCTile::getMoveElement()
{
	if(m_element != NULL)
	{
		return m_element->getMoveElement();
	}
	return NULL;
}





