#ifndef BASE_PROPERTY_TREE_H_
#define BASE_PROPERTY_TREE_H_

#include <string>

#include "boost/property_tree/ini_parser.hpp"

namespace base {

void WirteInfoToIniFile(const std::wstring& ini_file_path);
}

#endif // BASE_PROPERTY_TREE_H_