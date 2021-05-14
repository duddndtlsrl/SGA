#pragma once
#include "singletone.h"
#include "cocos2d.h"

/*매니저 클레스 헤더*/
#include "soundManager.h"
#include "dataManager.h"
#include "labelEffectManager.h"

/*
managerClass
*/
#define SOUNDMANAGER soundManager::getSingletone()
#define DATAMANAGER dataManager::getSingletone()
#define LABELEFFECTMANAGER labelEffectManager::getSingletone()

/*
각종 수치
*/
#define FONTSIZE 30
#define LABELWIDTH 900
#define LABELHEIGHT 60
