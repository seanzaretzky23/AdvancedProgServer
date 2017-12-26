//
// Created by yanivzi on 25/12/17.
//

#include <sstream>
#include "StrCommand.h"
static comData StrToNameAndArgc(string str) { // !!!!!!!!!!!!!!!!!!! add check for if there is more than one command (word) before the <> thro exception
    istringstream iss(str);
    comData data;
    data.comName="";
    if(countCharInString(str,'<')
            !=countCharInString(str,'>'))
        throw "unequal < and >";

    while (iss)
    {
        string tok;
        iss>>tok;
        if(tok[0]!='<')
        {
            data.comName+=tok;
            //data.comName+=" ";
        }
        else
        {
           if(tok[tok.length()-1]!='>')
               throw "invalid input";
           else
           {
               if(1==(tok.length()-2))
                   throw "empty argument";
               tok=tok.substr(1,tok.length()-2);
               data.comArgs.push_back(tok);
           }
        }
    };
    return data;
}

static int countCharInString(string text, char chToCount) {
    string str = text;
    char checkCharacter = chToCount;
    int countChar = 0;
    int i = 0;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == checkCharacter) {
            countChar++;
        }
    }
    return countChar;
}


