#include "clearAlgorithm.h"

clearAlgorithm::~clearAlgorithm()
{

}

bool clearAlgorithm::init()
{
	return true;
}

CCArray* clearAlgorithm::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	return NULL;
}

CCArray* clearAlgorithm::scanClearTiles(TCTile *triggerTile)
{
	return NULL;
}


bool clearAlgorithm::canTileClear(int row, int col)
{
	if(!isValidRowCol(row, col)){
		return false;// �����������Ϸ�������
	}
	TCTile* tile = matrix[row][col];
	if(tile != NULL){
		return tile->canClear();
	}
	return false;
}

bool clearAlgorithm::isValidRowCol(int row, int col){
	if(row<0 || row>=MAP_ROW_COUNT){
		return false;
	}
	if(col<0 || col>=MAP_COL_COUNT){
		return false;
	}
	return true;
}

bool clearAlgorithm::isTypeSameWith(int row, int col, TCTile *originalTile)
{
	if(!canTileClear(row, col)){
		return false;
	}

	TCElementBase *originalElement = originalTile->getClearElement();
	TCTile *tile = matrix[row][col];
	TCElementBase *tileElement = tile->getClearElement();

	return tileElement->isTypeEqualTo(originalElement) ;
}

void clearAlgorithm::setMatrix(MatrixPtr newMatrix)
{
	matrix = newMatrix;
}

void clearAlgorithm::addTileToArray(CCArray *array, CCObject *obj)
{
	if(!array->containsObject(obj))
	{
		array->addObject(obj);
	}
}

void clearAlgorithm::addArrayToArray(CCArray *srcArray,CCArray *dstArray)
{
	for(unsigned int index=0; index < srcArray->count(); index++)
	{
		CCObject *obj = srcArray->objectAtIndex(index);
		addTileToArray(dstArray, obj);
	}
}

void clearAlgorithm::scanSuperTiles(CCArray *clearTilesArray)
{
	if(!clearTilesArray){
		return ;
	}
	/*������ĵ�Ϊ��ʼ״̬ɨ�裬����clearTilesArray��ɨ������л��������ݣ�������Ҫ�Ȱѳ�ʼ�ĵ���ȡ�������б���*/
	CCArray *array = CCArray::create();
	array->addObjectsFromArray(clearTilesArray);
	for(unsigned int index = 0; index < array->count(); index++)
	{
		TCTile *tile = (TCTile *)array->objectAtIndex(index);
		scanSuperTile(tile, clearTilesArray);
	}
}

void clearAlgorithm::scanSuperTile(TCTile *startTile, CCArray *rootArray)
{
	if(!startTile || !rootArray){
		return ;
	}
	addTileToArray(rootArray, startTile);
	CCArray *relates = getRelates(startTile, rootArray);
	if(!relates){
		return ;
	}
	//�ҳ��������߿���ٰ����ݹ�ɨ��
	for(unsigned int index = 0; index < relates->count(); index++)
	{
		TCTile *tile = (TCTile *)relates->objectAtIndex(index);
		scanSuperTile(tile, rootArray);
	}
}

CCArray* clearAlgorithm::getRelates(TCTile *tile, CCArray *rootArray)
{
	TCElementBase *element = tile->getClearElement();
	int superClearType = element->getSuperClearType();
	//������߿�û������Ч����ֱ�ӷ���
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

CCArray* clearAlgorithm::getMatrixScale(int rowBegin, int rowEnd, int colBegin, int colEnd, CCArray *rootArray)
{
	CCArray *array = CCArray::create();
	for(int row = rowBegin; row <= rowEnd; row++)
	{
		for(int col = colBegin; col <= colEnd; col++)
		{
			if(!canTileClear(row, col)){
				continue;
			}
			//��ֹ�ػ��ڵݹ�����г���
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

CCArray* clearAlgorithm::getMatrixSurrond(int rowBegin, int colBegin, CCArray *rootArray)
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
			//��ֹ�ػ��ڵݹ�����г���
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

