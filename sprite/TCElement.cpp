#include "TCElement.h"
#include "../CJCImgConfig.h"

TCElement::TCElement():m_state(0),m_type(0)
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
