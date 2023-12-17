#include"Entity.h"

int Entity::Num = 0;//初始化结点编号
Entity::~Entity()//对指向精灵的指针进行释放
{
	CC_SAFE_RELEASE_NULL(MySprite);
}
bool Entity::Initiate(int num, const std::string& CsvFileName)//根据文件名称对物体进行初始化
{
	InitiateProperty(num, CsvFildName);//初始化物体的财产
	++Num;//Enity的数量加1
	MyNo = Num;
	return true;//返回初始化成功的标志
}
const Size& Entity::GetSize()const
{
	return MySprite->getContentSize();
}
int Entity::GetNum()//获取当前结点的编号
{
	return MyNo;
}
void Entity::InitiateProperty(const int Src, const std::string& CsvFileName)
{
	auto MyCsvUtil = CsvUtil::GetInstance();
	Id = Src;
	auto Data = MyCsvUtil->GetSomeRow(Src, CsvFileName);
	Name = Data.at(NAME);
	ModelName = Data.at(MODELNAME);
	Value = atoi(Data.at(VALUE).c_str());
	AnimationFrameCount = MyCsvUtil->Initiate(Id,ANIMATION_COUNT, CsvFileName);
	Grade = MyCsvUtil->Initiate(Id, GRADE, CsvFileName);
	IsDead = false;

	std::string SpriteName = "";
	if (AnimationFrameCount) SpriteName = ModelName + "1" + PHOTOPOSTFIX;
	else SpriteName = ModelName + PHOTOPOSTFIX;

	BindSprite(Sprite::createWithSpriteFrameName(SpriteName));
}
void Entity::BindSprite(cocos2d::Sprite* NewSprite)
{
	if (MySprite)
	{
		MySprite->stopAllActions();
		removeChild(MySprite);
	}
	CC_SAFE_RELEASE_NULL(MySprite);
	MySprite = pSprite;
	CC_SAFE_RETAIN(MySprite);
	addChild(MySprite);
}
Sprite* Entity::GetSprite()
{
	return MySprite;
}
void Entity::Dead()
{
	NOTIFY->postNotification("moneyChange", reinterpret_cast<Ref*>(&_iValue));
	setIsDead(true);
	MySprite->stopAllActions();
	DeadMove();
}
void Entity::DeadMove(const std::string& DeadImageFile)
{

	auto MyDeadImageFile = DeadImageFile;//初始化死亡图像
	auto MyAnimation = Animation::create();//创建动画
	auto MySpriteFrameCache = SpriteFrameCache::getInstance();//获取精灵帧缓存实例

	if (!MyDeadImageFile.empty())//死亡图像为空
	{
		switch (Level) {//根据当前等级更改死亡图像的名字
		case 1:
			MyDeadImageFild = "air0";
			break;
		case 2:
			MyDeadImageFile = "air1";
			break;
		case 3:
			MyDeadImageFile = "air2";
			break;
		}
		for (int i = 0; i < AnimationFrameCount; i++)//添加精灵帧
			MyAnimation->addSpriteFrame(SpriteFrameCache->getSpriteFrameByName(DeadImageFile + StringUtils::format("%d", i) + PHOTOPOSTFIX));

	}
	else//否则直接添加两个精灵帧
	{
		for (int i = 0; i < 2; i++)
			Animation->addSpriteFrame(SpriteFrameCache->getSpriteFrameByName(DeadImageFile + StringUtils::format("%02d", i) + PHOTOPOSTFIX));
	}
	//设置动画属性
	MyAnimation->setLoops(1);
	MyAnimation->setDelayPerUnit(0.1f);
	//执行
	MySprite->runAction(Sequence::create(Animate::create(MyAnimation), CallFunc::create([this]() {this->removeFromParent(); }), NULL));
}

Rect Entity::GetBoundingBox()const
{
	auto Pos = getPosition();//获取精灵位置
	auto Size = MySprite->getContentSize();//获取精灵尺寸
	return Rect(Pos.x - Size.width / 2, Pos.y - Size.height / 2, Size.width, Size.height);
}

int Entity::GetNum()
{
	return MyNo;
}


