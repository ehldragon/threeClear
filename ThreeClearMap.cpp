#include "ThreeClearMap.h"
#include "sprite/TCElementSpritesState.h"
#include "algorithm/clearFactory.h"

ThreeClearMap::ThreeClearMap()
{
	
}

ThreeClearMap::~ThreeClearMap()
{
	CC_SAFE_RELEASE_NULL(m_clearTileArray);
	CC_SAFE_RELEASE_NULL(m_triggerTileArray);
}

bool ThreeClearMap::init(){
	if(!CCLayer::init()){
		return false;
	}
 	testInit();
 	mapInit();
	setTouchEnabled(true);
	return true;
}

bool ThreeClearMap::testInit()
{
	for(int r=0;r<MAP_ROW_COUNT;r++){
		for(int c=0;c<MAP_COL_COUNT;c++){
			TCTile* tile = TCTile::create();
			m_map[r][c] = tile;
			tile->setMatrix(r, c);
			if(0 == r){
				tile->setShow(TILE_SHOW_NONE);
				continue;
			}
			tile->setShow(TILE_SHOW_DEFAULT);

// 			TCElementBase *element = NULL;
//  			if(1 == c){
//  				element = TCIce::create();
//  			}
// 			if(2 == c){
// 				element = TCStone::create();
// 			}
// 			if(3 == c){
// 				element = TCStone::create();
// 			}
// 			if(4 == c){
// 				element = TCIce::create(2);
// 			}
// 	
// 			if(element != NULL)
// 			{
// 				tile->setElement(element);
// 			}
		}
	}

	TCTile *tile = m_map[1][2];
	tile->setElement(TCElement::create());

	tile = m_map[1][6];
	tile->setElement(TCElement::create());

	tile = m_map[1][7];
	tile->setElement(TCElement::create());

	tile = m_map[1][8];
	tile->setElement(TCElement::create());


	tile = m_map[2][1];
	tile->setElement(TCElement::create(TILE_ELEMENT_1, TILE_SUPER_ELEMENT_ROW));

	tile = m_map[2][2];
	tile->setElement(TCElement::create(2));

	tile = m_map[2][3];
	tile->setElement(TCElement::create());

	tile = m_map[2][4];
	tile->setElement(TCElement::create());

	tile = m_map[2][7];
	tile->setElement(TCElement::create(TILE_ELEMENT_2, TILE_SUPER_ELEMENT_SURROUND));

	tile = m_map[2][8];
	tile->setElement(TCElement::create(2));

	tile = m_map[3][2];
	tile->setElement(TCElement::create());
	tile = m_map[3][3];
	tile->setElement(TCElement::create());

	tile = m_map[3][6];
	tile->setElement(TCElement::create());
	tile = m_map[3][7];
	tile->setElement(TCElement::create());
	tile = m_map[3][8];
	tile->setElement(TCElement::create());

	tile = m_map[4][2];
	tile->setElement(TCElement::create());
	tile = m_map[4][3];
	tile->setElement(TCElement::create());
	tile = m_map[4][7];
	tile->setElement(TCElement::create());

	tile = m_map[6][7];
	tile->setElement(TCElement::create());
	tile = m_map[7][7];
	tile->setElement(TCElement::create(TILE_ELEMENT_1, TILE_SUPER_ELEMENT_ROW));
	tile = m_map[7][2];
	tile->setElement(TCElement::create(TILE_ELEMENT_2, TILE_SUPER_ELEMENT_COLUMN));

	return true;
}
// 
// 
bool ThreeClearMap::mapInit(){
	if(!m_map){
		return false;
	}

	m_clearTileArray = CCArray::create();
	m_triggerTileArray = CCArray::create();
	m_clearTileArray->retain();
	m_triggerTileArray->retain();

	for(int r = 0;r < MAP_ROW_COUNT; r++){
		for(int c = 0; c < MAP_COL_COUNT; c++){
			TCTile* tile = m_map[r][c];
			CCPoint point = getPoint(r, c);
			//布局瓦块和element
			tile->setPosition(point);
			addChild(tile, MAP_ZORDER_SHOW);
			TCElementBase *element = tile->getElement();
			if(element != NULL)
			{
				element->setPosition(point);
				addChild(element, MAP_ZORDER_ELEMENT);
			}
		}
	}
	return true;
}

bool ThreeClearMap::checkMoveDown()
{
	return false;
}

