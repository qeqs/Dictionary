#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "constants.h"
#include "list"
#include "string"

using namespace std;

class FileHelper
{
public:
    FileHelper();
    static list<string>* find_dictionaries();
};

#endif // FILEHELPER_H
