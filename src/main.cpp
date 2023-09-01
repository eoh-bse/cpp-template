#include <iostream>
#include <istream>

#include "entities/person.h"

#define NAME_LEN 64

int main() {
  char first_name[NAME_LEN], last_name[NAME_LEN];

  std::cout << "Enter your first name: ";
  std::cin.getline(first_name, NAME_LEN);

  std::cout << "Enter your last name: ";
  std::cin.getline(last_name, NAME_LEN);

  person person{first_name, last_name};
  std::cout << "Your full name: " << person.full_name() << '\n';
}
