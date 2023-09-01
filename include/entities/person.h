#pragma once

#include <cstdint>
#include <string>
#include <string_view>

class person {
 public:
  std::string first_name;
  std::string last_name;

  person(std::string_view first_name, std::string_view last_name);

  [[nodiscard]] std::string full_name() const;
};
