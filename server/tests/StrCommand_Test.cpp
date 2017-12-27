#include "gtest/gtest.h"
#include "../StringCommandParser.h"
#include "../FileReader.h"
using namespace std;
TEST(countCharInString,check_space)
{
        EXPECT_EQ(1, 1);
        StringCommandParser::comData structttt;
        structttt.comName = "gsdgsdd";
        structttt.comArgs.push_back("1");
        EXPECT_EQ(structttt.comName, "gsdgsdd");
        FileReader fileReader = FileReader();
        string strPort = fileReader.ReadPort("configFileServer.txt");
        StringCommandParser stringCommandParser = StringCommandParser();
        EXPECT_EQ(stringCommandParser.countCharInString("play <3> <4>", '<'), 2);
        EXPECT_THROW(stringCommandParser.strToNameAndArgc("play play <3>"), const char *);
        try {
            StringCommandParser::comData struct2;
            struct2 = stringCommandParser.strToNameAndArgc("play <3> <4>");
            string x, y;
            x = struct2.comArgs[0];
            y = struct2.comArgs[1];
            EXPECT_EQ(struct2.comName, "play");
            EXPECT_EQ(x, "3");
            EXPECT_EQ(y, "4");
        } catch (const char * exception1){
            cout << exception1 << endl;
            //cout << exception1.what() << endl;
        }
        catch (...) {
            cout << "here 3" << endl;
        }
}