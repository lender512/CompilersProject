#include <gtest/gtest.h>

#include <strstream>

#include "FlexScanner.hpp"
#include "parser.hpp"

using namespace utec::compilers;

class ParamTest : public testing::TestWithParam<std::pair<std::string, int>> {};

TEST_P(ParamTest, basicTest) {
  std::istrstream str(GetParam().first.c_str());

  FlexScanner scanner{str, std::cerr};
  int result = 0;
  Parser parser{&scanner, &result};
 
  parser.parse();
  EXPECT_EQ(result, GetParam().second);
}

// INSTANTIATE_TEST_SUITE_P(SimpleTest, ParamTest,
//                          testing::Values(std::make_pair("entero mod(entero a, entero b);", 0),
//                                         std::make_pair("entero mod(entero a, entero b);", 0)));

INSTANTIATE_TEST_SUITE_P(SimpleTest, ParamTest,
                         testing::Values(
                  
                           std::make_pair(
                             "sin_tipo moda(sin_tipo);"
                             "entero mod(entero a, entero b);"
                             "entero mod(entero a, entero b){"
                             "  retorno a - b;"
                             "}"
                             "sin_tipo main(sin_tipo) {  "
                             "entero b;"
                             "entero d;"
                             "b = 1;"
                             "si ( b > 2 ) {"
                             "b = 2;"
                             "si (b != 3) {"
                             "b = 1;"
                             "si (b == 3){"
                             "b = 10;"
                             "}"
                             "sino {"
                             "b = 20;"
                             "}"
                             "}"
                             "}"
                             "si (b != 3) {"
                             "}"
                             "sino {"
                             "b = 8;"
                             "}"
                             "mientras (b != 0) {"
                             "}"
                             "retorno 0;"
                             "}"
                             , 0)
                           )
                         );

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
