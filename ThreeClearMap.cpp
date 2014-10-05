#include "ThreeClearMap.h"
#include "sprite/TCElementSpritesState.h"

ThreeClearMap::ThreeClearMap()
{
	
}

ThreeClearMap::~ThreeClearMap()
{

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

			TCElementBase *element = NULL;
 			if(1 == c){
 				element = TCIce::create();
 			}
			if(2 == c){
				element = TCStone::create();
			}
			if(3 == c){
				element = TCStone::create();
			}
			if(4 == c){
				element = TCIce::create(2);
			}
	
			if(element != NULL)
			{
				tile->setElement(element);
			}
		}
	}
	return true;
}
// 
// 
bool ThreeClearMap::mapInit(){
	if(!m_map){
		return false;
	}
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
				addChild(element, MAP_ZORDER_SHOW);
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
	if(!canTileSwap(m_selectedRow,m_selectedCol)){
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
		return;// 行列索引不合法，返回
	}
	if(!canTileSwap(dstRow,dstCol)){
		return;// 行列索引不合法，返回
	}
	TCTile* srcTile = m_map[srcRow][srcCol];
	TCTile* dstTile = m_map[dstRow][dstCol];
	
	//获取每个瓦块中，真正能够被提取出来移动交换的element
	TCElementBase *srcElement = srcTile->getMoveElement();
	TCElementBase *dstElement = dstTile->getMoveElement();
	//srcTile->setVisible(false);
	//dstTile->setVisible(false);

	CCPoint srcPoint = getPoint(srcTile->getRow(), srcTile->getCol());
	CCPoint dstPoint = getPoint(dstTile->getRow(), dstTile->getCol());
	
	srcElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, dstPoint),
		CCMoveTo::create(0.2f, srcPoint),
		NULL));
	dstElement->runAction(CCSequence::create(
		CCMoveTo::create(0.2f, srcPoint),
		CCMoveTo::create(0.2f, dstPoint),
		NULL));
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



