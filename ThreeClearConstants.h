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


/**可消除元素的超级状态*/
static const int TILE_SUPER_ELEMENT_NONE = 0; //没有超级状态
static const int TILE_SUPER_ELEMENT_ROW = 1; //消除一整行
static const int TILE_SUPER_ELEMENT_COLUMN = 2; //消除一整列
static const int TILE_SUPER_ELEMENT_SURROUND = 3; //消除周边两圈范围
static const int TILE_SUPER_ELEMENT_BOMB = 4; //五连消生成的炸弹效果

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

/**能引发交换的最小滑动位移*/
static const int SWAP_OFFSET_LIMIT = 36;

#endif