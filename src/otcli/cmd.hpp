/* See other files here for the LICENCE that applies here. */
/*
Template for new files, replace word "template" and later delete this line here.
*/

#ifndef INCLUDE_OT_NEWCLI_cmd
#define INCLUDE_OT_NEWCLI_cmd

#include "lib_common1.hpp"

#include "useot.hpp"

namespace nOT {
namespace nNewcli {

INJECT_OT_COMMON_USING_NAMESPACE_COMMON_1; // <=== namespaces

class cCmdParser;
class cCmdProcessing;
class cCmdFormat;
class cCmdData;

class cCmdName;
class cParamInfo;
class cParamString;

class cCmdParser_pimpl;


struct cErrCommandNotFound : public std::runtime_error { cErrCommandNotFound(const string &s) : runtime_error(s) { } };
struct cErrArgMissing : public std::runtime_error { cErrArgMissing(const string &s) : runtime_error(s) { } };

/**
The parser (can be used many times), that should contain some tree of possible commands and format/validation/hint of each.
*/
class cCmdParser : public enable_shared_from_this<cCmdParser> {
	protected:
		unique_ptr< cCmdParser_pimpl > mI;
		void AddFormat( const cCmdName &name, shared_ptr<cCmdFormat> format);

	public:
		cCmdParser();

		cCmdProcessing StartProcessing(const vector<string> &words);
		cCmdProcessing StartProcessing(const string &words);

		shared_ptr<cCmdFormat> FindFormat( const cCmdName &name ) throw(cErrCommandNotFound);

		void Init();
		void Test();
};

/**
Particular instance of process of parsing one input. 
E.g. parsing the input "msg sendfrom rafal dorota 5000" and pointing to standard parser
*/
class cCmdProcessing {
	protected:
		shared_ptr<cCmdParser> mParser; // our "parent" parser to use here

		vector<string> mCommandLine; // the words of command to be parsed

		shared_ptr<cCmdData> mData; // our parsed command as data; NULL if error/invalid
		shared_ptr<cCmdFormat> mFormat; // the selected CmdFormat template; NULL if error/invalid

	public:
		cCmdProcessing(shared_ptr<cCmdParser> parser, vector<string> commandLine);

		void Parse(); // parse into mData, mFormat

		vector<string> UseComplete( nUse::cUseOT &use ); 
		void UseExecute( nUse::cUseOT &use );
};

/** 
A function to be executed that will do some actuall OT call <- e.g. execute this on "ot msg ls"
*/
class cCmdExecutable {  
	public:
		typedef int tExitCode;
		typedef std::function< tExitCode ( shared_ptr<cCmdData> , nUse::cUseOT & ) > tFunc;
	public:
		const static cCmdExecutable::tExitCode sSuccess;
	private:
		tFunc mFunc;
	public:
		cCmdExecutable( tFunc func );

		tExitCode operator()( shared_ptr<cCmdData> , nUse::cUseOT & use );
};

/**
Describes template how given command arguments should look like (validation, hint)
*/
class cCmdFormat {
	public:
		typedef vector<cParamInfo> tVar;
		typedef map<string, cParamInfo> tOption;
		
	protected:
		tVar mVar, mVarExt;
		tOption mOption;

		cCmdExecutable mExec;

	public:
		cCmdFormat(cCmdExecutable exec, tVar var, tVar varExt, tOption opt);

		cCmdExecutable getExec() const;
};

/**
The parsed and interpreted data of command, arguments and options are ready in containers etc.
*/
class cCmdData {
	public:
		typedef vector<string> tVar;
		typedef map<string, vector<string> > tOption; // even single (not-multi) options will be placed in vector (1-element)
		
	protected:
		tVar mVar, mVarExt;
		tOption mOption;

		friend class cCmdProcessing; // it will fill-in this class fields directly

		string VarGetOrThrow(int nr, const string &def, bool doThrow) const throw(cErrArgMissing); // nr: 1,2,3,4 including both arg and argExt

	public:
		cCmdData()=default;

		string VarDef(int nr, const string &def="",  bool doThrow=0) const noexcept; // nr: 1,2,3,4 including both arg and argExt
		vector<string> OptIf(const string& name) const noexcept;

		string Var(int nr) const throw(cErrArgMissing); // nr: 1,2,3,4 including both arg and argExt
		vector<string> Opt(const string& name) const throw(cErrArgMissing);
};

// ============================================================================

/**
Name of command like "msg sendfrom"
*/
class cCmdName {
	protected:
		string mName;
	public:
		cCmdName(const string &name);
		
		bool operator<(const cCmdName &other) const;
		operator std::string() const;	
};


/**
Info about Parameter: How to validate and how to complete this argument
*/
class cParamInfo {
	public:
		typedef function< bool ( nUse::cUseOT &, cCmdData &, int, const string &  ) > tFuncValid;
		typedef function< vector<string> ( nUse::cUseOT &, cCmdData &, int, const string &  ) > tFuncHint;

	protected:
		tFuncValid funcValid;
		tFuncHint funcHint;

	public:
		cParamInfo()=default;
		cParamInfo(tFuncValid valid, tFuncHint hint);
};


void cmd_test();




}; // namespace nNewcli
}; // namespace nOT


#endif
