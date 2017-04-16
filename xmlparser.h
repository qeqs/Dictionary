#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "tinyxml2.h"
#include "map"
#include "string"


using namespace std;

class XmlParser
{
public:
    XmlParser();
    map<long,string>* get_dict(string name);
    void save_dict(map<long, string> dict, string name);
};

#endif // XMLPARSER_H
