/**
	* \file MsdccmbdUasrv.h
	* OPC UA server based on Matrikon FLEX OPC UA SDK for Msdc combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Oct 2018
	* \date modified: 4 Oct 2018
	*/

#ifndef MSDCCMBDUASRV_H
#define MSDCCMBDUASRV_H

#include "RootMsdc.h"

#include <iostream>
#include <stdlib.h>

#include <iuser_permissions_provider_t.h>
#include <iuser_permissions_t.h>

#include <time.h>

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

#include "intrusive_ptr_t.h"
#include "allocatable_t.h"
#include "safe_ref_count_t.h"
#include "itransaction_listener_t.h"
#include "iserver_state_listener_t.h"
#include "iaddress_space_t.h"
#include "opcua_build_info_t.h"
#include "iserver_configuration_t.h"
#include "opcua_user_identity_token_type_t.h"
#include "std_file_t.h"
#include "access_level_t.h"
#include "write_mask_t.h"
#include "ilog_listener_t.h"
#include "certificate_generation_parameters_t.h"
#include "icertificate_private_key_password_provider_t.h"
#include "certificate_validation_options_t.h"
#include "opcua_node_id_numeric_t.h"
#include "uasdk_default_build_config.h"
#include "opcua_qualified_name_t.h"
#include "opcua_bytestring_t.h"
#include "utilities.h"
#include "opcua_guid_t.h"
#include "opcua_boolean_t.h"
#include "opcua_sbyte_t.h"
#include "opcua_byte_t.h"
#include "opcua_int16_t.h"
#include "opcua_uint16_t.h"
#include "opcua_int32_t.h"
#include "opcua_uint32_t.h"
#include "opcua_int64_t.h"
#include "opcua_uint64_t.h"
#include "opcua_float_t.h"
#include "opcua_double_t.h"
#include "uaserver_t.h"
#include "inode_value_attribute_reader_writer_t.h"
#include "localizable_text_stored_t.h"
#include "logger_t.h"
#include "folder_t.h"
#include "base_data_variable_t.h"
#include "inode_attribute_changed_listener_t.h"
#include "inode_attribute_about_to_be_read_listener_t.h"
#include "opcua_localized_text_t.h"
#include "localizable_text_stored_t.h"

#include "method_t.h"
#include "opcua_call_method_request_t.h"
#include "opcua_call_method_result_t.h"
#include "opcua_iruntime_type_t.h"

using namespace uasdk;

/**
	* MsdccmbdUasrv
	*/
namespace MsdccmbdUasrv {
	/**
		* VecVVartype
		*/
	namespace VecVVartype {
		const uint VOID = 1;
		const uint BOOLEAN = 2;
		const uint TINYINT = 3;
		const uint UTINYINT = 4;
		const uint SMALLINT = 5;
		const uint USMALLINT = 6;
		const uint INT = 7;
		const uint UINT = 8;
		const uint BIGINT = 9;
		const uint UBIGINT = 10;
		const uint FLOAT = 11;
		const uint DOUBLE = 12;
		const uint STRING = 13;
		const uint UTINYINTVEC = 14;
		const uint USMALLINTVEC = 15;
		const uint INTVEC = 16;
		const uint UINTVEC = 17;
		const uint UBIGINTVEC = 18;
		const uint FLOATVEC = 19;
		const uint DOUBLEVEC = 20;
		//const uint FLOATMAT = 21;
		//const uint DOUBLEMAT = 22;
		const uint STRINGVEC = 23;
		const uint VECSREF = 24;
	};

	/**
		* Session
		*/
	class Session : public IUserPermissions_t {

	public:
		ubigint jrefM2msess;
		M2msessMsdc::StatShr statshr;

		set<uint> jobaccs;
		map<featix_t,uint> accs;

	public:
		Session();
		~Session() {};

		bool operator==(const IUserPermissions_t& obj) const {UASDK_UNUSED(obj); return true;};

		bool operator!=(const IUserPermissions_t& obj) const {UASDK_UNUSED(obj); return false;};

		void Initialise(const string& sref, const string& Password);

		Status_t GetVariableNodeUserAccessLevel(const IVariableNode_t& node, AccessLevel_t& userAccessLevel) const;

		Status_t SetVariableNodeUserAccessLevel(IVariableNode_t& node, AccessLevel_t userAccessLevel) {return OpcUa_BadNotSupported;};

		Status_t GetNodeUserWriteMask(const INode_t& node, WriteMask_t& userWriteMask) const;

		Status_t SetNodeUserWriteMask(const INode_t& node, WriteMask_t userWriteMask) {return OpcUa_BadNotSupported;};

		Status_t GetNodeUserVisibility(const INode_t& node, bool& visible) const;

		Status_t SetNodeUserVisibility(INode_t& node, bool visible) {return OpcUa_BadNotSupported;};

		Status_t GetMethodNodeUserExecutable(const IMethodNode_t& method, bool& userExecutable) const;

		Status_t SetMethodNodeUserExecutable(IMethodNode_t& method, bool userExecutable) {return OpcUa_BadNotSupported;};
	};

	/**
		* UserPermissionsProvider
		*/
	class UserPermissionsProvider : public IUserPermissionsProvider_t {

	public:
		~UserPermissionsProvider() {};

		Status_t GetUserPermissions(const NodeId_t& sessionId, const String_t& userName, const String_t& password, IntrusivePtr_t<IUserPermissions_t>& userPermissions) const;

		Status_t GetUserPermissions(const NodeId_t& sessionId, const X509IdentityToken_t& userIdentityToken, IntrusivePtr_t<IUserPermissions_t>& userPermissions) const;

		Status_t GetUserPermissions(const NodeId_t& sessionId, const AnonymousIdentityToken_t& userIdentityToken, IntrusivePtr_t<IUserPermissions_t>& userPermissions) const;
	};

