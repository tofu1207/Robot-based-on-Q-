#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "cqp.h"
#include "RrConfig.h"
#include "appmain.h"

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



	/*
	* ����˽����Ϣ, �ɹ�������ϢID
	* QQID Ŀ��QQ��
	* msg ��Ϣ����
	*/
	static int sendPrivateMag(int64_t QQID, const char* msg);

	/*
	* ����Ⱥ��Ϣ, �ɹ�������ϢID
	* groupid Ⱥ��
	* msg ��Ϣ����
	*/
	static int sendGroupMsg(int64_t groupid, const char* msg);

	/*
	* ������������Ϣ, �ɹ�������ϢID
	* discussid �������
	* msg ��Ϣ����
	*/
	static int sendDiscussMsg(int64_t discussid, const char* msg);

	/*
	* ������Ϣ
	* msgid ��ϢID
	*/
	static int deleteMsg(int64_t msgid);

	/*
	* ������ �����ֻ���
	* QQID QQ��
	*/
	static int sendLike(int64_t QQID);
	
	/*
	* ��ȺԱ�Ƴ�
	* groupid Ŀ��Ⱥ
	* QQID QQ��
	* rejectaddrequest ���ٽ��մ��˼�Ⱥ���룬������
	*/
	static int setGroupKick(int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);

	/*
	* ��ȺԱ����
	* groupid Ŀ��Ⱥ
	* QQID QQ��
	* duration ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0��
	*/
	static int setGroupBan(int64_t groupid, int64_t QQID, int64_t duration);

	/*
	* ��Ⱥ����Ա
	* groupid Ŀ��Ⱥ
	* QQID QQ��
	* setadmin true:���ù���Ա false:ȡ������Ա
	*/
	static int setGroupAdmin(int64_t groupid, int64_t QQID, CQBOOL setadmin);

	/*
	* ��ȫȺ����
	* groupid Ŀ��Ⱥ
	* enableban true:���� false:�ر�
	*/
	static int setGroupWholeBan(int64_t groupid, CQBOOL enableban);

	/*
	* ������ȺԱ����
	* groupid Ŀ��Ⱥ
	* anomymous Ⱥ��Ϣ�¼��յ��� anomymous ����
	* duration ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ����
	*/
	static int setGroupAnonymousBan(int64_t groupid, const char* anomymous, int64_t duration);

	/*
	* ��Ⱥ��������
	* groupid Ŀ��Ⱥ
	* enableanomymous true:���� false:�ر�
	*/
	static int setGroupAnonymous(int64_t groupid, CQBOOL enableanomymous);

	/*
	* ��Ⱥ��Ա��Ƭ
	* groupid Ŀ��Ⱥ
	* QQID Ŀ��QQ
	* newcard ����Ƭ(�ǳ�)
	*/
	static int setGroupCard(int64_t groupid, int64_t QQID, const char* newcard);

	/*
	* ��Ⱥ�˳� ����, �˽ӿ���Ҫ�ϸ���Ȩ
	* groupid Ŀ��Ⱥ
	* isdismiss �Ƿ��ɢ true:��ɢ��Ⱥ(Ⱥ��) false:�˳���Ⱥ(����Ⱥ��Ա)
	*/
	static int setGroupLeave(int64_t groupid, CQBOOL isdismiss);

	/*
	* ��Ⱥ��Աר��ͷ�� ��Ⱥ��Ȩ��
	* groupid Ŀ��Ⱥ
	* QQID Ŀ��QQ
	* newspecialtitle ͷ�Σ����Ҫɾ����������գ�
	* duration ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1��
	*/
	static int setGroupSpecialTitle(int64_t groupid, int64_t QQID, const char* newspecialtitle, int64_t duration);

	/*
	* ���������˳�
	* discussid Ŀ���������
	*/
	static int setDiscussLeave(int64_t discussid);

	/*
	* �ú����������
	* responseflag �����¼��յ��� responseflag ����
	* responseoperation REQUEST_ALLOW �� REQUEST_DENY
	* remark ��Ӻ�ĺ��ѱ�ע
	*/
	static int setFriendAddRequest( const char* responseflag, int32_t responseoperation, const char* remark);

	/*
	* ��Ⱥ�������
	* responseflag �����¼��յ��� responseflag ����
	* requesttype���������¼������������� REQUEST_GROUPADD �� REQUEST_GROUPINVITE
	* responseoperation  REQUEST_ALLOW �� REQUEST_DENY
	* reason �������ɣ��� REQUEST_GROUPADD �� REQUEST_DENY ʱ����
	*/
	static int setGroupAddRequestV2(const char* responseflag, int32_t requesttype, int32_t responseoperation, const char* reason);

	/*
	* ȡȺ��Ա��Ϣ
	* groupid Ŀ��QQ����Ⱥ
	* QQID Ŀ��QQ��
	* nocache ��ʹ�û���
	*/
	static const char* getGroupMemberInfoV2(int64_t groupid, int64_t QQID, CQBOOL nocache);

	/*
	* ȡİ������Ϣ
	* QQID Ŀ��QQ
	* nocache ��ʹ�û���
	*/
	static const char* getStrangerInfo(int64_t QQID, CQBOOL nocache);

	/*
	* ��־  ����������Ϣ�б�
	* priority ���ȼ���CQLOG ��ͷ�ĳ���
	* category ����
	* content ����
	*/
	static int addLog(int32_t priority, const char* category, const char* content);

	/*
	* ȡ��¼QQ
	*/
	static int64_t getLoginQQ();

	/*
	* ȡ��¼QQ�ǳ�
	*/
	static const char* getLoginNick();

	/*
	* ȡӦ��Ŀ¼�����ص�·��ĩβ��"\"
	*/
	static const char* getAppDirectory();

	/*
	* ������������ʾ
	* errorinfo ������Ϣ
	*/
	static int setFatal(const char* errorinfo);

	/*
	* ����������������Ϣ�е�����(record),���ر����� \data\record\ Ŀ¼�µ��ļ���
	* file �յ���Ϣ�е������ļ���(file)
	* outformat Ӧ������������ļ���ʽ��Ŀǰ֧�� mp3 amr wma m4a spx ogg wav flac
	*/
	static const char* getRecord(const char* file, const char* outformat);
	

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
*----------------------------   �����˳�ʼ��   ------------------------------------*
 --------------------------------------------------------------------------------*/
 // ʵ�� int ���� ת string ����
extern string to_String(QQ_T n);

// ��ٱ����ַ�����
extern stringInt getString(rr::RrConfig config, const char* section, const char* item, const char* default_value);
 
