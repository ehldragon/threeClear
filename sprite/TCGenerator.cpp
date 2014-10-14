#include "TCGenerator.h"
#include "TCElement.h"
#include "../ThreeClearConstants.h"

static TCGenerator *generator;
/*Ĭ�϶���capacityΪ10*/
static unsigned int queueMaxCount = 10;

TCGenerator::TCGenerator()
{

}

TCGenerator* TCGenerator::sharedGenerator()
{
	if(!generator){
		generator = new TCGenerator();
		generator->init();
	}
	return generator;
}

bool TCGenerator::init()
{
	m_queue = CCArray::createWithCapacity(queueMaxCount);
	m_queue->retain();
	for(int index = 0; index < queueMaxCount; index++)
	{
		TCElementBase *element = generate();
		enqueue(element);
	}
	return true;
}

TCElementBase * TCGenerator::generate()
{
	int type = rand()%6;
	if(0 == type){
		type++;
	}
	TCElement *element = TCElement::create(type);
	return element;
}

TCElementBase * TCGenerator::getElement()
{
	TCElementBase *element = dequeue();
	checkQueue();
	return element;
}

CCArray * TCGenerator::getElements(int count)
{
	CCArray *array = CCArray::createWithCapacity(count);
	for(int index = 0; index < count; index++)
	{
		TCElementBase *element = getElement();
		array->addObject(element);
	}
	return array;
}

void TCGenerator::enqueue(TCElementBase *element)
{
	if(!element){
		return;
	}
	m_queue->addObject(element);
}

TCElementBase* TCGenerator::dequeue()
{
	TCElementBase* element = (TCElementBase *)m_queue->objectAtIndex(0);
	//��������˵��addObjectһ��object������ᱻretain��������Ե�removeObjectӦ��Ҳ����release;
	//������ôд��΢�е��Ť�����remove����Ϊtrue����element���̾ͻᱻ�����������Ծ�û�취��return�ˡ�
	//ֻ���ȷ���autorelease��
	m_queue->removeObjectAtIndex(0, false);
	element->autorelease();
	return element;
}

void TCGenerator::checkQueue()
{
	if(m_queue->count() < (queueMaxCount>>2))
	{
		int enqueueCount = queueMaxCount - m_queue->count();
		for(int index = 0; index < enqueueCount; index++)
		{
			TCElementBase *element = generate();
			enqueue(element);
		}
	}
}




