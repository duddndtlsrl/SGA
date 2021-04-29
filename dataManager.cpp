#include "dataManager.h"
#include "cocos2d.h"

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"

USING_NS_CC;
using namespace tinyxml2;

void dataManager::init()
{
	/*xml 파일(script)와 json 파일을 경로명으로 불러와 멤버변수에 저장한다*/

}

const char * dataManager::getFilePath(const char * key, const char* array)
{
	/*key 값에 맞는 파일명을 불러오는 함수. 비순차 접근인 json이 적합하다*/

}
