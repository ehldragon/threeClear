#include "ClearAlgorithm.h"

ClearAlgorithm::ClearAlgorithm():matrix(NULL)
{
	
}

ClearAlgorithm::~ClearAlgorithm()
{

}

bool ClearAlgorithm::init()
{
	return true;
}

CCArray* ClearAlgorithm::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	return NULL;
}

CCArray* ClearAlgorithm::scanClearTiles(TCTile *triggerTile)
{
	return NULL;
}

bool ClearAlgorithm::canTileClear(int row, int col)
{
	if(!isValidRowCol(row, col)){
		return false;// 行列索引不合法，返回
	}
	TCTile* tile = matrix[row][col];
	if(tile != NULL){
		return tile->canClear();
	}
	return false;
}

bool ClearAlgorithm::isValidRowCol(int row, int col){
	if(row<0 || row>=MAP_ROW_COUNT){
		return false;
	}
	if(col<0 || col>=MAP_COL_COUNT){
		return false;
	}
	return true;
}

bool ClearAlgorithm::isTypeSameWith(int row, int col, TCTile *originalTile)
{
	if(!canTileClear(row, col)){
		return false;
	}

	TCElementBase *originalElement = originalTile->getClearElement();
	TCTile *tile = matrix[row][col];
	TCElementBase *tileElement = tile->getClearElement();

	return tileElement->isTypeEqualTo(originalElement) ;
}

void ClearAlgorithm::setMatrix(MatrixPtr newMatrix)
{
	matrix = newMatrix;
}

void ClearAlgorithm::addTileToArray(CCArray *array, CCObject *obj)
{
	if(!array->containsObject(obj))
	{
		array->addObject(obj);
	}
}

void ClearAlgorithm::addArrayToArray(CCArray *srcArray,CCArray *dstArray)
{
	for(unsigned int index=0; index < srcArray->count(); index++)
	{
		CCObject *obj = srcArray->objectAtIndex(index);
		addTileToArray(dstArray, obj);
	}
}

void ClearAlgorithm::scanSuperTiles(CCArray *clearTilesArray)
{
	if(!clearTilesArray){
		return ;
	}
	/*以最初的点为初始状态扫描，由于clearTilesArray在扫描过程中会增加内容，所以需要先把初始的点提取出来进行遍历*/
	CCArray *array = CCArray::create();
	array->addObjectsFromArray(clearTilesArray);
	for(unsigned int index = 0; index < array->count(); index++)
	{
		TCTile *tile = (TCTile *)array->objectAtIndex(index);
		scanSuperTile(tile, clearTilesArray);
	}
}

void ClearAlgorithm::scanSuperTile(TCTile *startTile, CCArray *rootArray)
{
	if(!startTile || !rootArray){
		return ;
	}
	addTileToArray(rootArray, startTile);
	CCArray *relates = getRelates(startTile, rootArray);
	if(!relates){
		return ;
	}
	//找出关联的瓦块后，再挨个递归扫描
	for(unsigned int index = 0; index < relates->count(); index++)
	{
		TCTile *tile = (TCTile *)relates->objectAtIndex(index);
		scanSuperTile(tile, rootArray);
	}
}

CCArray* ClearAlgorithm::getRelates(TCTile *tile, CCArray *rootArray)
{
	TCElementBase *element = tile->getClearElement();
	int superClearType = element->getSuperClearType();
	//如果该瓦块没有特殊效果，直接返回
	if(superClearType == TILE_SUPER_ELEMENT_NONE){
		return NULL;
	}

	CCArray *relatesArray = NULL;
	if(superClearType == TILE_SUPER_ELEMENT_ROW)
	{
		return getMatrixScale(tile->getRow(), tile->getRow(), 0, MAP_COL_COUNT, rootArray);
	}
	if(superClearType == TILE_SUPER_ELEMENT_COLUMN)
	{
		return getMatrixScale(0, MAP_COL_COUNT,tile->getCol(), tile->getCol(), rootArray);
	}
	if(superClearType == TILE_SUPER_ELEMENT_SURROUND)
	{
		return getMatrixSurrond(tile->getRow(), tile->getCol(), rootArray);
	}

	return NULL;
}

CCArray* ClearAlgorithm::getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd, CCArray *rootArray)
{
	CCArray *array = CCArray::create();
	for(int row = rowBegin; row <= rowEnd; row++)
	{
		for(int col = colBegin; col <= colEnd; col++)
		{
			if(!canTileClear(row, col)){
				continue;
			}
			//防止回环在递归调用中出现
			if(!rootArray->containsObject(matrix[row][col]))
			{
				array->addObject(matrix[row][col]);
			}
		}
	}

	if(array->count() == 0){
		return NULL;
	}
	return array;
}

CCArray* ClearAlgorithm::getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd)
{
	CCArray *array = CCArray::create();
	for(int row = rowBegin; row <= rowEnd; row++)
	{
		for(int col = colBegin; col <= colEnd; col++)
		{
			if(!canTileClear(row, col)){
				continue;
			}
			array->addObject(matrix[row][col]);
		}
	}

	if(array->count() == 0){
		return NULL;
	}
	return array;
}

CCArray* ClearAlgorithm::getMatrixSurrond(int rowBegin, int colBegin, CCArray *rootArray)
{
	CCArray *array = CCArray::create();
	int scale = 2;
	int maxValue = 5;// 2*scale+1
	for(int rowStep = -2; rowStep <= 2; rowStep++)
	{
		int colStepValue = (maxValue-2*abs(rowStep))/2;
		for(int colStep = -colStepValue; colStep <= colStepValue; colStep++)
		{
			int row = rowBegin + rowStep;
			int col = colBegin + colStep;
			if(!canTileClear(row, col)){
				continue;
			}
			//防止回环在递归调用中出现
			if(!rootArray->containsObject(matrix[row][col]))
			{
				array->addObject(matrix[row][col]);
			}
		}
	}

	if(array->count() == 0){
		return NULL;
	}
	return array;
}

