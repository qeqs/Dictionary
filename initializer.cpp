#include "initializer.h"

Initializer::Initializer()
{    
    fileHelper = new FileHelper();
    parser = new XmlParser();
}

map<string, map<long, string> *> *Initializer::dictionaries()
{
    map<string, map<long,string>*>* dictionaries = new map<string, map<long,string>*>();

    list<string>* files = fileHelper->find_dictionaries();
    if(files == nullptr) throw new exception("dictionaries not found");

    for(string const &name : files) {
       dictionaries->insert(pair<string, map<long,string>*>(name, parser->get_dict(name)));
    }

    return dictionaries;
}
