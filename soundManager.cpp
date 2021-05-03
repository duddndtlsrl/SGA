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
	/*key�� array ���� �������� datamanaer::getFilePath()�� ��� ���� ���� ��θ� �ҷ��´� */
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
	/*��� ���� ���带 ��� ������Ű�� �޸𸮿��� ����*/

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
	/*���� ����ǰ� �ִ� ������ ������ ������� key ���� �Ҹ��� ����Ѵ�.*/

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
