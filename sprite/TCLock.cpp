#include "TCLock.h"



TCLock::TCLock()
{

}

TCLock::~TCLock()
{

}

bool TCLock::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

bool TCLock::clear()
{
	return false;
}

bool TCLock::allowMoveIn()
{
	return true;
}

bool TCLock::canMove()
{
	return false;
}