#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RrConfig.h"

typedef std::int64_t QQ_T;

using std::endl;
using std::string;
using std::vector;

/*--------------------------------------------------------------------------------
*------------------------------   主人QQ号   --------------------------------------*
 --------------------------------------------------------------------------------*/
extern const QQ_T MASTERQQ;


/*--------------------------------------------------------------------------------
*------------------------------   时间类型   --------------------------------------*
 --------------------------------------------------------------------------------*/
enum class month_t {	//月份
	m1 = 1, 
	m2,  m3, 
	m4,  m5, 
	m6,  m7, 
	m8,  m9, 
	m10, m11, 
	m12 
};
enum class day_t {	//“一三五七八十腊,三十一天永不差,
					//四六九冬三十天,平年二月二十八(闰二月28天)"
	d1 = 1,
	d2,  d3,  d4,  d5,  d6,  d7,  d8,  d9,
	d10, d11, d12, d13, d14, d15, d16, d17,
	d18, d19, d20, d21, d22, d23, d24, d25,
	d26, d27, d28, d29, d30, d31
};
struct time_b {
	int year;	//年份
	month_t month;	//月份
	day_t day;	//日期

	// 重载 cout << time_b数据对象
	friend std::ostream& operator<<(std::ostream& out, const time_b& obj) {
		out << obj.year << "年"
			<< (int)obj.month << "月"
			<< (int)obj.day << "日";
		return out;
	}
};


/*--------------------------------------------------------------------------------
*------------------------------   性别枚举   --------------------------------------*
 --------------------------------------------------------------------------------*/
enum class gender_t
{
	boy,	// 0
	girl,	// 1
	unknown
};

/*--------------------------------------------------------------------------------
*-------------------------   getString的返回类型   --------------------------------*
 --------------------------------------------------------------------------------*/
struct stringInt
{
	vector<string> str;
	int i;
};


/*--------------------------------------------------------------------------------
*------------------------------   机器人类   --------------------------------------*
 --------------------------------------------------------------------------------*/
class Robot 
{
public:
	class Person
	{
	public:
		Person() {};

		// 文件载入数据使用的对象构造
		Person(QQ_T QQ, int goodWill = 0,	//必须的构造参数 
			string name = "",
			gender_t gender = gender_t::unknown,
			time_b birth = { 0, month_t::m1, day_t::d1 });

		virtual ~Person() {};

		// 设置名字
		void setName(string name) { m_name = name; }
		// 设置性别
		void setGender(gender_t gender) { m_gender = gender; }
		// 设置生日
		void setBirth(time_b birth) { 
			m_birth.year = birth.year;
			m_birth.month = birth.month;
			m_birth.day = birth.day;
		}

		// 重载 cout << Person类对象
		friend std::ostream& operator<<(std::ostream& out, const Person& obj) {
			out << "QQ: "<< obj.m_QQ << " (好感度: " << obj.m_goodWill << ")";
			return out;
		}



	private:
		QQ_T m_QQ = 0;	//QQ号
		int m_goodWill = 0;	//好感度
		string m_name = "";	//姓名
		gender_t m_gender = gender_t::unknown;	//性别
		time_b m_birth;	//生日

	};

	Robot();

	// 使用数据初始化机器人初始数据
	Robot(string name, gender_t gender, time_b birth, string* hobby,
		string* likeFood, string* likeSport, string* oral, 
		string dream, Person lover,
		int hobbyNum, int likeFoodNum, int likeSportNum, int oralNum);

	// 使用文件数据初始化机器人初始数据 格式: .ini
	Robot(char* file, char* personfile);
	virtual ~Robot();

	/*--------------------------------------------------------------------------------
	*------------------------------   调用接口   --------------------------------------*
	 --------------------------------------------------------------------------------*/


	// 获取机器人名字
	string getName() const { return m_name; }
	// 获取机器人性别
	gender_t getGender() const { return m_gender; }
	// 获取机器人生日
	time_b getBirth() const { return m_birth; }
	// 获取机器人爱好
	vector<string> getHobby() const { return m_hobby; }
	// 获取机器人喜欢的食物
	vector<string> getLikeFood() const { return m_likeFood; }
	// 获取机器人喜欢的运动
	vector<string> getLikeSport() const { return m_likeSport; }
	// 获取机器人的口头禅
	vector<string> getOral() const { return m_oral; }
	// 获取机器人的梦想
	string getDream() const { return m_dream; }
	// 获取机器人的爱人
	Person getLover() const { return m_lover; }
	

	// 重载 cout << Robot类对象
	friend std::ostream& operator<<(std::ostringstream& out, const Robot& obj) {

		// 写入显示数据
		out << obj.getName() << "\t" << ((bool)obj.getGender() ? "女" : "男") << endl <<
			"生日: " << obj.getBirth() << endl <<
			"爱好: ";
		for (int i = 0; i < obj.m_hobbyNum; ++i) {
			out << obj.getHobby().at(i) << " ";
		}
		out << endl << "喜欢的食物: ";
		for (int i = 0; i < obj.m_likeFoodNum; ++i) {
			out << obj.getLikeFood().at(i) << " ";
		}
		out << endl << "喜欢的运动: ";
		for (int i = 0; i < obj.m_likeSportNum; ++i) {
			out << obj.getLikeSport().at(i) << " ";
		}
		out << endl << "口头禅: ";
		for (int i = 0; i < obj.m_oralNum; ++i) {
			out << obj.getOral().at(i) << " ";
		}
		out << endl << "梦想: " << obj.getDream() << endl 
			<< "爱人: " << obj.getLover() << endl;

		return out;
	}

public:
	//class RobotAsync m_robot;	//机器人线程
private:
	string m_name;	//姓名
	gender_t m_gender;//性别
	time_b m_birth;	//生日
	vector<string> m_hobby;	//爱好
	vector<string> m_likeFood;	//喜欢的食物
	vector<string> m_likeSport;	//喜欢的运动
	vector<string> m_oral;	//口头禅
	string m_dream;	//梦想
	Person m_lover;	//爱人

	int m_hobbyNum = 0;
	int m_likeFoodNum = 0;
	int m_likeSportNum = 0;
	int m_oralNum = 0;
};


/*--------------------------------------------------------------------------------
*----------------------------   全局函数表   -------------------------------------*
 --------------------------------------------------------------------------------*/
 // 实现 int 类型 转 string 类型
extern string to_String(QQ_T n);
// 穷举遍历字符数组
extern stringInt getString(rr::RrConfig config, const char* section, const char* item, const char* default_value);
 
