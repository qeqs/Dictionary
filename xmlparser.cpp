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

}

void XmlParser::save_dict(map<long, string> dict, string name)
{
    XMLDocument doc;
    XMLNode * root = doc.NewElement("dictionary");
    XMLElement * element = doc.NewElement("word");

    for(auto const &ent : dict) {
        element->SetAttribute(ent.first,ent.second);
    }

    root->InsertEndChild(element);
    doc.InsertFirstChild(root);

    doc.SaveFile(name);
}
