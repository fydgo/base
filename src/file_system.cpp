#include "src\file_system.h"

#include "boost\filesystem.hpp"

#include "src\encoding.h"

namespace base {

bool FileExists(const std::string& utf8_path) {
  std::wstring utf16_path = base::Utf8ToUtf16(utf8_path);

  return FileExists(utf16_path);
}

bool FileExists(const std::wstring& utf16_path) {
  return boost::filesystem::exists(utf16_path);
}

}  // namespace base
