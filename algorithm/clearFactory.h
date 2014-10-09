#ifndef  _CLEAR_FACTORY_H_
#define  _CLEAR_FACTORY_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "clearAlgorithm.h"
USING_NS_CC;

class clearFactory : public CCObject{
public:
	static clearFactory* sharedClearFactory();
	bool init();
	/*获取一个消除算法*/
	clearAlgorithm *getDefaultAlgoritm(MatrixPtr matrix);
	/*获取一个消除算法*/
	clearAlgorithm *getAlgoritm(TCTile *tile1, TCTile *tile2, MatrixPtr matrix);

private:
	clearAlgorithm *m_simpleAlgorithm;
};

#endif