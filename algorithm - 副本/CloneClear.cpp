#include "CloneClear.h"

CCArray* CloneClear::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	if(tileSrc == NULL || tileDst == NULL || matrix == NULL){
		return NULL;
	}

	int superType1 = tileSrc->getClearElement()->getSuperClearType();
	int superType2 = tileDst->getClearElement()->getSuperClearType();
	TCTile *bombTile = NULL;
	TCTile *cloneTile = NULL;
	CCArray *clearTilesArray = CCArray::create();
	//�ҳ�˭������ը��
	if(superType1 == TILE_SUPER_ELEMENT_BOMB){
		bombTile = tileSrc;
		cloneTile = tileDst;
	}
	else{
		bombTile = tileDst;
		cloneTile = tileSrc;
	}

	clearTilesArray->addObject(bombTile);
	for(unsigned int row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(unsigned int column = 0; column < MAP_COL_COUNT; column++)
		{
			if(!this->isTypeSameWith(row, column, cloneTile)){
				continue;
			}
			TCTile *tile = matrix[row][column];
			clearTilesArray->addObject(tile);
		}
	}

	if(clearTilesArray->count() == 0)
	{
		return NULL;
	}
	//��Ҫ����һ�εݹ�ɨ��ը���Ĳ���
	this->scanSuperTiles(clearTilesArray);
	return clearTilesArray;
}


