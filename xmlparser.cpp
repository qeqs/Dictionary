#include "xmlparser.h"

using namespace tinyxml2;

#ifndef XMLCheckResult
    #define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

XmlParser::XmlParser()
{

}

map<long, string> XmlParser::get_dict(string name)
{
    map<long,string> dict;
    XMLDocument doc;
    doc.LoadFile(name.c_str());

    XMLNode* root = doc.FirstChild();
    if (root == nullptr) return XML_ERROR_FILE_READ_ERROR;

    XMLElement* list = root->FirstChildElement("wordList");
    if (list == nullptr) return XML_ERROR_PARSING_ELEMENT;

    XMLElement* element = list->FirstChildElement("word");
    while(element != nullptr){
        string value = string(element->GetText());
        string key = string(element->Attribute("id"));

        dict.insert(pair<long,string>(stol(key), value));

        element = element->NextSiblingElement("word");
    }
    doc.Clear();

    return dict;
}

void XmlParser::save_dict(map<long, string> dict, string name)
{
    XMLDocument doc;
    XMLNode* root = doc.NewElement("dictionary");
    XMLElement* list = doc.NewElement("wordList");
    for(pair<long,string> const &ent : dict) {
        XMLElement* element = doc.NewElement("word");
        element->SetAttribute("id",ent.first);
        element->SetText(ent.second.c_str());
        list->InsertEndChild(element);
    }

    root->InsertEndChild(list);
    doc.InsertFirstChild(root);

    doc.SaveFile(name.c_str());

    doc.Clear();
}
