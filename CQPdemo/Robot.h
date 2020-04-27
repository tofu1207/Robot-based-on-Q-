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



	/*
	* 发送私聊消息, 成功返回消息ID
	* QQID 目标QQ号
	* msg 消息内容
	*/
	static int sendPrivateMag(int64_t QQID, const char* msg);

	/*
	* 发送群消息, 成功返回消息ID
	* groupid 群号
	* msg 消息内容
	*/
	static int sendGroupMsg(int64_t groupid, const char* msg);

	/*
	* 发送讨论组消息, 成功返回消息ID
	* discussid 讨论组号
	* msg 消息内容
	*/
	static int sendDiscussMsg(int64_t discussid, const char* msg);

	/*
	* 撤回消息
	* msgid 消息ID
	*/
	static int deleteMsg(int64_t msgid);

	/*
	* 发送赞 发送手机赞
	* QQID QQ号
	*/
	static int sendLike(int64_t QQID);
	
	/*
	* 置群员移除
	* groupid 目标群
	* QQID QQ号
	* rejectaddrequest 不再接收此人加群申请，请慎用
	*/
	static int setGroupKick(int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);

	/*
	* 置群员禁言
	* groupid 目标群
	* QQID QQ号
	* duration 禁言的时间，单位为秒。如果要解禁，这里填写0。
	*/
	static int setGroupBan(int64_t groupid, int64_t QQID, int64_t duration);

	/*
	* 置群管理员
	* groupid 目标群
	* QQID QQ号
	* setadmin true:设置管理员 false:取消管理员
	*/
	static int setGroupAdmin(int64_t groupid, int64_t QQID, CQBOOL setadmin);

	/*
	* 置全群禁言
	* groupid 目标群
	* enableban true:开启 false:关闭
	*/
	static int setGroupWholeBan(int64_t groupid, CQBOOL enableban);

	/*
	* 置匿名群员禁言
	* groupid 目标群
	* anomymous 群消息事件收到的 anomymous 参数
	* duration 禁言的时间，单位为秒。不支持解禁。
	*/
	static int setGroupAnonymousBan(int64_t groupid, const char* anomymous, int64_t duration);

	/*
	* 置群匿名设置
	* groupid 目标群
	* enableanomymous true:开启 false:关闭
	*/
	static int setGroupAnonymous(int64_t groupid, CQBOOL enableanomymous);

	/*
	* 置群成员名片
	* groupid 目标群
	* QQID 目标QQ
	* newcard 新名片(昵称)
	*/
	static int setGroupCard(int64_t groupid, int64_t QQID, const char* newcard);

	/*
	* 置群退出 慎用, 此接口需要严格授权
	* groupid 目标群
	* isdismiss 是否解散 true:解散本群(群主) false:退出本群(管理、群成员)
	*/
	static int setGroupLeave(int64_t groupid, CQBOOL isdismiss);

	/*
	* 置群成员专属头衔 需群主权限
	* groupid 目标群
	* QQID 目标QQ
	* newspecialtitle 头衔（如果要删除，这里填空）
	* duration 专属头衔有效期，单位为秒。如果永久有效，这里填写-1。
	*/
	static int setGroupSpecialTitle(int64_t groupid, int64_t QQID, const char* newspecialtitle, int64_t duration);

	/*
	* 置讨论组退出
	* discussid 目标讨论组号
	*/
	static int setDiscussLeave(int64_t discussid);

	/*
	* 置好友添加请求
	* responseflag 请求事件收到的 responseflag 参数
	* responseoperation REQUEST_ALLOW 或 REQUEST_DENY
	* remark 添加后的好友备注
	*/
	static int setFriendAddRequest( const char* responseflag, int32_t responseoperation, const char* remark);

	/*
	* 置群添加请求
	* responseflag 请求事件收到的 responseflag 参数
	* requesttype根据请求事件的子类型区分 REQUEST_GROUPADD 或 REQUEST_GROUPINVITE
	* responseoperation  REQUEST_ALLOW 或 REQUEST_DENY
	* reason 操作理由，仅 REQUEST_GROUPADD 且 REQUEST_DENY 时可用
	*/
	static int setGroupAddRequestV2(const char* responseflag, int32_t requesttype, int32_t responseoperation, const char* reason);

	/*
	* 取群成员信息
	* groupid 目标QQ所在群
	* QQID 目标QQ号
	* nocache 不使用缓存
	*/
	static const char* getGroupMemberInfoV2(int64_t groupid, int64_t QQID, CQBOOL nocache);

	/*
	* 取陌生人信息
	* QQID 目标QQ
	* nocache 不使用缓存
	*/
	static const char* getStrangerInfo(int64_t QQID, CQBOOL nocache);

	/*
	* 日志  可做多条信息判别
	* priority 优先级，CQLOG 开头的常量
	* category 类型
	* content 内容
	*/
	static int addLog(int32_t priority, const char* category, const char* content);

	/*
	* 取登录QQ
	*/
	static int64_t getLoginQQ();

	/*
	* 取登录QQ昵称
	*/
	static const char* getLoginNick();

	/*
	* 取应用目录，返回的路径末尾带"\"
	*/
	static const char* getAppDirectory();

	/*
	* 置致命错误提示
	* errorinfo 错误信息
	*/
	static int setFatal(const char* errorinfo);

	/*
	* 接收语音，接收消息中的语音(record),返回保存在 \data\record\ 目录下的文件名
	* file 收到消息中的语音文件名(file)
	* outformat 应用所需的语音文件格式，目前支持 mp3 amr wma m4a spx ogg wav flac
	*/
	static const char* getRecord(const char* file, const char* outformat);
	

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
*----------------------------   机器人初始化   ------------------------------------*
 --------------------------------------------------------------------------------*/
 // 实现 int 类型 转 string 类型
extern string to_String(QQ_T n);

// 穷举遍历字符数组
extern stringInt getString(rr::RrConfig config, const char* section, const char* item, const char* default_value);
 
