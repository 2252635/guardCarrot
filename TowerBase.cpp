#include"Tower.h"


Tower::~Tower()
{
	CC_SAFE_RELEASE_NULL(Target);
	CC_SAFE_RELEASE_NULL(MyTower);
}
bool Tower::Initiate(const int& MyId) {

		CC_BREAK_IF(!Entity::Initiate(MyId, TOWERCSVFILE));

		InitTower();

		TowerManager::GetInstance()->AddTower(this);//��������ӵ�TV��

		schedule(schedule_selector((Tower::CheckTarget), 0.1f));//ʹ�õ�����ע��ص�����

		schedule(schedule_selector(Tower::Attack), AttackRange);

		schedule(schedule_selector(Tower::Ratate), 0.1f);

		return true;
}
void Tower::InitTower()
{
	if (MyTower) //��������������ʵ��
		removeChild(MyTower);//����ʵ�����Ƴ�
	CC_SAFE_RELEASE_NULL(MyTower);//�ͷ�ָ��ʵ���ָ��

	auto CsvUtil = CsvUtil::GetInstance();//��ȡʵ��
	BulletId = CsvUtil->Initiate(Id, BULLET_ID, TOWERCSVFILE);
	AttackSpeed = CsvUtil->Initiate(Id, RANGE, TOWERCSVFILE);
	AttackRange = pCsvUtil->Duplicate(Id, SPACE, TOWERCSVFILE);
	UpCost = pCsvUtil->GetText(Id, UP_COST TOWERCSVFILE);
	IsRotate = CsvUtil->Initiate(Id, IS_ROTATE, TOWERCSVFILE);
	AttackUp = 0;
	CreateCost = CsvUtil->Initiate(Id, CREATE_COST, TOWERCSVFILE);
	HaveTarget = false;

	Grade = Sprite::create();
	Grade->setVisible(false);
	auto GradeAnimation = Animation::create();//�����ȼ��Ķ���
	for (int i = 1; i <= 2; i++) {
		GradeAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("showupgrade0%d.png", i)));//��ʾ��֡����
	}
	GradeAnimation->setDelayPerUnit(0.5);//������ʱΪ0.5s
	GradeAnimation->setLoops(1);//���ö���ѭ���Ĵ���Ϊ1
	Grade->setZOrder(3);//���ý����Ⱦ��˳��Ϊ3
	Grade->runAction(Animate::create(GradeAnimation));//ִ�ж���
	Grade->setPosition(0, 50);//���÷�����ʾ��λ��
	addChild(Grade);//���÷������Ϊ�½��

	MyTower = Sprite::createWithSpriteFrameName(CsvUtil->GetText(Id, TOWER_BASE, TOWERCSVFILE));
	MyTower->retain();//����Ref counting
	MyTower->setZOrder(1);//��Ⱦ˳��
	addChild(MyTower);//��ӽ��
	GetSprite()->setZOrder(2);//���þ������Ⱦ˳��
}
void Tower::DeadMove(const std::string& DeadImageFile)
{
	NOTIFY->postNotification("TowerDead", this);
	Entity::DeadMove();
}
void Tower::CheckTarget(float Delta) {
	if (!Target) ChooseTarget();
	else {
		if (Target->GetIsDead() || (!Target->GetAtkTarget() && HaveTarget))
		{
			MissTarget();
			setHaveTarget(false);
			return;
		}
		IsInAttackRange();
	}
}

