#include "ThreeClearElement.h"

ThreeClearElement::ThreeClearElement()
{

}

ThreeClearElement::~ThreeClearElement()
{

}

bool ThreeClearElement::init()
{
	if(!ThreeClearSpriteBase::init()){
		return false;
	}

	return true;
}

int ThreeClearElement::getElement()
{
	return m_element;
}

bool ThreeClearElement::clear()
{
	return false;
}
