//
// Created by yanivzi on 25/12/17.
//

#ifndef UNTITLED_STRCOMMAND_H
#define UNTITLED_STRCOMMAND_H

#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

struct comData
{
    string comName;
    vector<string> comArgs;
};

static comData StrToNameAndArgc(string str);
static int countCharInString(string str, char ch);


#endif UNTITLED_STRCOMMAND_H
