//
// Created by sean on 12/27/17.
//

#include "StringCommandParser.h"
using namespace std;


StringCommandParser::comData StringCommandParser::strToNameAndArgc(string str) { // !!!!!!!!!!!!!!!!!!! add check for if there is more than one command (word) before the <> thro exception
    istringstream iss(str);
    comData data;
    int countCommandWords = 0;
    data.comName = "";
    if(countCharInString(str,'<') != countCharInString(str,'>'))
        throw "unequal number of < and number of >";

    while (iss)
    {
        string tok;
        iss >> tok;
        if(tok[0] != '<') //check that we have at least one command and not just arguments!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            //if tok is not just a space
            if(!tok.compare(" "))
            {
                data.comName.append(tok);
                countCommandWords++;
                if(countCommandWords > 1)
                    throw "error: more than on word for command name";
            }
        }
        else
        {
            if(tok[tok.length()-1] != '>')
                throw "invalid input";
            else
            {
                if(0 == (tok.length() - 2))
                    throw "empty argument";
                tok = tok.substr(1, tok.length() - 2);
                data.comArgs.push_back(tok);
            }
        }
    }
    return data;
}


int StringCommandParser::countCharInString(string text, char chToCount) {
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