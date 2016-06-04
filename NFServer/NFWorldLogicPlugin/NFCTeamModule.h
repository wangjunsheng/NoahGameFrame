// -------------------------------------------------------------------------
//    @FileName      :    NFITeamModule.h
//    @Author           :    Chuanbo.Guo
//    @Date             :    2016-01-30 08:51
//    @Module           :   NFITeamModule
//
// -------------------------------------------------------------------------

#ifndef NFC_TEAM_MODULE_H
#define NFC_TEAM_MODULE_H

#include "NFComm/NFCore/NFMap.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFITeamModule.h"
#include "NFComm/NFPluginModule/NFIUUIDModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFITeamDataModule.h"
#include "NFComm/NFPluginModule/NFIWorldNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFICommonRedisModule.h"
#include "NFComm/NFPluginModule/NFIClusterModule.h"

class NFCTeamModule
    : public NFITeamModule
{
public:
	NFCTeamModule(NFIPluginManager* p)
    {
        pPluginManager = p;
        mnScenceID = 400;
    }

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();

    virtual bool AfterInit();

	virtual const NFGUID& CreateTeam( const NFGUID& self, const NFGUID& xDefaultTeamID, const std::string& strName, const std::string& strRoleName, const int nLevel, const int nJob , const int nDonation , const int nVIP);
	virtual bool JoinTeam(const NFGUID& self, const NFGUID& xTeamID);
	virtual bool LeaveTeam(const NFGUID& self, const NFGUID& xTeamID);
	virtual bool KickTeamMmember(const NFGUID& self, const NFGUID& xTeamID, const NFGUID& xMmember);

    virtual bool GetPlayerGameID(const NFGUID& self, int& nGameID);
    virtual bool GetOnlineMember(const NFGUID& self, const NFGUID& xTeam, NFCDataList& varMemberList, NFCDataList& varGameList);
    virtual bool MemberOnline(const NFGUID& self, const NFGUID& xTeam, const int& nGameID);
    virtual bool MemberOffeline(const NFGUID& self, const NFGUID& xTeam);

protected:
	void OnCreateTeamProcess(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnJoinTeamProcess(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnLeaveTeamProcess(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnOprTeamMemberProcess(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

protected:
    int mnScenceID;

protected:
    NFIKernelModule* m_pKernelModule;
    NFIUUIDModule* m_pUUIDModule;
	NFIWorldNet_ServerModule* m_pWorldNet_ServerModule;
	NFILogModule* m_pLogModule;
	NFITeamDataModule* m_pTeamDataModule;
    NFICommonRedisModule* m_pCommonRedisModule;
    NFIClusterModule* m_pClusterSQLModule;
};

#endif