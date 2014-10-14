#ifndef  _CLEAR_FACTORY_H_
#define  _CLEAR_FACTORY_H_

#include "cocos2d.h"
#include "../sprite/TCTile.h"
#include "ClearAlgorithm.h"
USING_NS_CC;

class ClearFactory : public CCObject{
public:
	static ClearFactory* sharedClearFactory();
	/*获取一个消除算法*/
	ClearAlgorithm *getDefaultAlgoritm(MatrixPtr matrix);
	/*获取一个消除算法*/
	ClearAlgorithm *getAlgoritm(TCTile *tile1, TCTile *tile2, MatrixPtr matrix);

private:
	bool init();
	ClearAlgorithm *m_simpleAlgorithm;
	ClearAlgorithm *m_ruinAlgorithm;
	ClearAlgorithm *m_singleCrossAlgorithm;
	ClearAlgorithm *m_multiCrossAlgorithm;
	ClearAlgorithm *m_cloneAlgorithm;
};

#endif