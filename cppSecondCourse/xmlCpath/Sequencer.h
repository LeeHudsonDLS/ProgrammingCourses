//
// Created by jjc62351 on 07/10/2019.
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <algorithm>

class Sequencer {
public:
    Sequencer(const std::string& xmlTemplateFile);
    int setElement(const std::string& xPath, const std::string& value);
    int setElement(const std::string& xPath, const int& value);
    int setElement(const std::string& xPath, const double& value);
    std::string getXml();
private:
    xmlDocPtr pDoc;
    xmlNodeSetPtr nodeset;
    xmlXPathObjectPtr searchResult;
};