	/**
		* ServerStateListener
		*/
	class ServerStateListener : public IServerStateListener_t {

	public:
		void StateHasChanged(ServerState_t::Enum_t state) const;

		void UnhandledError(Status_t errorCode) const;
	};

	/**
		* MethodHandler
		*/
	class MethodHandler : public INodeMethodHandler_t {

	public:
		~MethodHandler() {};

		Status_t CallMethodBegin(IntrusivePtr_t<const NodeId_t> sessionId, uint32_t transactionId, const IUserPermissions_t& userPermissions, uint32_t timeoutHint, IntrusivePtr_t<INode_t>& componentOf, IntrusivePtr_t<IMethodNode_t>& method, IntrusivePtr_t<const CallMethodRequest_t>& requestParameters, IntrusivePtr_t<CallMethodResult_t>& result, IntrusivePtr_t<ICallbackCallMethodCompleted_t>& completedCallback);
	};

	/**
		* ValueAttributeReaderWriter
		*/
	class ValueAttributeReaderWriter : public INodeValueAttributeReaderWriter_t {

	public:
		ValueAttributeReaderWriter() {};

		bool CanReadValueSynchronously(const IVariableNode_t& node) {return true;};

		Status_t ReadValueAttributeBegin(IntrusivePtr_t<const IVariableNode_t>& node, uint32_t maxAge, bool setSourceTimestamp, IntrusivePtr_t<const ArrayUA_t<String_t> >& locales, IntrusivePtr_t<const ArrayRef_t<IndexRange_t> >& indexRange, uint32_t transactionId, uint32_t timeoutHint, IntrusivePtr_t<ICallbackNodeValueAttributeAccessCompleted_t>& completedCallback) {return OpcUa_BadNotSupported;};

		Status_t ReadValueAttribute(const IVariableNode_t& node, uint32_t maxAge, bool setSourceTimestamp, const ArrayUA_t<String_t>& locales, const Array_t<IndexRange_t>& indexRange, uint32_t transactionId, uint32_t timeoutHint, IntrusivePtr_t<DataValue_t>& dataValue, IntrusivePtr_t<DiagnosticInfo_t>& diagnosticInfo);

		bool CanWriteValueSynchronously(const IVariableNode_t& node) {return false;};

		Status_t WriteValueAttributeBegin(IntrusivePtr_t<IVariableNode_t>& node, IntrusivePtr_t<const ArrayRef_t<IndexRange_t> > indexRange, IntrusivePtr_t<const DataValue_t> dataValue, uint32_t transactionId, uint32_t timeoutHint, IntrusivePtr_t<ICallbackNodeValueAttributeAccessCompleted_t>& completedCallback) {return OpcUa_BadNotSupported;};

		Status_t WriteValueAttribute(IVariableNode_t& node, const Array_t<IndexRange_t>& indexRange, IntrusivePtr_t<const DataValue_t> dataValue, uint32_t transactionId, uint32_t timeoutHint, IntrusivePtr_t<DiagnosticInfo_t>& diagnosticInfo) {return OpcUa_BadNotSupported;};
	};

	void* run(void* arg);
	void cleanup(void* arg);

	IntrusivePtr_t<UAServer_t> setupServer(Status_t& result);

	Status_t fillAddressSpace(IntrusivePtr_t<INodeMethodHandler_t>& methodHandler, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter, IntrusivePtr_t<IAddressSpace_t> addressSpace);
	Status_t fAS_addJobFolder(const uint ixMsdcVJob, IntrusivePtr_t<IAddressSpace_t>& addressSpace, IntrusivePtr_t<IObjectNode_t>& objectsFolder, IntrusivePtr_t<IObjectNode_t>& jobFolder);

	Status_t fAS_addVar(const uint ixMsdcVJob, const uint ixMsdcVFeatgroup, const string& srefIxVVar, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter, IntrusivePtr_t<IAddressSpace_t>& addressSpace, IntrusivePtr_t<IObjectNode_t>& jobFolder, vector<string>& srefsSubvars, vector<uint>& icsVVartypeSubvars);
	Status_t fAS_addSubvar(const uint ixVVartype, const uint32_t nref, IntrusivePtr_t<IAddressSpace_t>& addressSpace, IntrusivePtr_t<String_t>& browseNameString, IntrusivePtr_t<BaseDataVariable_t>& subvarObject);

	Status_t fAS_addMethod(const uint ixMsdcVJob, const uint ixMsdcVFeatgroup, const string& srefIxVMethod, IntrusivePtr_t<INodeMethodHandler_t>& methodHandler, IntrusivePtr_t<IAddressSpace_t>& addressSpace, IntrusivePtr_t<IObjectNode_t>& jobFolder, vector<string>& srefsParsInv, vector<uint32_t>& opcUaIdsParsInv, vector<string>& srefsParsRet, vector<uint32_t>& opcUaIdsParsRet);

	void runMethod(const ubigint jref, const uint ixMsdcVFeatgroup, const string& srefIxVMethod, const vector<const void*>& parsInv, const vector<void*>& parsRet);

	extern XchgMsdccmbd* xchg;
	extern IntrusivePtr_t<UAServer_t> uaserver;
	extern bool serverHasFailed;
	extern Refseq nrefseq;
	extern map<uint32_t,IntrusivePtr_t<Session> > sessions;
	extern map<ubigint,uint> ixVFeatgroups;
	extern map<featix_t,DateTime_t> timestamps;
	extern map<uint32_t,uint> jobs;
	extern map<uint32_t,featix_t> methods;
	extern map<uint32_t,featix_t> vars;
	extern map<uint32_t,featix_t> subvarsVars;
	extern map<uint32_t,string> subvars;
};

#endif

