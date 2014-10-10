#include "ruinClear.h"

CCArray* RuinClear::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	if(tileSrc == NULL || tileDst == NULL || matrix == NULL){
		return NULL;
	}

	CCArray *array = CCArray::create();
	for(unsigned int row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(unsigned int column = 0; column < MAP_COL_COUNT; row++)
		{
			if(!canTileClear(row, column))
			{
				continue;
			}
			TCTile *tile = matrix[row][column];
			array->addObject(tile);
		}
	}

	if(array->count() == 0){
		return NULL;
	}
	return array;
}

