#include "base/uuid.h"

#include <sstream>

#include "boost/uuid/random_generator.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/algorithm/string/erase.hpp"

namespace base {

std::string RandomUuid() {
  boost::uuids::uuid u = boost::uuids::random_generator()();
  std::stringstream ss;
  ss << u;
  return ss.str();
}

std::string SimpleRandomUuid() {
  std::string uuid = RandomUuid();
  boost::erase_all(uuid, "-");
  return uuid.substr(0, 20);
}

}  // namespace base
