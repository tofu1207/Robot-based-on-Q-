#include "Robot.h"


extern const QQ_T MASTERQQ = 2890851110;

Robot::Robot()
{
}

Robot::Robot(string name, gender_t gender, time_b birth,
	string* hobby, string* likeFood, string* likeSport, string* oral,
	string dream, Person lover,
	int hobbyNum, int likeFoodNum, int likeSportNum, int oralNum):
	m_name(name), m_gender(gender), m_birth(birth),
	m_dream(dream), m_lover(lover),
	m_hobbyNum(hobbyNum), m_likeFoodNum(likeFoodNum),
	m_likeSportNum(likeSportNum), m_oralNum(oralNum)
{
	
	for (int i = 0; i < hobbyNum; ++i) {
		m_hobby.push_back(hobby[i]);
	}

	for (int i = 0; i < likeFoodNum; ++i) {
		m_likeFood.push_back(likeFood[i]);
	}

	for (int i = 0; i < likeSportNum; ++i) {
		m_likeSport.push_back(likeSport[i]);
	}

	for (int i = 0; i < oralNum; ++i) {
		m_oral.push_back(oral[i]);
	}
}

Robot::Robot(char* file, char* personfile)
{
	// 获取文件中的数据
	rr::RrConfig robotini;
	robotini.ReadConfig(file);

	string name = robotini.ReadString("Robot", "name", "");
	gender_t gender;
	if (robotini.ReadString("Robot", "gender", "") == "男") {
		gender = gender_t::boy;
	}
	else if (robotini.ReadString("Robot", "gender", "") == "女") {
		gender = gender_t::girl;
	}
	else {
		gender = gender_t::unknown;
	}
	string dream = robotini.ReadString("Robot", "dream", "");

	QQ_T loverQQ = atoi(robotini.ReadString("Robot", "lover", "").c_str());
	// 寻找文件中QQ
	rr::RrConfig personini;
	personini.ReadConfig(personfile);
	string sitem = "QQ" + to_String(loverQQ);
	int goodwill = personini.ReadInt(sitem.c_str(), "goodwill", 0);
	Robot::Person lover{ loverQQ, goodwill };

	time_b birth;
	birth.year = robotini.ReadInt("Birth", "year", 0);
	birth.month = month_t(robotini.ReadInt("Birth", "month", 0));
	birth.day = day_t(robotini.ReadInt("Birth", "day", 0));
	stringInt hobby = getString(robotini, "Hobby", "hobby", "");
	stringInt likefood = getString(robotini, "likeFood", "likefood", "");
	stringInt likesport = getString(robotini, "likeSport", "likesport", "");
	stringInt oral = getString(robotini, "Oral", "oral", "");


	// 写入数据
	m_name = name;
	m_gender = gender;
	m_birth = birth;
	m_hobby = hobby.str;
	m_hobbyNum = hobby.i;
	m_likeFood = likefood.str;
	m_likeFoodNum = likefood.i;
	m_likeSport = likesport.str;
	m_likeSportNum = likesport.i;
	m_oral = oral.str;
	m_oralNum = oral.i;
	m_dream = dream;
	m_lover = lover;

}

Robot::~Robot()
{
}


int Robot::sendPrivateMag(int64_t QQID, const char* msg)
{
	return CQ_sendPrivateMsg(ac, QQID, msg);
}

int Robot::sendGroupMsg(int64_t groupid, const char* msg)
{
	return CQ_sendGroupMsg(ac, groupid, msg);;
}

int Robot::sendDiscussMsg(int64_t discussid, const char* msg)
{
	return CQ_sendDiscussMsg(ac, discussid, msg);
}

int Robot::deleteMsg(int64_t msgid)
{
	return CQ_deleteMsg(ac, msgid);
}

int Robot::sendLike(int64_t QQID)
{
	return CQ_sendLike(ac, QQID);
}

int Robot::setGroupKick(int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest)
{
	return  CQ_setGroupKick(ac, groupid, QQID, rejectaddrequest);
}

int Robot::setGroupBan(int64_t groupid, int64_t QQID, int64_t duration)
{
	return CQ_setGroupBan(ac, groupid, QQID, duration);
}

