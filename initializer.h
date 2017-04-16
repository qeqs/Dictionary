#ifndef INITIALIZER_H
#define INITIALIZER_H
#include "map"
#include "list"
#include "string"
#include "filehelper.h"
#include "xmlparser.h"

class Initializer
{
public:
    Initializer();
    map<string, map<long,string>*>* dictionaries();
private:
    FileHelper* fileHelper;
    XmlParser* parser;
};

#endif // INITIALIZER_H
