#pragma once
#include "singletone.h"
#include "cocos2d.h"

class labelEffectManager : public singletone<labelEffectManager>, cocos2d::Ref
{
public:
	void typewriterFunc(cocos2d::Label* label, float speed = 0.1f);
	void typewriter(float dt);
	
private:
	cocos2d::Label* _label;
	int it;
};