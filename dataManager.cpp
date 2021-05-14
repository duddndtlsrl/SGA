#include "dataManager.h"
#include "cocos2d.h"

#include "json/stringbuffer.h"
#include "json/prettywriter.h"

USING_NS_CC;
using namespace tinyxml2;

void dataManager::init(const char* xmlFilePath, const char* jsonFilePath)
{
	/*xml 파일(script)와 json 파일을 경로명으로 불러와 멤버변수에 저장한다*/

	{
		auto xmlUtil = FileUtils::getInstance();

		std::string path = xmlUtil->fullPathForFilename(xmlFilePath);
		xmlDoc = new tinyxml2::XMLDocument();

		XMLError error = xmlDoc->LoadFile(path.c_str());

		//오류 검사
		if (error != 0)
		{
			log("Error Occured");
			return;
		}
	}

	{
		auto util = FileUtils::getInstance();
		std::string jsonData = util->getStringFromFile(jsonFilePath);

		jsonDoc.Parse<0>(jsonData.c_str());

		//오류 검사
		if (jsonDoc.HasParseError())
		{
			log("Parse Error Occured");
		}
		
	}

	/*미리 대사들을 불러와서 vector container에 집어넣는다*/


	return;

}

const char * dataManager::getFilePath(const char * key, const char* array)
{
	/*key 값에 맞는 파일명을 불러오는 함수. 비순차 접근인 json이 적합하다*/
	
	const rapidjson::Value &arr = jsonDoc[array];
	const char* path;

	if (arr.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arr.Size(); i++)
		{
			path = arr[i][key].GetString();
		}
	}

	return path;
}

const char* dataManager::getScript(const char * chapter)
{
	const char* foo;

	return foo;
}
