#pragma once

#include "stdafx.h"
#include "appmain.h"
#include "cqp.h"

class CQApi
{
public:
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
	static int setFriendAddRequest(const char* responseflag, int32_t responseoperation, const char* remark);

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
};

