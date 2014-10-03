#include "TCStone.h"

TCStone::TCStone()
{

}

TCStone::~TCStone()
{

}

bool TCStone::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

bool TCStone::clear()
{
	return false;
}

