//
// Created by sean on 12/27/17.
//

#ifndef ADVANCEDPROGSERVER_FILEREADER_H
#define ADVANCEDPROGSERVER_FILEREADER_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

class FileReader {


public:
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
std::string ReadData(std::string fileName, std::string dataName);

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
std::string ReadIP(std::string fileName, std::string dataName = "serverIP");

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
std::string ReadPort(std::string fileName, std::string dataName = "port");
};


#endif //ADVANCEDPROGSERVER_FILEREADER_H
