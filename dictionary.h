#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "map"
#include "list"
#include "string"
#include "initializer.h"
#include "wordlinker.h"

using namespace std;

class Dictionary
{
public:
    Dictionary();
    void create_new(string name, string name2, map<string,string>* words);
    void update_one(string name, string name2, map<string,string>* words);
    void delete_one(string name);
    void reload();
    string find(string name, string name2, string word);
    map<string,string>* find_many(string name, string name2, list<string>* words);
    ~Dictionary()
    {
        delete wordLinker;
        delete initializer;
        for(pair<string, map<long,string>*> const &ent : dictionaries) {
            delete ent.second;
        }
        delete dictionaries;
    }

private:
    map<string, map<long,string>*>* dictionaries;
    Initializer* initializer;
    WordLinker* wordLinker;


};

#endif // DICTIONARY_H
