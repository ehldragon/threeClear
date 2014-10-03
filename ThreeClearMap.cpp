#include "ThreeClearMap.h"

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
			ThreeClearTile* tile = ThreeClearTile::create();
			m_map[r][c] = tile;
			if(0==r){
				tile->set(r, c, 0);
				continue;
			}

			tile->set(r, c, 1);

			if(1==c){
				tile->setTrap(TILE_TRAP_ICE);
			}
			if(2==c){
				tile->setTrap(TILE_TRAP_STONE);
			}
			if(3==c){
				tile->setTrap(TILE_TRAP_DOUBLE_ICE);
			}
		}
	}
	return true;
}


bool ThreeClearMap::mapInit(){
	if(!m_map){
		return false;
	}
	for(int r = 0;r < MAP_ROW_COUNT; r++){
		for(int c = 0; c < MAP_COL_COUNT; c++){
			ThreeClearTile* tile = m_map[r][c];
			CCPoint point = getPoint(r, c);

			// 瓦片背景
			int show = tile->getShow();
			CCSprite* showSprite = NULL;
			if(0 == show){
				showSprite = CCSprite::create();
			}
			else{
				showSprite = CCSprite::create("show1.png");
			}
			showSprite->setPosition(point);
			addChild(showSprite, MAP_ZORDER_SHOW);
			
			// 瓦片陷阱
			int trap = tile->getTrap();
			if(TILE_TRAP_EMPTY != trap){
				CCSprite* trapSprite = NULL;
				if(TILE_TRAP_ICE == trap){
					trapSprite= CCSprite::create("ice.png");
				}
				else if(TILE_TRAP_DOUBLE_ICE == trap){
					trapSprite= CCSprite::create("double_ice.png");
				}
				else if(TILE_TRAP_STONE == trap){
					trapSprite= CCSprite::create("stone.png");
				}
				trapSprite->setPosition(point);
				addChild(trapSprite, MAP_ZORDER_TRAP);
			}

			// 瓦片元素
			ThreeClearElement* element = tile->getElement();
			if(element){
				element->setPosition(point); //TODO 这里不应该是直接放置好，应该在地图的上面往下掉落
				addChild(element, MAP_ZORDER_ELEMENT);
			}

			// 笼子
			CCSprite* lockSprite = tile->getLockSprite();
			if(lockSprite){
				lockSprite->setPosition(point);
				addChild(lockSprite, MAP_ZORDER_LOCK);
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

