#include "entities/person.h"

#include <iostream>

person::person(std::string_view first_name, std::string_view last_name)
    : first_name(first_name), last_name(last_name) {}

[[nodiscard]] std::string person::full_name() const {
  return this->first_name + " " + this->last_name;
}
