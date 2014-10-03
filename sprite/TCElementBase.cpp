#include "TCElementBase.h"

TCElementBase::TCElementBase():fillingElement(NULL)
{

}


TCElementBase::~TCElementBase()
{
	CC_SAFE_RELEASE_NULL(fillingElement);
}

bool TCElementBase::init()
{
	if(!CCSprite::init()){
		return false;
	}

	return true;
}

void TCElementBase::setFillingElement(TCElementBase *element)
{
	element->retain();
	if(fillingElement != NULL)
	{
		fillingElement->release();
	}
	fillingElement = element;
}

TCElementBase* TCElementBase::getFillingElement()
{
	return fillingElement;
};


bool TCElementBase::allowMoveIn()
{
	return false;
}

bool TCElementBase::clearOver()
{
	runAction(CCRemoveSelf::create(true));
	return TRUE;
}

bool TCElementBase::canClear()
{
	return true;
}

bool TCElementBase::canMove()
{
	return true;
}

