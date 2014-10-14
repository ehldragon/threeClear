#include "SingleCrossClear.h"
#include "SimpleClear.h"

CCArray* SingleCrossClear::scanClearTiles(TCTile *tileSrc, TCTile *tileDst)
{
	if(tileSrc == NULL || tileDst == NULL || matrix == NULL){
		return NULL;
	}

	//先要执行SimpleClear消除操作,找出有普通三连消除的点
	SimpleClear *simpleAlgorithm = SimpleClear::create();
	simpleAlgorithm->setMatrix(this->matrix);
	CCArray *clearTilesArray = simpleAlgorithm->scanClearTiles(tileSrc, tileDst);
	if(!clearTilesArray){
		clearTilesArray = CCArray::create();
	}
	
	int superType1 = tileSrc->getClearElement()->getSuperClearType();
	int superType2 = tileDst->getClearElement()->getSuperClearType();

	CCArray *lineArray1 = scan(tileSrc);
	CCArray *lineArray2 = scan(tileDst);
	if(lineArray1 != NULL){
		this->addArrayToArray(lineArray1, clearTilesArray);
	}
	if(lineArray2 != NULL){
		this->addArrayToArray(lineArray2, clearTilesArray);
	}

	if(clearTilesArray->count() == 0){
		return NULL;
	}

	//还要进行一次递归扫描炸弹的操作
	this->scanSuperTiles(clearTilesArray);
	return clearTilesArray;
}

CCArray* SingleCrossClear::scan(TCTile *triggerTile)
{
	CCArray *array = CCArray::create();
	int superType = triggerTile->getClearElement()->getSuperClearType();
	if(superType == TILE_SUPER_ELEMENT_ROW){
		array = this->getMatrixScale(triggerTile->getRow(), triggerTile->getRow(), 0, MAP_COL_COUNT);
	}
	else if(superType == TILE_SUPER_ELEMENT_COLUMN){
		array = this->getMatrixScale(0, MAP_COL_COUNT,triggerTile->getCol(), triggerTile->getCol());
	}
	if(array->count() == 0){
		return NULL;
	}
	return array;
}
