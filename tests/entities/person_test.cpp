#include "entities/person.h"

#include <gtest/gtest.h>

TEST(PersonTest, FullNameTest) {
  person p("Elbert", "Oh");
  const std::string &full_name = p.full_name();
  EXPECT_EQ(full_name, "Elbert Oh");
}
