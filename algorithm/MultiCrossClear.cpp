#include "MultiCrossClear.h"
#include "SimpleClear.h"

CCArray* MultiCrossClear::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	if(tileSrc == NULL || tileDst == NULL || matrix == NULL){
		return NULL;
	}

	//��Ҫִ��SimpleClear��������,�ҳ�����ͨ���������ĵ�
	SimpleClear *simpleAlgorithm = SimpleClear::create();
	simpleAlgorithm->setMatrix(this->matrix);
	CCArray *clearTilesArray = simpleAlgorithm->scanClearTiles(tileSrc, tileDst);
	if(!clearTilesArray){
		clearTilesArray = CCArray::create();
	}
	//ɨ��������ը�������ĵ�
	CCArray *array = scan(tileSrc, tileDst);
	if(array != NULL){
		this->addArrayToArray(array, clearTilesArray);
	}

	if(clearTilesArray->count() == 0){
		return NULL;
	}

	//��Ҫ����һ�εݹ�ɨ��ը���Ĳ���
	this->scanSuperTiles(clearTilesArray);
	return clearTilesArray;
}

CCArray* MultiCrossClear::scan(TCTile *tileSrc, TCTile *tileDst)
{
	int superType1 = tileSrc->getClearElement()->getSuperClearType();
	int superType2 = tileDst->getClearElement()->getSuperClearType();

	int rowBegin=0, rowEnd=0, colBegin=0, colEnd=0;
	if(superType1 == superType2){  //��ΪTILE_SUPER_ELEMENT_SURROUND���ͣ�����������ը��
		if(tileSrc->getRow() == tileDst->getRow()){
			colBegin = MIN(tileSrc->getCol(), tileDst->getCol()) - 2;
			colEnd = MAX(tileSrc->getCol(), tileDst->getCol()) + 2;
			rowBegin = tileSrc->getRow() - 2;
			rowEnd = tileSrc->getRow() + 2;
		}
		else if(tileSrc->getCol() == tileDst->getCol()){
			rowBegin = MIN(tileSrc->getRow(), tileDst->getRow()) - 2;
			rowEnd = MAX(tileSrc->getRow(), tileDst->getRow()) + 2;
			colBegin = tileSrc->getCol() - 2;
			colEnd = tileSrc->getCol() + 2;
		}
	}
 	else {     //һ��������ը�����һ������ը��
		TCTile *surrondBomb = NULL, *lineBomb = NULL;
		//���ҳ�˭��������ը��
 		if(superType1 == TILE_SUPER_ELEMENT_SURROUND)	
		{
			surrondBomb = tileSrc;
			lineBomb = tileDst;
		}
		else if(superType2 = TILE_SUPER_ELEMENT_SURROUND)
		{
			surrondBomb = tileDst;
			lineBomb = tileSrc;
		}
		//���ж�����ը��������
		if(lineBomb->getClearElement()->getSuperClearType() == TILE_SUPER_ELEMENT_ROW)
		{
			rowBegin = surrondBomb->getRow() - 2;
			rowEnd = surrondBomb->getRow() + 2;
			colBegin = 0;
			colEnd = MAP_COL_COUNT;
		}
		else if(lineBomb->getClearElement()->getSuperClearType() == TILE_SUPER_ELEMENT_COLUMN)
		{
			rowBegin = 0;
			rowEnd = MAP_ROW_COUNT;
			colBegin = surrondBomb->getCol() - 2;
			colEnd = surrondBomb->getCol() + 2;
		}
 	}

	return this->getMatrixScale(rowBegin, rowEnd, colBegin, colEnd);
}

