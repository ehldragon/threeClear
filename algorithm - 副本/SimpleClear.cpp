#include "SimpleClear.h"

CCArray* SimpleClear::scan(TCTile *triggerTile)
{
	if(triggerTile == NULL || matrix == NULL){
		return NULL;
	}

	CCArray *clearTileArray = CCArray::create();
	//�����Ӵ����㿪ʼ���Ըõ�Ϊ���ģ��ҵ�5x5�������Ƿ��пɱ������ĵ㡣
	/*ɨ���У��������������߿���ѡ����*/
	CCArray *rowClearArray = scanRowWith(triggerTile);
	if(rowClearArray != NULL){
		addArrayToArray(rowClearArray, clearTileArray);
	}

	/*ɨ���У��������������߿���ѡ����*/
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

	//��Ҫ����һ�εݹ�ɨ��ը���Ĳ���
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
	//��Ҫ����һ�εݹ�ɨ��ը���Ĳ���
	this->scanSuperTiles(clearTileArray);
	return clearTileArray;
}

CCArray *SimpleClear::scanRowWith(TCTile *triggerTile)
{
	CCArray *array = CCArray::createWithObject(triggerTile);
	int row = triggerTile->getRow();
	int col = triggerTile->getCol();

	/*�鿴��ߵĵ�һ��*/
	if(isTypeSameWith(row, col-1, triggerTile))
	{
		TCTile *leftTile1 = matrix[row][col-1];
		array->addObject(leftTile1);
		/*�ٲ鿴��ߵĵڶ���*/
		if(isTypeSameWith(row, col-2, triggerTile))
		{
			TCTile *leftTile2 = matrix[row][col-2];
			array->addObject(leftTile2);
		}
	}
	/*�鿴�ұߵĵ�һ��*/
	if(isTypeSameWith(row, col+1, triggerTile))
	{
		TCTile *rightTile1 = matrix[row][col+1];
		array->addObject(rightTile1);
		/*�ٲ鿴��ߵĵڶ���*/
		if(isTypeSameWith(row, col+2, triggerTile))
		{
			TCTile *rightTile2 = matrix[row][col+2];
			array->addObject(rightTile2);
		}
	}
	//���С��3��������˵��û�п��������߿�
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

	/*�鿴�ϱ߱ߵĵ�һ��*/
	if(isTypeSameWith(row-1, col, triggerTile))
	{
		TCTile *upTile1 = matrix[row-1][col];
		array->addObject(upTile1);
		/*�ٲ鿴�ϱߵĵڶ���*/
		if(isTypeSameWith(row-2, col, triggerTile))
		{
			TCTile *upTile2 = matrix[row-2][col];
			array->addObject(upTile2);
		}
	}
// 	/*�鿴�±߱ߵĵ�һ��*/
	if(isTypeSameWith(row+1, col, triggerTile))
	{
		TCTile *downTile1 = matrix[row+1][col];
		array->addObject(downTile1);
		/*�ٲ鿴��ߵĵڶ���*/
		if(isTypeSameWith(row+2, col, triggerTile))
		{
			TCTile *downTile2 = matrix[row+2][col];
			array->addObject(downTile2);
		}
	}
	//���С��3��������˵��û�п��������߿�
	if(array->count() <3){
		return NULL;
	}
	return array;
}

