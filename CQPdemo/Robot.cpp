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
	// ��ȡ�ļ��е�����
	rr::RrConfig robotini;
	robotini.ReadConfig(file);

	string name = robotini.ReadString("Robot", "name", "");
	gender_t gender;
	if (robotini.ReadString("Robot", "gender", "") == "��") {
		gender = gender_t::boy;
	}
	else if (robotini.ReadString("Robot", "gender", "") == "Ů") {
		gender = gender_t::girl;
	}
	else {
		gender = gender_t::unknown;
	}
	string dream = robotini.ReadString("Robot", "dream", "");

	QQ_T loverQQ = atoi(robotini.ReadString("Robot", "lover", "").c_str());
	// Ѱ���ļ���QQ
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


	// д������
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
	if (n < 0)// ������
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
