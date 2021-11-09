//
// Created by iamaw on 11/1/2021.
//

#include "Database.h"

void Database::addRelation(Relation * input) {
    tables.insert(std::pair<std::string,Relation*>(input->getName(),input));
}

std::string Database::printRelation(std::string input) {
    std::string output ="";
    output = tables.find(input)->second->toString();
    return output;
}

std::map<std::string, Relation *> Database::getTables() {
    return tables;
}

std::string Database::printString() {
    std::string output="";
    std::map<std::string,Relation*>::iterator it;
    for (it = tables.begin(); it != tables.end(); it++)
    {
        output+= it->second->toString() + "\n";
    }
    return output;
}
