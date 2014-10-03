#include "TCIce.h"

TCIce::TCIce()
:m_times(1)
{

}

TCIce::~TCIce()
{

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
