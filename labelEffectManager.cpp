#include "labelEffectManager.h"
#include "setDefine.h"

USING_NS_CC;

void labelEffectManager::typewriterFunc(cocos2d::Label* label, float speed)
{
	_label = label;
	
	label->unschedule(schedule_selector(labelEffectManager::typewriter));
	
	label->schedule(schedule_selector(labelEffectManager::typewriter));
	
	
}

void labelEffectManager::typewriter(float dt)
{
	it = 0;
	
	std::vector<Sprite*> letters;
	letters.reserve(100);
	
	if (it < _label->getStringLength())
	{
		if (it*FONTSIZE <= LABELWIDTH)
		{
			auto letter = _label->getLetter(it);
			/*���� Sprite*�� ���Ϳ� �����Ѵ�*/
			letters.push_back(letter);

			if (!letter)
			{
				it++;
				return;
			}

			letter->setColor(Color3B::WHITE);
			letter->setOpacity(255);
		}
		else
		{
			/*ĭ�� �� ä�����ٸ� ���ο� ���ڸ� ����ϱ� ���� ������ Sprite*�� �����Ѵ�*/
			letters.clear();
		}
	}
	else
	{
		it = 0;
		_label->unschedule(schedule_selector(labelEffectManager::typewriter));
	}

	

}
