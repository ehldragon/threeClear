#include "ClearFactory.h"
#include "SimpleClear.h"
#include "RuinClear.h"
#include "SingleCrossClear.h"
#include "MultiCrossClear.h"

static bool isHasType(TCElementBase *element1, TCElementBase *element2, int superType1, int superType2);
static ClearFactory *s_sharedFactory;
ClearFactory* ClearFactory::sharedClearFactory()
{
	if (!s_sharedFactory)
	{
		s_sharedFactory = new ClearFactory();
		s_sharedFactory->init();
	}
	return s_sharedFactory;
}

bool ClearFactory::init()
{
	m_simpleAlgorithm = SimpleClear::create();
	m_simpleAlgorithm->retain();

	m_ruinAlgorithm = RuinClear::create();
	m_ruinAlgorithm->retain();

	return true;
}

/*ע���м򵥹涨һ��
��ͨelement �� A
���������ɵ�Ϊ�� B
�����������ɵ�Ϊ��C
���������ɵ�Ϊ:D
*/
ClearAlgorithm * ClearFactory::getAlgoritm(TCTile *tile1, TCTile *tile2, MatrixPtr matrix)
{
	TCElementBase *element1 = tile1->getClearElement();
	TCElementBase *element2 = tile2->getClearElement();
	
	if(!element1 || !element2){
		return NULL;
	}

	ClearAlgorithm *algorithm = NULL;
	//A���A��A���B��A���C
	if(isHasType(element1, element2, TILE_SUPER_ELEMENT_NONE, TILE_SUPER_ELEMENT_NONE) ||
		isHasType(element1, element2, TILE_SUPER_ELEMENT_NONE, TILE_SUPER_ELEMENT_ROW) ||
		isHasType(element1, element2, TILE_SUPER_ELEMENT_NONE, TILE_SUPER_ELEMENT_COLUMN) ||
		isHasType(element1, element2, TILE_SUPER_ELEMENT_NONE, TILE_SUPER_ELEMENT_SURROUND))
	{
		algorithm = m_simpleAlgorithm;
	}
	else if(isHasType(element1, element2, TILE_SUPER_ELEMENT_NONE, TILE_SUPER_ELEMENT_BOMB))
	{
		//A���D
	}
	else if(isHasType(element1, element2, TILE_SUPER_ELEMENT_ROW, TILE_SUPER_ELEMENT_ROW) ||
			isHasType(element1, element2, TILE_SUPER_ELEMENT_ROW, TILE_SUPER_ELEMENT_COLUMN) ||
			isHasType(element1, element2, TILE_SUPER_ELEMENT_COLUMN, TILE_SUPER_ELEMENT_COLUMN))
	{
		//B���B
	}
	else if(isHasType(element1, element2, TILE_SUPER_ELEMENT_ROW, TILE_SUPER_ELEMENT_SURROUND) ||
			isHasType(element1, element2, TILE_SUPER_ELEMENT_COLUMN, TILE_SUPER_ELEMENT_SURROUND))
	{
		//B���C
	}
	else if(isHasType(element1, element2, TILE_SUPER_ELEMENT_ROW, TILE_SUPER_ELEMENT_BOMB) ||
		isHasType(element1, element2, TILE_SUPER_ELEMENT_COLUMN, TILE_SUPER_ELEMENT_BOMB) || 
		isHasType(element1, element2, TILE_SUPER_ELEMENT_SURROUND, TILE_SUPER_ELEMENT_BOMB))
	{
		//B���D, C���D

	}
	else if(isHasType(element1, element2, TILE_SUPER_ELEMENT_BOMB, TILE_SUPER_ELEMENT_BOMB))
	{
		//D���D
		return m_ruinAlgorithm;
	}

	if(algorithm != NULL){
		algorithm->setMatrix(matrix);
	}
	return algorithm;
}

ClearAlgorithm * ClearFactory::getDefaultAlgoritm(MatrixPtr matrix)
{
	if(m_simpleAlgorithm != NULL){
		m_simpleAlgorithm->setMatrix(matrix);
	}
	return m_simpleAlgorithm;
}


static bool isHasType(TCElementBase *element1, TCElementBase *element2, int superType1, int superType2)
{
	if(element1->getSuperClearType() == superType1 && element2->getSuperClearType() == superType2){
		return true;
	}
	else if(element1->getSuperClearType() == superType2 && element2->getSuperClearType() == superType1){
		return true;
	}
	return false;
}


