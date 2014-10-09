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

TCElementBase* TCElementBase::getMoveElement()
{
	if(!canMove()){
		return NULL;
	}
	if(fillingElement != NULL){
		return fillingElement->getMoveElement();
	}
	return this;
}

void TCElementBase::setMoveElement(TCElementBase *element)
{
	if(!canMove()){
		return ;
	}

	if(fillingElement == NULL){
		setFillingElement(element);
		return;
	}
	//如果是冰块，笼子等可嵌套的，实际移动的是被嵌套的element
	//如果是不可嵌套，直接就要被消除的，则直接进行set
	if(fillingElement->allowMoveIn()){
		fillingElement->setMoveElement(element);
	}
	else{
		setFillingElement(element);
	}
}

TCElementBase* TCElementBase::getClearElement()
{
	if(!canClear()){
		return NULL;
	}
	if(fillingElement != NULL){
		return fillingElement->getClearElement();
	}
	return this;
}

int TCElementBase::getClearType()
{
	return -1;
}


int TCElementBase::getSuperClearType()
{
	return -1;
}


bool TCElementBase::isTypeEqualTo(TCElementBase *element)
{
	return false;
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

void TCElementBase::setClearType(int type)
{

}

void TCElementBase::setSuperClearType(int superType)
{

}



