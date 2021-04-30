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

void soundManager::preloadAll(std::vector<const char*>* bgm, std::vector<const char*>* sfx)
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
	AudioEngine::stopAll();
	
	AudioEngine::uncacheAll();
}

void soundManager::upVolume()
{
	if()
}

void soundManager::downVolume()
{
}

void soundManager::playSound()
{
}

void soundManager::pauseSound()
{
}

void soundManager::resumeSound()
{
}

void soundManager::stopSound()
{
}

soundManager::~soundManager()
{
	uncacheAll();

	AudioEngine::end();
}