bool ThreeClearMap::checkClear()
{
	return false;
}

cocos2d::CCPoint ThreeClearMap::getPoint(int row, int col)
{
	float x = MAP_START_X + col * TILE_WIDTH + TILE_WIDTH/2;
	float y = MAP_START_Y + (MAP_ROW_COUNT-row) * TILE_HEIGHT + TILE_HEIGHT/2;
	CCPoint p = CCPointMake(x, y);
	return p;
}

void ThreeClearMap::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	m_selectedPoint = touch->getLocation();
	int col = (m_selectedPoint.x - MAP_START_X)/TILE_WIDTH;
	int row = (m_selectedPoint.y - MAP_START_Y)/TILE_HEIGHT;
	m_selectedRow = MAP_ROW_COUNT - row;
	m_selectedCol = col;
	if(!canTileSwap(m_selectedRow,m_selectedCol)){
		m_selectedRow = -1;
		m_selectedCol = -1;
	}
}

void ThreeClearMap::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	if(!isValidRowCol(m_selectedRow,m_selectedCol)){
		return;// 不合法的选中行列索引
	}
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint p = touch->getLocation();
	float offsetX = p.x - m_selectedPoint.x;
	float offsetY = p.y - m_selectedPoint.y;

	// 横向交换
	if(abs(offsetX)>SWAP_OFFSET_LIMIT && abs(offsetX) > abs(offsetY)){
		int dstRow = -1;
		int dstCol = -1;
		// 向右交换
		if(offsetX>0){
			dstRow = m_selectedRow;
			dstCol = m_selectedCol + 1;
		}
		else{ // 向左交换
			dstRow = m_selectedRow;
			dstCol = m_selectedCol - 1;
		}

		if(!canTileSwap(dstRow,dstCol)){
			return;// 目标行列索引不合法，返回
		}
 
		swap(m_selectedRow, m_selectedCol, dstRow, dstCol);
		m_selectedRow = -1;
		m_selectedCol = -1;
		return;
	}

	// 竖向交换
	if(abs(offsetY)>SWAP_OFFSET_LIMIT && abs(offsetY) > abs(offsetX)){
		int dstRow = -1;
		int dstCol = -1;
		// 向下交换
		if(offsetY>0){
			dstRow = m_selectedRow - 1;
			dstCol = m_selectedCol;
		}
		else{ // 向上交换
			dstRow = m_selectedRow + 1;
			dstCol = m_selectedCol;
		}
		
		if(!canTileSwap(dstRow,dstCol)){
			return;// 目标行列索引不合法，返回
		}
		swap(m_selectedRow, m_selectedCol, dstRow, dstCol);
		m_selectedRow = -1;
		m_selectedCol = -1;
		return;
	}
}

void ThreeClearMap::swap(int srcRow, int srcCol, int dstRow, int dstCol){
	if(!canTileSwap(srcRow,srcCol)){
		return;// 行列索引不合法，或者瓦块不符合要求，返回
	}
	if(!canTileSwap(dstRow,dstCol)){
		return;
	}
	TCTile* srcTile = m_map[srcRow][srcCol];
	TCTile* dstTile = m_map[dstRow][dstCol];
	/*记录一下调换的瓦块，用于后续还原reverse*/
	m_srcSwapTile = srcTile;
	m_dstSwapTile = dstTile;
	
	/*将两个交换的瓦块作为触发点保存，用于后续扫描消除*/
	m_triggerTileArray->addObject(srcTile);
	m_triggerTileArray->addObject(dstTile);
	
	//获取每个瓦块中，真正能够被提取出来移动交换的element
	TCElementBase *srcElement = srcTile->getMoveElement();
	TCElementBase *dstElement = dstTile->getMoveElement();

	CCPoint srcPoint = getPoint(srcTile->getRow(), srcTile->getCol());
	CCPoint dstPoint = getPoint(dstTile->getRow(), dstTile->getCol());
	CCAction *swapElementAction = CCCallFunc::create(this, callfunc_selector(ThreeClearMap::swapElement));
	CCAction *clearTilesAction = CCCallFunc::create(this, callfunc_selector(ThreeClearMap::clearTilesAfterSwap));

	srcElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, dstPoint),
//		CCMoveTo::create(0.2f, srcPoint),
		swapElementAction,
		clearTilesAction,
		NULL));
	dstElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, srcPoint),
//		CCMoveTo::create(0.2f, dstPoint),
		NULL));
}

