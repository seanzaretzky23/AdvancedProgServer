#include "gtest/gtest.h"
#include "../StringCommandParser.h"
#include "../FileReader.h"
using namespace std;

TEST(comData_check,check1) {
    StringCommandParser::comData structttt;
    structttt.comName = "gsdgsdd";
    structttt.comArgs.push_back("1");
    EXPECT_EQ(structttt.comName, "gsdgsdd");
}

TEST(fileReader_check,check1) {
    FileReader fileReader = FileReader();
    string strPort = fileReader.ReadPort("configFileServer.txt");
    EXPECT_EQ(strPort, "8000");
}

TEST(strCommandParser_check,check1) {
    StringCommandParser stringCommandParser = StringCommandParser();
    EXPECT_THROW(stringCommandParser.strToNameAndArgc(""), const char *);
    EXPECT_THROW(stringCommandParser.strToNameAndArgc(" "), const char *);
    StringCommandParser::comData struct2;
    struct2 = stringCommandParser.strToNameAndArgc("play 3 4");
    EXPECT_EQ(struct2.comName, "play");
    EXPECT_EQ(struct2.comArgs[0], "3");
    EXPECT_EQ(struct2.comArgs[1], "4");
}