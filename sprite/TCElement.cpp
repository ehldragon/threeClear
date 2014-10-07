#include "TCElement.h"
#include "../CJCImgConfig.h"
#include "../ThreeClearConstants.h"

TCElement::TCElement():m_superType(0),m_type(0)
{

}

TCElement::~TCElement()
{

}

TCElement* TCElement::create()
{
	TCElement *elementSprite = create(1);
	return elementSprite;
}

TCElement* TCElement::create(int type)
{
	TCElement *elementSprite = new TCElement();
	elementSprite->m_type = type;
	const char *fileName = NULL;
	if(type == 1)
	{
		fileName = IMG_ELEMENT1;
	}
	else
	{
		fileName = IMG_ELEMENT2;
	}
	if (elementSprite && elementSprite->initWithFile(fileName))
	{
		elementSprite->autorelease();
		return elementSprite;
	}
	CC_SAFE_DELETE(elementSprite);
	return NULL;
}

bool TCElement::init()
{
	if(!TCElementBase::init()){
		return false;
	}

	return true;
}

int TCElement::getClearType()
{
	return m_type;
}

bool TCElement::clear()
{
	return false;
}

bool TCElement::isTypeEqualTo(TCElementBase *element)
{
	if(m_type == TILE_ELEMENT_BOMB){
		return true;
	}
	
	TCElementBase *clearElement = element->getClearElement();
	if(m_type == clearElement->getClearType()){
		return true;
	}
	return false;
}
