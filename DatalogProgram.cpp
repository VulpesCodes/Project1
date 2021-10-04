//
// Created by iamaw on 10/3/2021.
//

#include "DatalogProgram.h"
DatalogProgram::DatalogProgram() {

}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::addFacts(Predicate * input) {
    facts.push_back(input);
}

void DatalogProgram::addQueries(Predicate * input) {
    queries.push_back(input);
}

void DatalogProgram::addRules(Rule * input) {
    rules.push_back(input);
}

void DatalogProgram::addSchemes(Predicate * input) {
    schemes.push_back(input);

}

std::string DatalogProgram::toString() {
    std::string output ="";
    output += "Schemes(" + std::to_string(schemes.size())  + "):\n";
    for (unsigned int i = 0; i < schemes.size(); ++i) {
        output += "\t" + schemes[i]->toString() + "\n";
    }
    output += "Facts(" + std::to_string(facts.size())  + "):\n";
    for (unsigned int i = 0; i < facts.size(); ++i) {
        output += "\t" + facts[i]->toString() + "\n";
    }
    output += "Rules(" + std::to_string(rules.size())  + "):\n";
    for (unsigned int i = 0; i < rules.size(); ++i) {
        output += "\t" + rules[i]->toString() + "\n";
    }
    output += "Queries(" + std::to_string(queries.size())  + "):\n";
    for (unsigned int i = 0; i < queries.size(); ++i) {
        output += "\t" + queries[i]->toString() + "\n";
    }
    return output;
}