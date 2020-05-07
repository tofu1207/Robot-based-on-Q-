#include "Robot.h"

#include "CQApi.h"      //CQ的api重构

extern char* ROBOTINI = "ShallowBird.ini";
extern char* PERSONINI = "C:\\Person.ini";
extern const QQ_T MASTERQQ = 2890851110;


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

extern Person getPerson(QQ_T QQ)
{
	// 获取文件中的数据
	rr::RrConfig personini;
	personini.ReadConfig(PERSONINI);
	string sitem = "QQ" + to_String(QQ);
	if (::GetPrivateProfileInt(sitem.c_str(), "qqid", 0, PERSONINI) == 0) {
		return Person(0);
	}
	int goodwill = personini.ReadInt(sitem.c_str(), "goodwill", 0);
	string name = personini.ReadString(sitem.c_str(), "name", "");
	gender_t gender;
	if (personini.ReadString(sitem.c_str(), "gender", "") == "男") {
		gender = gender_t::boy;
	}
	else if (personini.ReadString(sitem.c_str(), "gender", "") == "女") {
		gender = gender_t::girl;
	}
	else {
		gender = gender_t::unknown;
	}
	time_b birth;
	birth.year = personini.ReadInt(sitem.c_str(), "birth.year", 0);
	birth.month = month_t(personini.ReadInt(sitem.c_str(), "birth.month", 0));
	birth.day = day_t(personini.ReadInt(sitem.c_str(), "birth.day", 0));
	Person person(QQ, goodwill, name, gender, birth);
	return person;
}

void setPerson(QQ_T QQ)
{
	// 读取 QQ 的字段地址
	string sitem = "QQ" + to_String(QQ);

	// 保存现有的person数据
	Person tem_person = getPerson(QQ);
	if (tem_person.m_QQ == 0) {
		::WritePrivateProfileString(sitem.c_str(), "qqid", to_String(QQ).c_str(), PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "goodwill", "0", PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "name", "", PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "gender", to_String((int)gender_t::unknown).c_str(), PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "birh.year", "0", PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "birth.month", to_String((int)month_t::m1).c_str(), PERSONINI);
		::WritePrivateProfileString(sitem.c_str(), "birth.day", to_String((int)day_t::d1).c_str(), PERSONINI);
	}
	else {
		::WritePrivateProfileString(sitem.c_str(), "qqid", to_String(tem_person.m_QQ).c_str(), PERSONINI);
		if (tem_person.m_goodWill != 0) {
			::WritePrivateProfileString(sitem.c_str(), "goodwill", to_String(tem_person.m_goodWill).c_str(), PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "goodwill", "0", PERSONINI);
		}

		if (tem_person.m_name != "") {
			::WritePrivateProfileString(sitem.c_str(), tem_person.m_name.c_str(), "", PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "name", "", PERSONINI);
		}

		if (tem_person.m_gender != gender_t::unknown) {
			::WritePrivateProfileString(sitem.c_str(), "gender", to_String((int)tem_person.m_gender).c_str(), PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "gender", to_String((int)gender_t::unknown).c_str(), PERSONINI);
		}

		if (tem_person.m_birth.year != 0) {
			::WritePrivateProfileString(sitem.c_str(), "birh.year", to_String(tem_person.m_birth.year).c_str(), PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "birh.year", "0", PERSONINI);
		}

		if (tem_person.m_birth.month != month_t::m1) {
			::WritePrivateProfileString(sitem.c_str(), "birth.month", to_String((int)tem_person.m_birth.month).c_str(), PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "birth.month", to_String((int)month_t::m1).c_str(), PERSONINI);
		}

		if (tem_person.m_birth.day != day_t::d1) {
			::WritePrivateProfileString(sitem.c_str(), "birth.day", to_String((int)tem_person.m_birth.day).c_str(), PERSONINI);
		}
		else {
			::WritePrivateProfileString(sitem.c_str(), "birth.day", to_String((int)day_t::d1).c_str(), PERSONINI);
		}
	}
}


Person::Person()
{
}

Person::Person(QQ_T QQ, int goodWill, string name, gender_t gender, time_b birth):
	m_QQ(QQ), m_goodWill(goodWill), m_name(name), m_gender(gender), m_birth(birth)
{
}

void Person::setGoodwill(int goodwill)
{
	string sitem = "QQ" + to_String(m_QQ);
	::WritePrivateProfileString(sitem.c_str(), "goodwill", to_String(goodwill).c_str(), PERSONINI);
}

void Person::setName(string name)
{
	string sitem = "QQ" + to_String(m_QQ);
	::WritePrivateProfileString(sitem.c_str(), "name", name.c_str(), PERSONINI);
}

void Person::setGender(gender_t gender)
{
	string sitem = "QQ" + to_String(m_QQ);
	::WritePrivateProfileString(sitem.c_str(), "gender", to_String((int)gender).c_str(), PERSONINI);
}

void Person::serBirth(time_b birrh)
{
	string sitem = "QQ" + to_String(m_QQ);
	::WritePrivateProfileString(sitem.c_str(), "birth.year", to_String((int)birrh.year).c_str(), PERSONINI);
	::WritePrivateProfileString(sitem.c_str(), "birth.month", to_String((int)birrh.month).c_str(), PERSONINI);
	::WritePrivateProfileString(sitem.c_str(), "birth.day", to_String((int)birrh.day).c_str(), PERSONINI);
}

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

	QQ_T loverQQ = atoll(robotini.ReadString("Robot", "lover", "").c_str());
	// 寻找文件中QQ
	Person lover = getPerson(loverQQ);
	/*
	rr::RrConfig personini;
	personini.ReadConfig(personfile);
	string sitem = "QQ" + to_String(loverQQ);
	int goodwill = personini.ReadInt(sitem.c_str(), "goodwill", 0);
	Person lover{ loverQQ, goodwill };
	*/
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