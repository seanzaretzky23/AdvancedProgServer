/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "FileReader.h"
using namespace std;
string FileReader::ReadData(std::string fileName, std::string dataName) {
    ifstream inFile;
    string buffer;
    char chBuf;
    int kind;
    if(!strcmp(dataName.c_str(),"serverIP"))
        kind=1;
    if(!strcmp(dataName.c_str(),"port"))
        kind=2;
    string outputData;
    inFile.open(fileName.c_str());
    if (!inFile.is_open()) {
        throw ("file \"" + fileName + "\" doesnt exist").c_str();
    }
    inFile>>buffer;
    //if the file not containing the data name return empty string ""
    while((strcmp(buffer.c_str(),dataName.c_str())!=0)&&(!inFile.eof()))
    {
        inFile>>buffer;
    }
    //if we got to eof return empty string
    if(inFile.eof())
        return "";
    inFile>>chBuf;
    while(!((chBuf>='0')&&(chBuf<='9')))
    {
        inFile>>chBuf;
    }
    switch (kind) {
        case 1 :
            //IP_Case
            while (((chBuf == '.') || ((chBuf >= '0') && (chBuf <= '9')))
                   &&(!inFile.eof())) {
                outputData.push_back(chBuf);
                inFile >> chBuf;
            }
            break;
        case 2:
            //PortCase
            while (((chBuf >= '0') && (chBuf <= '9'))&&(!inFile.eof())) {
                outputData.push_back(chBuf);
                inFile >> chBuf;
            }
            break;
        default:
            return "";
    }
    inFile.close();
    return outputData;
}

string FileReader::ReadIP(std::string fileName, std::string dataName) {
    return ReadData(fileName, dataName);
}

string FileReader::ReadPort(std::string fileName, std::string dataName) {
    return ReadData(fileName, dataName);
}