#pragma once
#include "json/rapidjson.h"
#include "json/document.h"
#include "singletone.h"
#include "tinyxml2/tinyxml2.h"


class dataManager : public singletone<dataManager>
{
public:
	void init(const char* xmlFilePath, const char* jsonFilePath);

	const char* getFilePath(const char* key, const char* array);

private:
	tinyxml2::XMLDocument* xmlDoc;
	rapidjson::Document jsonDoc;

};