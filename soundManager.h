#pragma once
#include "singletone.h"
#include "cocos2d.h"

class soundManager : public singletone<soundManager>, public cocos2d::Ref
{
public:
	void init();

private:
	float _soundVolume;
	int audioId1;
	std::vector<const std::string*> bgmList;
	std::vector<const std::string*> sfxLIst;
	
	void preloadAll(Ref* pSender);
	void uncacheAll(Ref* pSender);

	void upVolume(Ref* pSender);
	void downVolume(Ref* pSender);

	void playSound(Ref* pSender);
	void pauseSound(Ref* pSender);
	void resumeSound(Ref* pSender);
	void stopSound(Ref* pSender);

	~soundManager();

};