#include <gtest/gtest.h>

#include <strstream>
#include <iostream>
#include <fstream>
#include "FlexScanner.hpp"
#include "parser.hpp"
#include <filesystem>
#include <unistd.h>

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

   std::ifstream file("../tests/" + filename);
   if (!file.is_open()){
      std::cout << "Error opening file, cd to the project root";
      exit(1);
   }

    std::string temp;
    std::string input;
    while(std::getline(file, temp)) {
          input += temp + "\n";
    }
    return input;  
}

INSTANTIATE_TEST_SUITE_P(SimpleTest, ParamTest,
                         testing::Values(
                          std::make_pair(readFromFile("test2.ce"), 0),
                          std::make_pair(readFromFile("test1.ce"), 0)
                          )
                        //    std::make_pair(readFromFile("test2.ce"), 0),
                        //    std::make_pair(
                        //       "entero j; \n"
                        //       "entero l; \n"
                        //       "sin_tipo main(entero mama, entero mams , entero ka);"
                        //       "sin_tipo moda(sin_tipo) { \n"
                        //         "entero b; \n"
                        //         "entero c; \n"
                        //         "entero a; \n"
                        //         "a = 2;     \n"
                        //         "}\n" , 0)
                        // )
                         );

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
