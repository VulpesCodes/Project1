//
// Created by iamaw on 11/1/2021.
//

#include "Relation.h"

std::string Relation::toString() {
    std::string output ="";
    for (Tuple t :mySet) {
        for (unsigned int i = 0; i < header.getHeaders().size(); ++i) {
            output+= header.getHeaders()[i] + "=" + t.getTuple()[i] ;
        }
        output += "\n";
    }

    return output;
}

void Relation::addTuple(Tuple tuple) {
    mySet.insert(tuple);
}

void Relation::setHeader(Header input) {
    header = input;
}

Relation::Relation(std::string stringIn, Header headerIn) {
    name = stringIn;
    header = headerIn;
}

std::string Relation::getName() {
    return name;
}

Relation Relation::project(std::vector<int> index) {
    std::vector<std::string> oldHeader= header.getHeaders();
    std::vector<std::string> newHeader;
    std::string newName = "";
    for (unsigned int i = 0; i < index.size(); ++i) {
        newHeader.push_back(oldHeader[index[i]] );
        newName += oldHeader[index[i]];
    }
    Relation projection = Relation(newName,Header(newHeader));
    for (Tuple t :mySet) {
        std::vector<std::string> newTupleData;
        for (unsigned int i = 0; i < index.size(); ++i) {
            newTupleData.push_back(t.getTuple()[index[i]]);
        }
        projection.addTuple(newTupleData);
    }

    return projection;
}

Relation Relation::rename(std::vector<std::string> newHeader) {
    std::string newName = "";
    for (unsigned int i = 0; i < newHeader.size(); ++i) {
        newName += newHeader[i];
    }
    Relation rename = Relation(newName,Header(newHeader));
    for (Tuple t :mySet) {
        std::vector<std::string> newTupleData;
        for (unsigned int i = 0; i < newHeader.size(); ++i) {
            newTupleData.push_back(t.getTuple()[i]);
        }
        rename.addTuple(newTupleData);
    }

    return rename;
}

Relation Relation::select(int index, std::string searchValue) {
    std::string newName = name + std::to_string(index) + searchValue;
    Relation select = Relation(newName,Header(header));
    for (Tuple t :mySet) {
        if (t.getTuple()[index] == searchValue) {
            select.addTuple(t.getTuple());
        }
    }
    return select;
}

Relation Relation::select(int index1, int index2) {
    std::string newName = name + std::to_string(index1) + std::to_string(index2);
    Relation select = Relation(newName,Header(header));
    for (Tuple t :mySet) {
        if (t.getTuple()[index1] == t.getTuple()[index2]) {
            select.addTuple(t.getTuple());
        }
    }
    return select;
}
