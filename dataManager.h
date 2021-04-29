#pragma once

#include "singletone.h"
#include "tinyxml2/tinyxml2.h"

class dataManager : public singletone<dataManager>
{
public:
	void init();

	const char* getFilePath(const char* key, const char* array);

private:
	tinyxml2::XMLDocument* bgmList;
	tinyxml2::XMLDocument* sfxList;

};