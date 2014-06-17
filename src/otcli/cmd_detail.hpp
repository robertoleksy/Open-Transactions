/* See other files here for the LICENCE that applies here. */
/* See header file .hpp for info */

#include "cmd.hpp"

#include "lib_common2.hpp"
#include "ccolor.hpp"

namespace nOT {
namespace nNewcli {
INJECT_OT_COMMON_USING_NAMESPACE_COMMON_2; // <=== namespaces
using namespace nUse;
// ========================================================================================================================

class cCmdParser_pimpl {
	friend class cCmdParser;

	typedef map< cCmdName , shared_ptr<cCmdFormat> >::value_type tTreePair; // type of element (pair) in tree-map. TODO: will be not needed in C+11 map emplace
	typedef	map< cCmdName , shared_ptr<cCmdFormat> > tTree;

	map<string , cParamInfo> mCommonOpt; // will be added by default to all formats

	private:
		tTree mTree;
};

} // namespace 
} // namespace 
