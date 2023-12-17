#include"Entity.h"

int Entity::Num = 0;//��ʼ�������
Entity::~Entity()//��ָ�����ָ������ͷ�
{
	CC_SAFE_RELEASE_NULL(MySprite);
}
bool Entity::Initiate(int num, const std::string& CsvFileName)//�����ļ����ƶ�������г�ʼ��
{
	InitiateProperty(num, CsvFildName);//��ʼ������ĲƲ�
	++Num;//Enity��������1
	MyNo = Num;
	return true;//���س�ʼ���ɹ��ı�־
}
const Size& Entity::GetSize()const
{
	return MySprite->getContentSize();
}
int Entity::GetNum()//��ȡ��ǰ���ı��
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

	auto MyDeadImageFile = DeadImageFile;//��ʼ������ͼ��
	auto MyAnimation = Animation::create();//��������
	auto MySpriteFrameCache = SpriteFrameCache::getInstance();//��ȡ����֡����ʵ��

	if (!MyDeadImageFile.empty())//����ͼ��Ϊ��
	{
		switch (Level) {//���ݵ�ǰ�ȼ���������ͼ�������
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
		for (int i = 0; i < AnimationFrameCount; i++)//��Ӿ���֡
			MyAnimation->addSpriteFrame(SpriteFrameCache->getSpriteFrameByName(DeadImageFile + StringUtils::format("%d", i) + PHOTOPOSTFIX));

	}
	else//����ֱ�������������֡
	{
		for (int i = 0; i < 2; i++)
			Animation->addSpriteFrame(SpriteFrameCache->getSpriteFrameByName(DeadImageFile + StringUtils::format("%02d", i) + PHOTOPOSTFIX));
	}
	//���ö�������
	MyAnimation->setLoops(1);
	MyAnimation->setDelayPerUnit(0.1f);
	//ִ��
	MySprite->runAction(Sequence::create(Animate::create(MyAnimation), CallFunc::create([this]() {this->removeFromParent(); }), NULL));
}

Rect Entity::GetBoundingBox()const
{
	auto Pos = getPosition();//��ȡ����λ��
	auto Size = MySprite->getContentSize();//��ȡ����ߴ�
	return Rect(Pos.x - Size.width / 2, Pos.y - Size.height / 2, Size.width, Size.height);
}

int Entity::GetNum()
{
	return MyNo;
}


