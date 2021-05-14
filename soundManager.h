#pragma once
#include "singletone.h"
#include "cocos2d.h"

class soundManager : public singletone<soundManager>
{
public:
	void init();

private:
	float bgmVolume;
	float sfxVolume;
	
	int bgmId;
	int sfxId;
	
	void preloadAll(std::vector<char*>* bgm, std::vector<char*>* sfx);
	void uncacheAll();

	void upVolume(float dt, bool bgm=false);
	void downVolume(float dt, bool bgm = false);

	void playSound(const char* key, bool bgm=false);
	void pauseSound(bool bgm = false);
	void resumeSound(bool bgm = false);
	void stopSound(bool bgm = false);

	~soundManager();

};