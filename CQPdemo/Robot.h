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
*------------------------------   ����QQ��   --------------------------------------*
 --------------------------------------------------------------------------------*/
extern const QQ_T MASTERQQ;


/*--------------------------------------------------------------------------------
*------------------------------   ʱ������   --------------------------------------*
 --------------------------------------------------------------------------------*/
enum class month_t {	//�·�
	m1 = 1, 
	m2,  m3, 
	m4,  m5, 
	m6,  m7, 
	m8,  m9, 
	m10, m11, 
	m12 
};
enum class day_t {	//��һ�����߰�ʮ��,��ʮһ��������,
					//�����Ŷ���ʮ��,ƽ����¶�ʮ��(�����28��)"
	d1 = 1,
	d2,  d3,  d4,  d5,  d6,  d7,  d8,  d9,
	d10, d11, d12, d13, d14, d15, d16, d17,
	d18, d19, d20, d21, d22, d23, d24, d25,
	d26, d27, d28, d29, d30, d31
};
struct time_b {
	int year;	//���
	month_t month;	//�·�
	day_t day;	//����

	// ���� cout << time_b���ݶ���
	friend std::ostream& operator<<(std::ostream& out, const time_b& obj) {
		out << obj.year << "��"
			<< (int)obj.month << "��"
			<< (int)obj.day << "��";
		return out;
	}
};


/*--------------------------------------------------------------------------------
*------------------------------   �Ա�ö��   --------------------------------------*
 --------------------------------------------------------------------------------*/
enum class gender_t
{
	boy,	// 0
	girl,	// 1
	unknown
};

/*--------------------------------------------------------------------------------
*-------------------------   getString�ķ�������   --------------------------------*
 --------------------------------------------------------------------------------*/
struct stringInt
{
	vector<string> str;
	int i;
};


/*--------------------------------------------------------------------------------
*------------------------------   ��������   --------------------------------------*
 --------------------------------------------------------------------------------*/
class Robot 
{
public:
	class Person
	{
	public:
		Person() {};

		// �ļ���������ʹ�õĶ�����
		Person(QQ_T QQ, int goodWill = 0,	//����Ĺ������ 
			string name = "",
			gender_t gender = gender_t::unknown,
			time_b birth = { 0, month_t::m1, day_t::d1 });

		virtual ~Person() {};

		// ��������
		void setName(string name) { m_name = name; }
		// �����Ա�
		void setGender(gender_t gender) { m_gender = gender; }
		// ��������
		void setBirth(time_b birth) { 
			m_birth.year = birth.year;
			m_birth.month = birth.month;
			m_birth.day = birth.day;
		}

		// ���� cout << Person�����
		friend std::ostream& operator<<(std::ostream& out, const Person& obj) {
			out << "QQ: "<< obj.m_QQ << " (�øж�: " << obj.m_goodWill << ")";
			return out;
		}



	private:
		QQ_T m_QQ = 0;	//QQ��
		int m_goodWill = 0;	//�øж�
		string m_name = "";	//����
		gender_t m_gender = gender_t::unknown;	//�Ա�
		time_b m_birth;	//����

	};

	Robot();

	// ʹ�����ݳ�ʼ�������˳�ʼ����
	Robot(string name, gender_t gender, time_b birth, string* hobby,
		string* likeFood, string* likeSport, string* oral, 
		string dream, Person lover,
		int hobbyNum, int likeFoodNum, int likeSportNum, int oralNum);

	// ʹ���ļ����ݳ�ʼ�������˳�ʼ���� ��ʽ: .ini
	Robot(char* file, char* personfile);
	virtual ~Robot();

	/*--------------------------------------------------------------------------------
	*------------------------------   ���ýӿ�   --------------------------------------*
	 --------------------------------------------------------------------------------*/


	// ��ȡ����������
	string getName() const { return m_name; }
	// ��ȡ�������Ա�
	gender_t getGender() const { return m_gender; }
	// ��ȡ����������
	time_b getBirth() const { return m_birth; }
	// ��ȡ�����˰���
	vector<string> getHobby() const { return m_hobby; }
	// ��ȡ������ϲ����ʳ��
	vector<string> getLikeFood() const { return m_likeFood; }
	// ��ȡ������ϲ�����˶�
	vector<string> getLikeSport() const { return m_likeSport; }
	// ��ȡ�����˵Ŀ�ͷ��
	vector<string> getOral() const { return m_oral; }
	// ��ȡ�����˵�����
	string getDream() const { return m_dream; }
	// ��ȡ�����˵İ���
	Person getLover() const { return m_lover; }
	

	// ���� cout << Robot�����
	friend std::ostream& operator<<(std::ostringstream& out, const Robot& obj) {

		// д����ʾ����
		out << obj.getName() << "\t" << ((bool)obj.getGender() ? "Ů" : "��") << endl <<
			"����: " << obj.getBirth() << endl <<
			"����: ";
		for (int i = 0; i < obj.m_hobbyNum; ++i) {
			out << obj.getHobby().at(i) << " ";
		}
		out << endl << "ϲ����ʳ��: ";
		for (int i = 0; i < obj.m_likeFoodNum; ++i) {
			out << obj.getLikeFood().at(i) << " ";
		}
		out << endl << "ϲ�����˶�: ";
		for (int i = 0; i < obj.m_likeSportNum; ++i) {
			out << obj.getLikeSport().at(i) << " ";
		}
		out << endl << "��ͷ��: ";
		for (int i = 0; i < obj.m_oralNum; ++i) {
			out << obj.getOral().at(i) << " ";
		}
		out << endl << "����: " << obj.getDream() << endl 
			<< "����: " << obj.getLover() << endl;

		return out;
	}

public:
	//class RobotAsync m_robot;	//�������߳�
private:
	string m_name;	//����
	gender_t m_gender;//�Ա�
	time_b m_birth;	//����
	vector<string> m_hobby;	//����
	vector<string> m_likeFood;	//ϲ����ʳ��
	vector<string> m_likeSport;	//ϲ�����˶�
	vector<string> m_oral;	//��ͷ��
	string m_dream;	//����
	Person m_lover;	//����

	int m_hobbyNum = 0;
	int m_likeFoodNum = 0;
	int m_likeSportNum = 0;
	int m_oralNum = 0;
};


/*--------------------------------------------------------------------------------
*----------------------------   ȫ�ֺ�����   -------------------------------------*
 --------------------------------------------------------------------------------*/
 // ʵ�� int ���� ת string ����
extern string to_String(QQ_T n);
// ��ٱ����ַ�����
extern stringInt getString(rr::RrConfig config, const char* section, const char* item, const char* default_value);
 
