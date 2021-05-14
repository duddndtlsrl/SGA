#include "testScene.h"
#include "setDefine.h"

USING_NS_CC;

cocos2d::Scene * testScene::createScene()
{
	return testScene::create();
}

bool testScene::init()
{
	if(!Scene::init()) return false;

	SOUNDMANAGER->init();
	//DATAMANAGER->init("data/test.xml", "data/test.json");

	typewriterTest();

	return true;
}

void testScene::typewriterTest()
{
	const char* str = "You're not a voice, you're just a ringing in my ear\nAnd if I heard you, which I don't, I'm spoken for I fear";

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto label = Label::createWithSystemFont(std::string(str), "", FONTSIZE, Size(LABELWIDTH, LABELHEIGHT), TextHAlignment::CENTER, TextVAlignment::BOTTOM);
	label->setPosition(Vec2(visibleSize)*0.5f);
	label->setOpacity(0);
	this->addChild(label);

	LABELEFFECTMANAGER->typewriterFunc(label, 0.1f);
}
