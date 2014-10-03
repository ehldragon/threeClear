#ifndef  _THREE_CLEAR_CONSTANTS_H_
#define  _THREE_CLEAR_CONSTANTS_H_

/**��ͼ��Ƭ����*/
static const int MAP_ROW_COUNT = 9;

/**��ͼÿ�е���Ƭ����*/
static const int MAP_COL_COUNT = 9;

/**��Ƭ-����Ԫ��-��*/ 
static const int TILE_TRAP_EMPTY = 0;
/**��Ƭ-����Ԫ��-��*/ 
static const int TILE_TRAP_ICE = 1;
/**��Ƭ-����Ԫ��-˫���*/ 
static const int TILE_TRAP_DOUBLE_ICE = 2;
/**��Ƭ-����Ԫ��-ʯͷ*/
static const int TILE_TRAP_STONE =3;

/**������Ԫ��*/
static const int TILE_ELEMENT_EMPTY = 0;
static const int TILE_ELEMENT_1 = 1;
static const int TILE_ELEMENT_2 = 2;
static const int TILE_ELEMENT_3 = 3;
static const int TILE_ELEMENT_4 = 4;
static const int TILE_ELEMENT_5 = 5;
static const int TILE_ELEMENT_6 = 6;

/**��ͼ��Ԫ�صĲ�*/
static const int MAP_ZORDER_SHOW = 1;
static const int MAP_ZORDER_ELEMENT = 2;
static const int MAP_ZORDER_TRAP = 3;
static const int MAP_ZORDER_LOCK = 4;

/**��ͼ��ʼ����*/
static const int MAP_START_X = 24;
static const int MAP_START_Y = 100;

/**��Ƭ���*/
static const int TILE_WIDTH = 66;
static const int TILE_HEIGHT = 66;

/**��Ƭ��ʾ���͵�״̬*/
static const int TILE_SHOW_NONE = 0;
static const int TILE_SHOW_DEFAULT = 1;

#endif