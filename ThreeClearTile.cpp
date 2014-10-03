#include "ThreeClearTile.h"

ThreeClearTile::ThreeClearTile()
:m_row(0)
,m_col(0)
,m_show(0)
,m_isFull(false)
,m_trap(TILE_TRAP_EMPTY)
,m_element(NULL)
,m_tranformTile(NULL)
,m_lockSprite(NULL)
{
	
}

ThreeClearTile::~ThreeClearTile()
{
	if(m_element){
		m_element->release();
		m_element = NULL;
	}
	if(m_tranformTile){
		m_tranformTile->release();
		m_tranformTile = NULL;
	}
	if(m_lockSprite){
		m_lockSprite->release();
		m_lockSprite = NULL;
	}
}

bool ThreeClearTile::init()
{
	if(!CCSprite::init()){
		return false;
	}

	return true;
}


bool ThreeClearTile::isEmpty()
{
	if(m_isFull){
		return false;
	}

	if(m_lockSprite){
		return false;
	}

	if(m_trap == TILE_TRAP_STONE){
		return false;
	}

	if(m_element->getElement() == TILE_ELEMENT_EMPTY){
		return false;
	}
	return true;
}

int ThreeClearTile::getShow()
{
	return m_show;
}

int ThreeClearTile::getTrap()
{
	return m_trap;
}

ThreeClearElement* ThreeClearTile::getElement()
{
	return m_element;
}

void ThreeClearTile::setLock(bool isLock)
{
	if(isLock){
		if(m_lockSprite){
			m_lockSprite->release();

			m_lockSprite = ThreeClearLockSprite::create(); // TODO 自己去找笼子的图片
			m_lockSprite->retain();
		}
	}
}

CCSprite* ThreeClearTile::getLockSprite(){
	return m_lockSprite;
}

bool ThreeClearTile::clear()
{
	return false;
}

void ThreeClearTile::set(int row, int col, int show)
{
	m_row = row;
	m_col = col;
	m_show = show;
}

void ThreeClearTile::setTrap(int trap)
{
	m_trap = trap;
}

