//
// Created by iamaw on 11/1/2021.
//

#ifndef PROJECT1_STARTER_CODE_RELATION_H
#define PROJECT1_STARTER_CODE_RELATION_H
#include <vector>
#include <string>
#include <set>
#include "Header.h"
#include "Tuple.h"

class Relation
{
private:
    std::string name;
    Header header;
    std::set<Tuple> mySet;
    int newRelation = 0;

public:
    Relation(std::string,Header);
    void addTuple(Tuple);
    void setHeader(Header);
    void setPass(int);
    int getPass();

    std::string getName();
    std::string toString();
    std::string toStringQ();
    Header getHeader();
    std::set<Tuple> getTuple();

    Relation select(int,std::string);
    Relation select(int,int);
    Relation project(std::vector<int>);
    Relation rename(std::vector<std::string>);

    Relation join(Relation,Relation);
    Relation cross(Relation,Relation);

    void unionize(Relation);



};

#endif //PROJECT1_STARTER_CODE_RELATION_H
