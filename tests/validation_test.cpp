#include <gtest/gtest.h>

#include <strstream>
#include <iostream>
#include <fstream>
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

std::string readFromFile(std::string filename) {
  
   std::ifstream file("../../tests/" + filename);
    std::string temp;
    std::string input;
    while(std::getline(file, temp)) {
          input += temp + "\n";
    }
    return input;  
}

INSTANTIATE_TEST_SUITE_P(SimpleTest, ParamTest,
                         testing::Values(
                           std::make_pair(readFromFile("test1.ce"), 0)
                        //    std::make_pair(readFromFile("test2.ce"), 0),
                        //   std::make_pair(
                        //      "sin_tipo moda(sin_tipo) {\n"
                        //        "entero b;} \n"
                        //        "entero c; \n"
                        //        "entero a; \n"
                        //        "a = 2;     \n"
                        //        "}\n" , 0)
                        )
                         );

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
