#ifndef BASE_ENCODING_H_
#define BASE_ENCODING_H_

#include <string>

namespace base {
// Convert UTF16 to UTF8.
std::string Utf16ToUtf8(const std::wstring& utf16_string);

// Convert UTF8 to UTF16.
std::wstring Utf8ToUtf16(const std::string& utf8_string);

}  // namespace base

#endif  // BASE_ENCODING_H_
