// Distributed under the MIT License (See
// accompanying file "LICENSE" or the website
// http://www.opensource.org/licenses/mit-license.php)

#pragma once

#include "../Utility/StringUtils.h"

namespace Assets { class DirectorySearchRules; }
namespace ShaderPatcher
{
	std::string ReadGraphSyntax(StringSection<char> input, const ::Assets::DirectorySearchRules& searchRules);
}
