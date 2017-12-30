#include "gtest/gtest.h"
#include "../StringCommandParser.h"
#include "../FileReader.h"
using namespace std;
TEST(countCharInString,check_space) {
    EXPECT_EQ(1, 1);
    StringCommandParser::comData structttt;
    structttt.comName = "gsdgsdd";
    structttt.comArgs.push_back("1");
    EXPECT_EQ(structttt.comName, "gsdgsdd");
    FileReader fileReader = FileReader();
    string strPort = fileReader.ReadPort("configFileServer.txt");
    StringCommandParser stringCommandParser = StringCommandParser();
    EXPECT_THROW(stringCommandParser.strToNameAndArgc("play play <3>"), const char *);
    EXPECT_THROW(stringCommandParser.strToNameAndArgc("play <3"), const char *);
    EXPECT_THROW(stringCommandParser.strToNameAndArgc("play <3> 4>"), const char *);
    EXPECT_THROW(stringCommandParser.strToNameAndArgc("<3> <4>"), const char *);
    StringCommandParser::comData struct2;
    struct2 = stringCommandParser.strToNameAndArgc("play <3> <4>");
    EXPECT_EQ(struct2.comName, "play");
    EXPECT_EQ(struct2.comArgs[0], "3");
    EXPECT_EQ(struct2.comArgs[1], "4");
}