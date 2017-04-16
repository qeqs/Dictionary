#include "dictionary.h"

Dictionary::Dictionary()
{
    wordLinker = new WordLinker();
    initializer = new Initializer();
    reload();
}

void Dictionary::create_new(string name, string name2, map<string, string> *words)
{

}

void Dictionary::update_one(string name, string name2, map<string, string> *words)
{

}

void Dictionary::delete_one(string name)
{

}

void Dictionary::reload()
{
    dictionaries = initializer->dictionaries();
}

string Dictionary::find(string name, string name2, string word)
{
    map<long,string>* dict1 = dictionaries->find(name);
    map<long,string>* dict2 = dictionaries->find(name2);
    for(pair<long,string> const &ent : dict1) {
        if(ent.second.compare(word)==0){
            return dict2->find(ent.first);
        }
    }
    return string("");
}

map<string, string> *Dictionary::find_many(string name, string name2, list<string> *words)
{
    map<string, string> * result = new map<string, string>();
    for(string const &ent : words) {
            result->insert(pair<string, string>(ent,find(name, name2, ent)));
    }
    return result;
}
