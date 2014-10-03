#ifndef  _THREE_CLEAR_CONSTANTS_H_
#define  _THREE_CLEAR_CONSTANTS_H_

/**地图瓦片行数*/
static const int MAP_ROW_COUNT = 9;

/**地图每行的瓦片数量*/
static const int MAP_COL_COUNT = 9;

/**瓦片-陷阱元素-空*/ 
static const int TILE_TRAP_EMPTY = 0;
/**瓦片-陷阱元素-冰*/ 
static const int TILE_TRAP_ICE = 1;
/**瓦片-陷阱元素-双层冰*/ 
static const int TILE_TRAP_DOUBLE_ICE = 2;
/**瓦片-陷阱元素-石头*/
static const int TILE_TRAP_STONE =3;

/**可消除元素*/
static const int TILE_ELEMENT_EMPTY = 0;
static const int TILE_ELEMENT_1 = 1;
static const int TILE_ELEMENT_2 = 2;
static const int TILE_ELEMENT_3 = 3;
static const int TILE_ELEMENT_4 = 4;
static const int TILE_ELEMENT_5 = 5;
static const int TILE_ELEMENT_6 = 6;

/**地图中元素的层*/
static const int MAP_ZORDER_SHOW = 1;
static const int MAP_ZORDER_ELEMENT = 2;
static const int MAP_ZORDER_TRAP = 3;
static const int MAP_ZORDER_LOCK = 4;

/**地图起始坐标*/
static const int MAP_START_X = 24;
static const int MAP_START_Y = 100;

/**瓦片宽高*/
static const int TILE_WIDTH = 66;
static const int TILE_HEIGHT = 66;

/**瓦片显示类型的状态*/
static const int TILE_SHOW_NONE = 0;
static const int TILE_SHOW_DEFAULT = 1;

#endif