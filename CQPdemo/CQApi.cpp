#include "CQApi.h"


int CQApi::sendPrivateMag(int64_t QQID, const char* msg)
{
	return CQ_sendPrivateMsg(ac, QQID, msg);
}

int CQApi::sendGroupMsg(int64_t groupid, const char* msg)
{
	return CQ_sendGroupMsg(ac, groupid, msg);;
}

int CQApi::sendDiscussMsg(int64_t discussid, const char* msg)
{
	return CQ_sendDiscussMsg(ac, discussid, msg);
}

int CQApi::deleteMsg(int64_t msgid)
{
	return CQ_deleteMsg(ac, msgid);
}

int CQApi::sendLike(int64_t QQID)
{
	return CQ_sendLike(ac, QQID);
}

int CQApi::setGroupKick(int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest)
{
	return  CQ_setGroupKick(ac, groupid, QQID, rejectaddrequest);
}

int CQApi::setGroupBan(int64_t groupid, int64_t QQID, int64_t duration)
{
	return CQ_setGroupBan(ac, groupid, QQID, duration);
}

int CQApi::setGroupAdmin(int64_t groupid, int64_t QQID, CQBOOL setadmin)
{
	return CQ_setGroupAdmin(ac, groupid, QQID, setadmin);
}

int CQApi::setGroupWholeBan(int64_t groupid, CQBOOL enableban)
{
	return CQ_setGroupWholeBan(ac, groupid, enableban);
}

int CQApi::setGroupAnonymousBan(int64_t groupid, const char* anomymous, int64_t duration)
{
	return CQ_setGroupAnonymousBan(ac, groupid, anomymous, duration);
}

int CQApi::setGroupAnonymous(int64_t groupid, CQBOOL enableanomymous)
{
	return CQ_setGroupAnonymous(ac, groupid, enableanomymous);
}

int CQApi::setGroupCard(int64_t groupid, int64_t QQID, const char* newcard)
{
	return CQ_setGroupCard(ac, groupid, QQID, newcard);
}

int CQApi::setGroupLeave(int64_t groupid, CQBOOL isdismiss)
{
	return CQ_setGroupLeave(ac, groupid, isdismiss);
}

int CQApi::setGroupSpecialTitle(int64_t groupid, int64_t QQID, const char* newspecialtitle, int64_t duration)
{
	return CQ_setGroupSpecialTitle(ac, groupid, QQID, newspecialtitle, duration);
}

int CQApi::setDiscussLeave(int64_t discussid)
{
	return CQ_setDiscussLeave(ac, discussid);
}

int CQApi::setFriendAddRequest(const char* responseflag, int32_t responseoperation, const char* remark)
{
	return CQ_setFriendAddRequest(ac, responseflag, responseoperation, remark);
}

int CQApi::setGroupAddRequestV2(const char* responseflag, int32_t requesttype, int32_t responseoperation, const char* reason)
{
	return CQ_setGroupAddRequestV2(ac, responseflag, requesttype, responseoperation, reason);
}

const char* CQApi::getGroupMemberInfoV2(int64_t groupid, int64_t QQID, CQBOOL nocache)
{
	return CQ_getGroupMemberInfoV2(ac, groupid, QQID, nocache);
}

const char* CQApi::getStrangerInfo(int64_t QQID, CQBOOL nocache)
{
	return CQ_getStrangerInfo(ac, QQID, nocache);
}

int CQApi::addLog(int32_t priority, const char* category, const char* content)
{
	return CQ_addLog(ac, priority, category, content);
}

int64_t CQApi::getLoginQQ()
{
	return CQ_getLoginQQ(ac);
}

const char* CQApi::getLoginNick()
{
	return CQ_getLoginNick(ac);
}

const char* CQApi::getAppDirectory()
{
	return CQ_getAppDirectory(ac);
}

int CQApi::setFatal(const char* errorinfo)
{
	return CQ_setFatal(ac, errorinfo);
}

const char* CQApi::getRecord(const char* file, const char* outformat)
{
	return CQ_getRecord(ac, file, outformat);
}