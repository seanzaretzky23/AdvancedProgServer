/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROG_READFILE_H
#define ADVANCEDPROG_READFILE_H

#include <string.h>
#include <iostream>
using namespace std;



    /**************************************************************
    * function name: Read data
    * Input: string fileName,string dataName
    * @return string the requested data(dataName data)
    * if there is no dataName or invalid input
    * in the file return empty string ""
    * Function operation: open the file, search to a word
    * dataName, the search for the first num, and add
    * the chars until not a num in port case/
    * not num or dot in serverIP case.
    **************************************************************/
    static std::string ReadData(string fileName,string dataName);

    //if there is no dataName or invalid input in the file return empty string ""
    /**************************************************************
    * function name: ReadIP
    * Input: string fileName,string dataName,defualt serverIP
    * @return string the requested data(dataName data)
    * if there is no dataName or invalid input
    * in the file return empty string ""
    * Function operation: open the file, search to a word
    * dataName, the search for the first num, and add
    * the chars until not a num
    **************************************************************/
    static std::string ReadIP(string fileName,string dataName = "serverIP");

    /**************************************************************
    * function name: Read data
    * Input: string fileName,string dataName
    * @return string the requested data(dataName data)
    * if there is no dataName or invalid input
    * in the file return empty string ""
    * Function operation: open the file, search to a word
    * dataName, the search for the first num, and add
    * the chars until not a num or dot
    **************************************************************/
    static std::string ReadPort(string fileName,string dataName = "port");




#endif //ADVANCEDPROG_READFILE_H
