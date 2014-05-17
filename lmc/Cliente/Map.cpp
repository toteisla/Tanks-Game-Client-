#include "Map.h"

void Map::loadMap(){
    file<> xmlFile("Maps/test.tmx");
    xml_document<> doc;
    xml_node<> *rootNode;
    doc.parse<0>(xmlFile.data());
    rootNode = doc.first_node(); //Get the root node

    cout << rootNode->name() << endl;
    
    for(xml_node<> *childNode = rootNode->first_node(); childNode ; childNode = childNode->next_sibling()){ //Go through childs of root node
        cout << "   " << childNode->name() << endl;

        if(strcmp(childNode->name(), "layer") == 0 ){//Get all tiles from layer found.
            
            xml_node<> *data = childNode->first_node();
            cout << "       " << data->name() << endl;

            for(xml_node<> *tile = data->first_node(); tile ; tile = tile->next_sibling()){
                xml_attribute<> *pAttr = tile->first_attribute();
                cout << "           tile " << pAttr->value() << endl;
            }
        }
    }
}