#include "TCElement.h"
#include "../CJCImgConfig.h"
#include "../ThreeClearConstants.h"

TCElement::TCElement():m_superType(TILE_SUPER_ELEMENT_NONE),m_type(0)
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

TCElement* TCElement::create(int type, int superType)
{
	TCElement *elementSprite = TCElement::create(type);
	if(elementSprite){
		elementSprite->m_superType = superType;
	}
	return elementSprite;
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

int TCElement::getSuperClearType()
{
	return m_superType;
} 

bool TCElement::clear()
{
	return false;
}

bool TCElement::isTypeEqualTo(TCElementBase *element)
{
	if(m_superType == TILE_SUPER_ELEMENT_BOMB){
		return true;
	}
	
	TCElementBase *clearElement = element->getClearElement();
	if(m_type == clearElement->getClearType()){
		return true;
	}
	return false;
}

void TCElement::setClearType(int type)
{
	m_type = type;
}

void TCElement::setSuperClearType(int superType)
{
	m_superType = superType;
}