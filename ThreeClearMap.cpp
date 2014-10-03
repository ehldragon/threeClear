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
				tile->setShow(0);
				continue;
			}
			tile->setShow(1);

			TCElementBase *element = NULL;
 			if(1 == c){
 				element = TCIce::create();
 			}
			if(2 == c){
				element = TCStone::create();
			}
			if(3 == c){
				element = TCIce::create(2);
			}
	
			if(element != NULL)
			{
				tile->setElement(element);
				CCSize size = tile->getContentSize();
				CCPoint point = CCPointMake(size.width / 2, size.height / 2);
				element->setPosition(point);
				tile->addChild(element, 1);
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
			tile->setPosition(point);
			addChild(tile, MAP_ZORDER_SHOW);
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

