#include "xmlparser.h"
#include "exception"

using namespace tinyxml2;

#ifndef XMLCheckResult
    #define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { throw new exception("xml error", a_eResult); }
#endif

XmlParser::XmlParser()
{

}

map<long, string> *XmlParser::get_dict(string name)
{
    map<long,string>* dict = new map<long,string>();
    XMLDocument doc;
    XMLError err = doc.LoadFile(name.c_str());
    XMLCheckResult(err);

    XMLNode* root = doc.FirstChild();
    if (root == nullptr) throw new exception("file read error",XML_ERROR_FILE_READ_ERROR);

    XMLElement* list = root->FirstChildElement("wordList");
    if (list == nullptr) throw new exception("parsing error",XML_ERROR_PARSING_ELEMENT);

    XMLElement* element = list->FirstChildElement("word");
    while(element != nullptr){
        string value = string(element->GetText());
        string key = string(element->Attribute("id"));

        dict->insert(pair<long,string>(stol(key), value));

        element = element->NextSiblingElement("word");
    }
    doc.Clear();
    delete root;
    delete list;
    delete element;

    return dict;
}

void XmlParser::save_dict(map<long, string> dict, string name)
{
    XMLDocument doc;
    XMLNode* root = doc.NewElement("dictionary");
    XMLElement* list = doc.NewElement("wordList");
    XMLElement* element;
    for(pair<long,string> const &ent : dict) {
        element = doc.NewElement("word");
        element->SetAttribute("id",ent.first);
        element->SetText(ent.second.c_str());
        list->InsertEndChild(element);
    }

    root->InsertEndChild(list);
    doc.InsertFirstChild(root);

    XMLError err = doc.SaveFile(name.c_str());
    XMLCheckResult(err);

    doc.Clear();
    delete root;
    delete list;
    delete element;
}