void ThreeClearMap::reverse(int srcRow, int srcCol, int dstRow, int dstCol){
	if(!canTileSwap(srcRow,srcCol)){
		return;// 行列索引不合法，或者瓦块不符合要求，返回
	}
	if(!canTileSwap(dstRow,dstCol)){
		return;
	}
	TCTile* srcTile = m_map[srcRow][srcCol];
	TCTile* dstTile = m_map[dstRow][dstCol];

	m_srcSwapTile = srcTile;
	m_dstSwapTile = dstTile;

	//获取每个瓦块中，真正能够被提取出来移动交换的element
	TCElementBase *srcElement = srcTile->getMoveElement();
	TCElementBase *dstElement = dstTile->getMoveElement();

	CCPoint srcPoint = getPoint(srcTile->getRow(), srcTile->getCol());
	CCPoint dstPoint = getPoint(dstTile->getRow(), dstTile->getCol());
	CCAction *swapElementAction = CCCallFunc::create(this, callfunc_selector(ThreeClearMap::swapElement));

	srcElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, dstPoint),
		//		CCMoveTo::create(0.2f, srcPoint),
		swapElementAction,
		NULL));
	dstElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, srcPoint),
		//		CCMoveTo::create(0.2f, dstPoint),
		NULL));
}

void ThreeClearMap::swapElement()
{
	if(m_srcSwapTile == NULL || m_dstSwapTile == NULL)
	{
		return;
	}
	TCElementBase *tmpElement = m_srcSwapTile->getMoveElement();
	m_srcSwapTile->setMoveElement(m_dstSwapTile->getMoveElement());
	m_dstSwapTile->setMoveElement(tmpElement);

	TCTile *tmpTile = m_srcSwapTile;
	m_srcSwapTile = m_dstSwapTile;
	m_dstSwapTile = tmpTile;
}

bool ThreeClearMap::isValidRowCol(int row, int col){
	if(row<0 || row>=MAP_ROW_COUNT){
		return false;
	}
	if(col<0 || col>=MAP_COL_COUNT){
		return false;
	}
	return true;
}

bool ThreeClearMap::canTileSwap(int row, int col)
{
	if(!isValidRowCol(row, col)){
		return false;// 行列索引不合法，返回
	}
	TCTile* tile = m_map[row][col];
	if(tile != NULL){
		return tile->canMove();
	}
	return false;
}


bool ThreeClearMap::canTileClear(int row, int col)
{
	if(!isValidRowCol(row, col)){
		return false;// 行列索引不合法，返回
	}
	TCTile* tile = m_map[row][col];
	if(tile != NULL){
		return tile->canClear();
	}
	return false;
}

bool ThreeClearMap::scanClearAfterSwap()
{
	if(m_srcSwapTile == NULL || m_dstSwapTile == NULL){
		return false;
	}
	//获取相关算法，进行扫描
	clearAlgorithm *algorithm = clearFactory::sharedClearFactory()->getAlgoritm(m_srcSwapTile, m_dstSwapTile, m_map);
	CCArray *clearTileArray = algorithm->scanClearTiles(m_srcSwapTile, m_dstSwapTile);
	//没有值说明没有可以被消除的瓦块
	if(clearTileArray == NULL){
		return false;
	}

	clearTileArray->retain();
	m_clearTileArray->release();
	m_clearTileArray = clearTileArray;
	
	//触发点扫描完毕，清空触发点容器
	m_triggerTileArray->removeAllObjects();
	if(m_clearTileArray->count() == 0)
	{
		return false;
	}


	//for testCC
	CCObject *obj = NULL;
	CCARRAY_FOREACH(m_clearTileArray, obj)
	{
		TCTile *tile = (TCTile *)obj;
		CCLOG("[%d][%d]", tile->getRow(), tile->getCol());
	}
	return true;
}

bool ThreeClearMap::scanClearNoSwap()
{
	if(m_triggerTileArray->count() == 0){
		return false;
	}

	clearAlgorithm *algorithm = clearFactory::sharedClearFactory()->getDefaultAlgoritm(m_map);
	//遍历从各个触发点开始，以该点为中心，找到5x5矩阵中是否有可被消除的点。
	for(unsigned int index = 0; index < m_triggerTileArray->count(); index++)
	{
		TCTile *triggerTile = (TCTile *)m_triggerTileArray->objectAtIndex(index);
		CCArray *clearTileArray = algorithm->scanClearTiles(triggerTile);
		if(clearTileArray != NULL){
			addArrayToArray(clearTileArray, m_clearTileArray);
		}
	}
	//触发点扫描完毕，清空触发点容器
	m_triggerTileArray->removeAllObjects();
	if(m_clearTileArray->count() == 0)
	{
		return false;
	}
	return true;
}