void Tower::Attack(float Delta)
{
	if (Target && !Target->GetIsDead())//����Ŀ��Ϊ�ջ�Ŀ���Ѿ�����
		AttackMove();//���й���
}
void Tower::ChooseTarget()
{
	auto MonsterVec = MonsterManager::getInstance()->getMonsterVec();

	for (auto& iterMonster : MonsterVec)
	{
		if (IsInAttackRange(iterMonster->getPosition()))
		{
			SetTarget(iterMonster);
			break;
		}
	}
}
bool TowerBase::IsInAtkRange(const cocos2d::Vec2& Pos) {

	auto Distance = getPosition().distance(Pos);
	auto RangeSp = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("range_%d", AttackSpeed) + PHOTOPOSTFIX));
	CC_BREAK_IF(!(Distance < RangeSp->getContentSize().width / 2 + 30));
	return true;
}
void Tower::Attack(float Delta) {
	if (!Target || Target->getIsDead()) 
		return;
	AttackMove();

	auto CreateBulletCF = CallFunc::create([=]() {
		if (!Target) 
			return;
		BulletFactory::CreateBullet(BulletId, this, Target);
		});

	this->runAction(Sequence::create(DelayTime::create(0.15), CreateBulletCF, nullptr));
	//Executes an action, and returns the action that is executed
}
void Tower::CheckTargetIsOutOfRange()
{
	if (Target)
		if (!IsInAttackRange(Target->getPosition())) 
			MissTarget();
}
void Tower::MissTarget() {
	CC_SAFE_RELEASE_NULL(Target);
}

void Tower::SetTarget(VictimEntityBase* VictimEntity) {

	CC_SAFE_RELEASE_NULL(Target);//�ͷ�ԭ��Ŀ��
	Target =VictimEntity;//�滻Ϊ��Ŀ��
	CC_SAFE_RETAIN(Target);//����Ŀ��������ü���
}

Tower* Tower::PlaceTower(const int Id) {

	auto NewTower = new Tower();

	if (NewTower && NewTower->Initiate(Id)) {//���·�������Ϊ�գ��򷵻��·�������ָ��
		NewTower->autorelease();//���ٸö�������ü���
		return NewTower;
	}

	CC_SAFE_DELETE(NewTower);//ɾ���·�����
	return nullptr;//���ؿ�ָ��
}

void Tower::Rotate(float Delta) {

	if (!Target) 
		return;//������Ŀ��Ϊ�գ��򲻽�����ת

	if (IsRotate)//���������������Խ�����ת
		getSprite()->runAction(RotateTo::create(0.1, 90 - 180 * (Target->getPosition() - this->getPosition()).getAngle() / M_PI));
	//��ȡ��ǰ�����x��֮��ļнǵĻ��ȣ��õ���ת�ĽǶȣ���תʱ��Ϊ0.1s
}

void Tower::AttackMove() {
	std::string SoundName = Name;
	if (SoundName == "BStar") 
		SoundName = "PStar";
	SoundUtil::getInstance()->PlayEffect(StringUtils::format("Music/Towers/%s.mp3", SoundName.c_str()));
	auto MyAnimation = Animation::create();
	auto MySpriteFrameCache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= this->getAnimationFrameCount(); i++)
		MyAnimation->addSpriteFrame(MySpriteFrameCache->getSpriteFrameByName(ModelName + StringUtils::format("%d", i) + PHOTOPOSTFIX));
	MyAnimation->addSpriteFrame(MySpriteFrameCache->getSpriteFrameByName(ModelName + "1" + PHOTOPOSTFIX));
	MyAnimation->setDelayPerUnit(0.05);
	MyAnimation->setLoops(1);

	auto MyAnimate = Animate::create(MyAnimation);

	this->getSprite()->runAction(MyAnimate);
}

void Tower::GradeUp() {
	std::stringstream StoI;
	StoI << UpCost;
	int UpGradeMoney;
	StoI >> UpGradeMoney;
	UpGradeMoney = -UpGradeMoney;
	NotificationCenter::getInstance()->postNotification("moneyChange", (Ref*)(&UpGradeMoney));

	auto UpGradeCounts = this->getAttackUp();
	Grade->removeFromParentAndCleanup(true);
	getSprite()->removeFromParentAndCleanup(true);
	Entity::InitiateProperty(this->getId() + 1, TOWERCSVFILE);

	InitTower();
	this->AttackUp = UpGradeCounts;
}

int Tower::GetUpCost() {
	std::stringstream StoI;
	StoI << UpCost;
	int UpGradeMoney;
	StoI >> UpGradeMoney;
	return UpGradeMoney;
}

void Tower::ShowGrade() {
	Grade->setVisible(true);
}

void Tower::HideGradeMark() {
	Grade->setVisible(false);
}