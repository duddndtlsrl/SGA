#pragma once
#include "singletone.h"
#include "cocos2d.h"

/*�Ŵ��� Ŭ���� ���*/
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
���� ��ġ
*/
#define FONTSIZE 30
#define LABELWIDTH 900
#define LABELHEIGHT 60
