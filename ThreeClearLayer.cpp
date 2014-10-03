#include "ThreeClearLayer.h"

ThreeClearLayer::ThreeClearLayer()
{

}

ThreeClearLayer::~ThreeClearLayer()
{

}

bool ThreeClearLayer::init()
{
	if(!CCLayer::init()){
		return false;
	}

	return true;
}