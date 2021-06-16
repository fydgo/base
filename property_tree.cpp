#include "base/property_tree.h"

#include <windows.h>
#include <string>
#include <iostream>

#include "base/encoding.h"

namespace base {

const int kMinNumber = 0;
const int kMaxNumber = 9;

const char* const kScanner = "Scanner";
const char* const kAppPath = "App_Path";
const char* const kAppCmd = "App_Cmd";

void WirteInfoToIniFile(const std::wstring& ini_file_path) {
  using namespace boost::property_tree;

  ptree org_ini_content;
  std::string ini_file = base::Utf16ToUtf8(ini_file_path);
  try {
    ini_parser::read_ini(ini_file, org_ini_content, std::locale::global(std::locale("")));
  } catch (ini_parser_error& ex) {
    //TRACELOG_ERROR("Failed to read DolphinScan.ini file %s with err %s.", ini_file.c_str(), ex.message().c_str());
    return;
  }

  ptree new_ini_content;
  for (auto it = org_ini_content.begin(); it != org_ini_content.end(); ++it) {
    std::string app_path = it->second.get(kAppPath, "");
    if (app_path != "C:\\TW\\TW.exe") {
      std::string third_party_section = it->first;
      ptree third_party_value = org_ini_content.get_child(third_party_section);
      new_ini_content.put_child(third_party_section, third_party_value);
    }
  }

  //TRACELOG_INFORMATION("[Dolphin] Append TW motilities information into DolphinScan.ini.");
  std::string name_part = "DolphinArchScan";
  std::string number_part = "2";
  std::string tw_section = name_part + number_part;

  // Check if the section name is already used.
  if (new_ini_content.find(tw_section) == new_ini_content.not_found()) {
    ptree tw_value;
    tw_value.put<std::string>(kScanner, "cs3700");
    tw_value.put<std::string>(kAppPath, "C:\\TW\\TW.exe");
    tw_value.put<std::string>(kAppCmd, "C:\\TW\\TW.exe");

    new_ini_content.put_child(tw_section, tw_value);
  }

  try {
    write_ini(ini_file, new_ini_content);
  } catch (std::exception& e) {
    //TRACELOG_ERROR("Failed to write new_info to DolphinScan.ini file %s.", e.what());
  }
}

}