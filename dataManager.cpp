#include "dataManager.h"
#include "cocos2d.h"

#include "json/stringbuffer.h"
#include "json/prettywriter.h"

USING_NS_CC;
using namespace tinyxml2;

void dataManager::init(const char* xmlFilePath, const char* jsonFilePath)
{
	/*xml ����(script)�� json ������ ��θ����� �ҷ��� ��������� �����Ѵ�*/

	{
		auto xmlUtil = FileUtils::getInstance();

		std::string path = xmlUtil->fullPathForFilename(xmlFilePath);
		xmlDoc = new tinyxml2::XMLDocument();

		XMLError error = xmlDoc->LoadFile(path.c_str());

		//���� �˻�
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

		//���� �˻�
		if (jsonDoc.HasParseError())
		{
			log("Parse Error Occured");
		}
		
	}

	/*�̸� ������ �ҷ��ͼ� vector container�� ����ִ´�*/


	return;

}

const char * dataManager::getFilePath(const char * key, const char* array)
{
	/*key ���� �´� ���ϸ��� �ҷ����� �Լ�. ����� ������ json�� �����ϴ�*/
	
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
