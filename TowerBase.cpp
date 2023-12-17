#include"Tower.h"


Tower::~Tower()
{
	CC_SAFE_RELEASE_NULL(Target);
	CC_SAFE_RELEASE_NULL(MyTower);
}
bool Tower::Initiate(const int& MyId) {

		CC_BREAK_IF(!Entity::Initiate(MyId, TOWERCSVFILE));

		InitTower();

		TowerManager::GetInstance()->AddTower(this);//将该塔添加到TV中

		schedule(schedule_selector((Tower::CheckTarget), 0.1f));//使用调度器注册回调函数

		schedule(schedule_selector(Tower::Attack), AttackRange);

		schedule(schedule_selector(Tower::Ratate), 0.1f);

		return true;
}
void Tower::InitTower()
{
	if (MyTower) //如果这个塔已有有实体
		removeChild(MyTower);//将该实体结点移除
	CC_SAFE_RELEASE_NULL(MyTower);//释放指向实体的指针

	auto CsvUtil = CsvUtil::GetInstance();//获取实例
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
	auto GradeAnimation = Animation::create();//创建等级的动画
	for (int i = 1; i <= 2; i++) {
		GradeAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("showupgrade0%d.png", i)));//显示两帧动画
	}
	GradeAnimation->setDelayPerUnit(0.5);//设置延时为0.5s
	GradeAnimation->setLoops(1);//设置动画循环的次数为1
	Grade->setZOrder(3);//设置结点渲染的顺序为3
	Grade->runAction(Animate::create(GradeAnimation));//执行动作
	Grade->setPosition(0, 50);//设置分数显示的位置
	addChild(Grade);//将该分数添加为新结点

	MyTower = Sprite::createWithSpriteFrameName(CsvUtil->GetText(Id, TOWER_BASE, TOWERCSVFILE));
	MyTower->retain();//增加Ref counting
	MyTower->setZOrder(1);//渲染顺序
	addChild(MyTower);//添加结点
	GetSprite()->setZOrder(2);//设置精灵的渲染顺序
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
	if (Target && !Target->GetIsDead())//攻击目标为空或目标已经死亡
		AttackMove();//进行攻击
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

	CC_SAFE_RELEASE_NULL(Target);//释放原有目标
	Target =VictimEntity;//替换为新目标
	CC_SAFE_RETAIN(Target);//给新目标添加引用计数
}

Tower* Tower::PlaceTower(const int Id) {

	auto NewTower = new Tower();

	if (NewTower && NewTower->Initiate(Id)) {//若新防御塔不为空，则返回新防御塔的指针
		NewTower->autorelease();//减少该对象的引用计数
		return NewTower;
	}

	CC_SAFE_DELETE(NewTower);//删除新防御塔
	return nullptr;//返回空指针
}

void Tower::Rotate(float Delta) {

	if (!Target) 
		return;//若攻击目标为空，则不进行旋转

	if (IsRotate)//如果这个防御塔可以进行旋转
		getSprite()->runAction(RotateTo::create(0.1, 90 - 180 * (Target->getPosition() - this->getPosition()).getAngle() / M_PI));
	//获取当前结点与x轴之间的夹角的弧度，得到旋转的角度，旋转时间为0.1s
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