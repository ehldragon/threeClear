#include "TCElement.h"

TCElement::TCElement()
{

}

TCElement::~TCElement()
{

}

bool TCElement::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

int TCElement::getElementValue()
{
	return m_element;
}

bool TCElement::clear()
{
	return false;
}
