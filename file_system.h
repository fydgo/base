#ifndef BASE_FILE_SYSTEM_H_
#define BASE_FILE_SYSTEM_H_

#include <string>

namespace base {

bool FileExists(const std::string& utf8_path);
bool FileExists(const std::wstring& utf16_path);


}  // namespace base

#endif  // BASE_FILE_SYSTEM_H_