int Robot::setGroupAdmin(int64_t groupid, int64_t QQID, CQBOOL setadmin)
{
	return CQ_setGroupAdmin(ac, groupid, QQID, setadmin);
}

int Robot::setGroupWholeBan(int64_t groupid, CQBOOL enableban)
{
	return CQ_setGroupWholeBan(ac, groupid, enableban);
}

int Robot::setGroupAnonymousBan(int64_t groupid, const char* anomymous, int64_t duration)
{
	return CQ_setGroupAnonymousBan(ac, groupid, anomymous, duration);
}

int Robot::setGroupAnonymous(int64_t groupid, CQBOOL enableanomymous)
{
	return CQ_setGroupAnonymous(ac, groupid, enableanomymous);
}

int Robot::setGroupCard(int64_t groupid, int64_t QQID, const char* newcard)
{
	return CQ_setGroupCard(ac, groupid, QQID, newcard);
}

int Robot::setGroupLeave(int64_t groupid, CQBOOL isdismiss)
{
	return CQ_setGroupLeave(ac, groupid, isdismiss);
}

int Robot::setGroupSpecialTitle(int64_t groupid, int64_t QQID, const char* newspecialtitle, int64_t duration)
{
	return CQ_setGroupSpecialTitle(ac, groupid, QQID, newspecialtitle, duration);
}

int Robot::setDiscussLeave(int64_t discussid)
{
	return CQ_setDiscussLeave(ac, discussid);
}

int Robot::setFriendAddRequest(const char* responseflag, int32_t responseoperation, const char* remark)
{
	return CQ_setFriendAddRequest(ac, responseflag, responseoperation, remark);
}

int Robot::setGroupAddRequestV2(const char* responseflag, int32_t requesttype, int32_t responseoperation, const char* reason)
{
	return CQ_setGroupAddRequestV2(ac, responseflag, requesttype, responseoperation, reason);
}

const char* Robot::getGroupMemberInfoV2(int64_t groupid, int64_t QQID, CQBOOL nocache)
{
	return CQ_getGroupMemberInfoV2(ac, groupid, QQID, nocache);
}

const char* Robot::getStrangerInfo(int64_t QQID, CQBOOL nocache)
{
	return CQ_getStrangerInfo(ac, QQID, nocache);
}

int Robot::addLog(int32_t priority, const char* category, const char* content)
{
	return CQ_addLog(ac, priority, category, content);
}

int64_t Robot::getLoginQQ()
{
	return CQ_getLoginQQ(ac);
}

const char* Robot::getLoginNick()
{
	return CQ_getLoginNick(ac);
}

const char* Robot::getAppDirectory()
{
	return CQ_getAppDirectory(ac);
}

int Robot::setFatal(const char* errorinfo)
{
	return CQ_setFatal(ac, errorinfo);
}

const char* Robot::getRecord(const char* file, const char* outformat)
{
	return CQ_getRecord(ac, file, outformat);
}

Robot::Person::Person(QQ_T QQ, int goodWill, string name, gender_t gender, time_b birth) :
	m_QQ(QQ), m_goodWill(goodWill), m_name(name), m_gender(gender), m_birth(birth)
{
}

extern string to_String(QQ_T n)
{
	const int max = 100;
	QQ_T m = n;
	char s[max];
	char ss[max];
	int i = 0, j = 0;
	if (n < 0)// 处理负数
	{
		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}
	while (m > 0)
	{
		s[i++] = m % 10 + '0';
		m /= 10;
	}
	s[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ss[j++] = s[i--];
	}
	ss[j] = '\0';
	return ss;
}

extern stringInt getString(rr::RrConfig config, const char* section, const char* item, const char* default_value)
{

	stringInt si;
	vector<string> str;
	int i = 1;
	while (1) {
		string sitem = item + to_String(i);
		sitem = config.ReadString(section, sitem.c_str(), default_value);
		if (sitem== default_value) {
			break;
		}
		else {
			i++;
			str.push_back(sitem.c_str());
		}
	}
	si.i = i - 1;
	si.str = str;
	return si;
}