void ThreeClearMap::clearTilesAfterSwap()
{
	//如果没有需要消除的瓦块，需要将滑动的两个瓦块复原
	if(!scanClearAfterSwap()){
		reverse(m_srcSwapTile->getRow(),
			m_srcSwapTile->getCol(),
			m_dstSwapTile->getRow(),
			m_dstSwapTile->getCol());
		return;
	}
	//TODO:遍历m_clearTileArray，消除瓦块。
	//TODO:将m_clearTileArray内容导入m_triggerTileArray；
	m_clearTileArray->removeAllObjects();
	return ;
}

void ThreeClearMap::clearTilesNoSwap()
{
	//如果没有需要消除的瓦块，直接返回
	if(!scanClearNoSwap()){
		return;
	}
	//TODO:遍历m_clearTileArray，消除瓦块。
	//TODO:将m_clearTileArray内容导入m_triggerTileArray；
	m_clearTileArray->removeAllObjects();
	return ;
}


void ThreeClearMap::addTileToArray(CCArray *array, CCObject *obj)
{
	if(!array->containsObject(obj))
	{
		array->addObject(obj);
	}
}

void ThreeClearMap::addArrayToArray(CCArray *srcArray,CCArray *dstArray)
{
	for(unsigned int index=0; index < srcArray->count(); index++)
	{
		CCObject *obj = srcArray->objectAtIndex(index);
		addTileToArray(dstArray, obj);
	}
}

CCArray *ThreeClearMap::scanRowWith(TCTile *triggerTile)
{
	CCArray *array = CCArray::createWithObject(triggerTile);
	int row = triggerTile->getRow();
	int col = triggerTile->getCol();

	/*查看左边的第一个*/
	if(isTypeSameWith(row, col-1, triggerTile))
	{
		TCTile *leftTile1 = m_map[row][col-1];
		array->addObject(leftTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row, col-2, triggerTile))
		{
			TCTile *leftTile2 = m_map[row][col-2];
			array->addObject(leftTile2);
		}
	}
	/*查看右边的第一个*/
	if(isTypeSameWith(row, col+1, triggerTile))
	{
		TCTile *rightTile1 = m_map[row][col+1];
		array->addObject(rightTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row, col+2, triggerTile))
		{
			TCTile *rightTile2 = m_map[row][col+2];
			array->addObject(rightTile2);
		}
	}
	//如果小于3个相连，说明没有可消除的瓦块
	if(array->count() <3){
		return NULL;
	}
	return array;
}

CCArray *ThreeClearMap::scanColWith(TCTile *triggerTile)
{
	CCArray *array = CCArray::createWithObject(triggerTile);
	int row = triggerTile->getRow();
	int col = triggerTile->getCol();

	/*查看上边边的第一个*/
	if(isTypeSameWith(row-1, col, triggerTile))
	{
		TCTile *upTile1 = m_map[row-1][col];
		array->addObject(upTile1);
		/*再查看上边的第二个*/
		if(isTypeSameWith(row-2, col, triggerTile))
		{
			TCTile *upTile2 = m_map[row-2][col];
			array->addObject(upTile2);
		}
	}
	/*查看下边边的第一个*/
	if(isTypeSameWith(row+1, col, triggerTile))
	{
		TCTile *downTile1 = m_map[row+1][col];
		array->addObject(downTile1);
		/*再查看左边的第二个*/
		if(isTypeSameWith(row+2, col, triggerTile))
		{
			TCTile *downTile2 = m_map[row+2][col];
			array->addObject(downTile2);
		}
	}
	//如果小于3个相连，说明没有可消除的瓦块
	if(array->count() <3){
		return NULL;
	}
	return array;
}

bool ThreeClearMap::isTypeSameWith(int row, int col, TCTile *originalTile)
{
	if(!canTileClear(row, col)){
		return false;
	}

	TCElementBase *originalElement = originalTile->getClearElement();
	TCTile *tile = m_map[row][col];
	TCElementBase *tileElement = tile->getClearElement();

	return tileElement->isTypeEqualTo(originalElement) ;
}
