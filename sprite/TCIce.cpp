#include "TCIce.h"

TCIce::TCIce()
:m_times(1)
{

}

TCIce::~TCIce()
{

}

TCIce* TCIce::create()
{
	TCIce *iceSprite = create(1);
	return iceSprite;
}

TCIce* TCIce::create(int times)
{
	TCIce *iceSprite = new TCIce();
	iceSprite->m_times = times;
	char *fileName = NULL;
	if(times == 1)
	{
		fileName = "threeclear/ice.png";
	}
	else
	{
		fileName = "threeclear/double_ice.png";
	}
	if (iceSprite && iceSprite->initWithFile(fileName))
	{
		iceSprite->autorelease();
		return iceSprite;
	}
	CC_SAFE_DELETE(iceSprite);
	return NULL;
}

bool TCIce::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

bool TCIce::clear()
{
	return false;
}

bool TCIce::allowMoveIn()
{
	return true;
}

bool TCIce::canMove()
{
	if(this->fillingElement != NULL)
	{
		return this->fillingElement->canMove();
	}
	return false;
}

int TCIce::getClearType()
{
	TCElementBase *clearElement = getClearElement();
	if(clearElement != NULL)
	{
		return clearElement->getClearType();
	}
	return TCElementBase::getClearType();
} 
