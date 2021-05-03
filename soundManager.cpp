#include "soundManager.h"
#include "AudioEngine.h"
#include "setDefine.h"

USING_NS_CC;
using namespace experimental;

void soundManager::init()
{
	bgmVolume = 1.0f;
	sfxVolume = 1.0f;
}

void soundManager::preloadAll(std::vector<char*>* bgm, std::vector<char*>* sfx)
{
	/*key와 array 값을 바탕으로 datamanaer::getFilePath()로 모든 음악 파일 경로를 불러온다 */
	for (auto iter = bgm->begin(); iter != bgm->end(); iter++)
	{
		DATAMANAGER->getFilePath(*iter, "bgm");
	}

	for (auto iter = sfx->begin(); iter != sfx->end(); iter++)
	{
		DATAMANAGER->getFilePath(*iter, "sfx");
	}
}

void soundManager::uncacheAll()
{
	/*재생 중인 사운드를 모두 정지시키고 메모리에서 해제*/

	AudioEngine::stopAll();

	AudioEngine::uncacheAll();
}

void soundManager::upVolume(float dt, bool bgm)
{
	int volume;
	
	if (bgm)
		volume = bgmVolume;
	else
		volume = sfxVolume;

	if (volume < 1.0f)
		volume += dt;

	if (bgm)
	{
		bgmVolume = volume;
		AudioEngine::setVolume(bgmId, bgmVolume);
	}
	else
	{
		sfxVolume = volume;
		AudioEngine::setVolume(sfxId, sfxVolume);
	}
}

void soundManager::downVolume(float dt, bool bgm)
{
	int volume;

	if (bgm)
		volume = bgmVolume;
	else
		volume = sfxVolume;

	if (volume > 0.0f)
		volume -= dt;

	if (bgm)
	{
		bgmVolume = volume;
		AudioEngine::setVolume(bgmId, bgmVolume);
	}
	else
	{
		sfxVolume = volume;
		AudioEngine::setVolume(sfxId, sfxVolume);
	}
}

void soundManager::playSound(const char * key, bool bgm)
{
	/*현재 재생되고 있는 사운드의 유무에 상관없이 key 값의 소리를 재생한다.*/

	if (bgm)
		bgmId = AudioEngine::play2d(DATAMANAGER->getFilePath(key, "bgm"), true, bgmVolume);
	else
		sfxId = AudioEngine::play2d(DATAMANAGER->getFilePath(key, "sfx"), true, sfxVolume);
}

void soundManager::pauseSound(bool bgm)
{
	if (bgm)
		AudioEngine::pause(bgmId);
	else
		AudioEngine::pause(sfxId);
}

void soundManager::resumeSound(bool bgm)
{
	if (bgm)
		AudioEngine::resume(bgmId);
	else
		AudioEngine::resume(sfxId);
}

void soundManager::stopSound(bool bgm)
{
	if (bgm)
		AudioEngine::stop(bgmId);
	else
		AudioEngine::stop(sfxId);
}



soundManager::~soundManager()
{
	AudioEngine::end();
}
