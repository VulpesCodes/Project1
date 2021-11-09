//
// Created by iamaw on 11/1/2021.
//

#ifndef PROJECT1_STARTER_CODE_DATABASE_H
#define PROJECT1_STARTER_CODE_DATABASE_H

#include <map>
#include "Relation.h"
#include <iterator>

class Database
{
private:
    std::map<std::string,Relation*> tables;


public:
    void addRelation(Relation*);
    std::string printRelation(std::string);
    std::map<std::string,Relation*> getTables();
    std::string printString();

};

#endif //PROJECT1_STARTER_CODE_DATABASE_H
