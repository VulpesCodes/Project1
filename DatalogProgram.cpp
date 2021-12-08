//
// Created by iamaw on 10/3/2021.
//

#include "DatalogProgram.h"
DatalogProgram::DatalogProgram() {

}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::addFacts(Predicate input) {
    facts.push_back(input);

}

void DatalogProgram::addQueries(Predicate input) {
    queries.push_back(input);
}

void DatalogProgram::addRules(Rule input) {
    rules.push_back(input);
}

void DatalogProgram::addSchemes(Predicate input) {
    schemes.push_back(input);

}

std::vector<Parameter> DatalogProgram::createDomain() {
    std::vector<Parameter> vector;
    for (unsigned int i = 0; i < facts.size(); ++i) {
        Predicate currFact = facts[i];
        for (unsigned int j = 0; j < currFact.returnParameters().size(); ++j) {
            vector.push_back(currFact.returnParameters()[j]);
        }
    }

    return vector;
}

std::string DatalogProgram::toString() {
    std::string output ="";
    output += "Schemes(" + std::to_string(schemes.size())  + "):\n";
    for (unsigned int i = 0; i < schemes.size(); ++i) {
        output += "\t" + schemes[i].toString() + "\n";
    }
    output += "Facts(" + std::to_string(facts.size())  + "):\n";
    for (unsigned int i = 0; i < facts.size(); ++i) {
        output += "\t" + facts[i].toString() + ".\n";
    }
    output += "Rules(" + std::to_string(rules.size())  + "):\n";
    for (unsigned int i = 0; i < rules.size(); ++i) {
        output += "\t" + rules[i].toString() + "\n";
    }
    output += "Queries(" + std::to_string(queries.size())  + "):\n";
    for (unsigned int i = 0; i < queries.size(); ++i) {
        output += "\t" + queries[i].toString() + "?\n";
    }
    domain = createDomain();
    std::set<std::string> domainSet;
    for (unsigned int i = 0; i < domain.size(); ++i) {
        domainSet.insert(domain[i].toString());
    }
    output += "Domain(" + std::to_string(domainSet.size())  + "):\n";
    for (auto i = domainSet.begin(); i != domainSet.end(); ++i) {
        output += "\t" + *i + "\n";
    }
    return output;
}

std::vector<Predicate> DatalogProgram::getSchemes() {
    return schemes;
}

std::vector<Predicate> DatalogProgram::getFacts() {
    return facts;
}

std::vector<Predicate> DatalogProgram::getQueries() {
    return queries;
}

std::vector<Rule> DatalogProgram::getRules() {
    return rules;
}
