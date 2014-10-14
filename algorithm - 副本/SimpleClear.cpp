#include "SimpleClear.h"

CCArray* SimpleClear::scan(TCTile *triggerTile)
{
	if(triggerTile == NULL || matrix == NULL){
		return NULL;
	}

	CCArray *clearTileArray = CCArray::create();
	//遍历从触发点开始，以该点为中心，找到5x5矩阵中是否有可被消除的点。
	/*扫描行，将符合条件的瓦块挑选出来*/
	CCArray *rowClearArray = scanRowWith(triggerTile);
	if(rowClearArray != NULL){
		addArrayToArray(rowClearArray, clearTileArray);
	}

	/*扫描列，将符合条件的瓦块挑选出来*/
	CCArray *colClearArray = scanColWith(triggerTile);
	if(colClearArray != NULL){
		addArrayToArray(colClearArray, clearTileArray);
	}

	if(clearTileArray->count() == 0)
	{
		return NULL;
	}
	return clearTileArray;
}

CCArray* SimpleClear::scanClearTiles(TCTile *triggerTile)
{
	CCArray *clearTileArray = scan(triggerTile);
	if(clearTileArray->count() == 0){
		return NULL;
	}

	//还要进行一次递归扫描炸弹的操作
	this->scanSuperTiles(clearTileArray);
	return clearTileArray;
}

CCArray* SimpleClear::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	if(tileSrc == NULL || tileDst == NULL || matrix == NULL){
		return NULL;
	}
	
	CCArray *clearTileArray = CCArray::create();
	CCArray *clearArray1 = scan(tileSrc);
	CCArray *clearArray2 = scan(tileDst);

	if(clearArray1 != NULL){
		clearTileArray->addObjectsFromArray(clearArray1);
	}
	if(clearArray2 != NULL){
		clearTileArray->addObjectsFromArray(clearArray2);
	}
	
	if(clearTileArray->count() == 0)
	{
		return NULL;
	}
	//还要进行一次递归扫描炸弹的操作
	this->scanSuperTiles(clearTileArray);
	return clearTileArray;
}

CCArray *SimpleClear::scanRowWith(TCTile *triggerTile)
{
	CCArray *array = CCArray::createWithObject(triggerTile);
	int row = triggerTile->getRow();
	int col = triggerTile->getCol();

	/*查看左边的第一个*/
	if(isTypeSameWith(row, col-1, triggerTile))
	{
		TCTile *leftTile1 = matrix[row][col-1];
		array->addObject(leftTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row, col-2, triggerTile))
		{
			TCTile *leftTile2 = matrix[row][col-2];
			array->addObject(leftTile2);
		}
	}
	/*查看右边的第一个*/
	if(isTypeSameWith(row, col+1, triggerTile))
	{
		TCTile *rightTile1 = matrix[row][col+1];
		array->addObject(rightTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row, col+2, triggerTile))
		{
			TCTile *rightTile2 = matrix[row][col+2];
			array->addObject(rightTile2);
		}
	}
	//如果小于3个相连，说明没有可消除的瓦块
	if(array->count() <3){
		return NULL;
	}
	return array;
}

CCArray *SimpleClear::scanColWith(TCTile *triggerTile)
{
 	CCArray *array = CCArray::createWithObject(triggerTile);
	int row = triggerTile->getRow();
	int col = triggerTile->getCol();

	/*查看上边边的第一个*/
	if(isTypeSameWith(row-1, col, triggerTile))
	{
		TCTile *upTile1 = matrix[row-1][col];
		array->addObject(upTile1);
		/*再查看上边的第二个*/
		if(isTypeSameWith(row-2, col, triggerTile))
		{
			TCTile *upTile2 = matrix[row-2][col];
			array->addObject(upTile2);
		}
	}
// 	/*查看下边边的第一个*/
	if(isTypeSameWith(row+1, col, triggerTile))
	{
		TCTile *downTile1 = matrix[row+1][col];
		array->addObject(downTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row+2, col, triggerTile))
		{
			TCTile *downTile2 = matrix[row+2][col];
			array->addObject(downTile2);
		}
	}
	//如果小于3个相连，说明没有可消除的瓦块
	if(array->count() <3){
		return NULL;
	}
	return array;
}

