//
// Created by iamaw on 11/1/2021.
//

#include "Interpreter.h"


Interpreter::Interpreter(DatalogProgram input) {
    datalogProgram = input;
}

void Interpreter::evaluateScheme(Predicate p) {
    std::vector<std::string> header;
    for (unsigned int i = 0; i < p.returnParameters().size(); ++i) {
        header.push_back(p.returnParameters()[i].toString());
    }
    Relation *newScheme = new Relation(p.getID(),Header(header));
    database.addRelation(newScheme);
}

void Interpreter::evaluateFact(Predicate p) {
    std::vector<std::string> parameters;
    for (unsigned int i = 0; i < p.returnParameters().size(); ++i) {
        parameters.push_back(p.returnParameters()[i].toString());
    }
    Relation *table = database.getTables().find(p.getID())->second;
    table->addTuple(Tuple(parameters));
}

void Interpreter::run() {
    for (unsigned int i = 0; i < datalogProgram.getSchemes().size(); ++i) {
        evaluateScheme(datalogProgram.getSchemes()[i]);

    }
    for (unsigned int i = 0; i < datalogProgram.getFacts().size(); ++i) {
        evaluateFact(datalogProgram.getFacts()[i]);

    }
    //std::cout << database.printString();

    for (unsigned int i = 0; i < datalogProgram.getQueries().size(); ++i) {
        Relation query = evaluatePredicate(datalogProgram.getQueries()[i]);
        std::cout <<  datalogProgram.getQueries()[i].toString() + "? " + query.toStringQ();
        if (i < datalogProgram.getQueries().size()-1) {
            std::cout << "\n";
        }


    }
    std::cout << "\n";
    std::cout << database.getTables().find("snap")->second->cross(*database.getTables().find("csg")->second,*database.getTables().find("snap")->second).toString();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "rrr";
    std::cout << database.getTables().find("snap")->second->join(*database.getTables().find("csg")->second).toString();



}

Relation Interpreter::evaluatePredicate(Predicate p) {    //TEMP
    /*std::vector<int> tempTest;
    tempTest.push_back(0);
    std::vector<std::string> tempTest2;
    std::string tempTest3 = "'c'";
    tempTest2.push_back("HELLO");
    tempTest2.push_back("C");
    std::cout<< database.getTables().find("SK")->second->select(1,tempTest3).toString() + "select1\n";
    std::cout<< database.getTables().find("SK")->second->select(0,1).toString() + "selecet2\n";
    std::cout<< database.getTables().find("SK")->second->project(tempTest).toString() + "project\n";
    std::cout<< database.getTables().find("SK")->second->rename(tempTest2).toString() + "rename\n";

    return database.getTables().find("SK")->second->project(tempTest);
     */
    Relation* relation = new Relation(*database.getTables().find(p.getID())->second);
    std::map<std::string,int> variableMap;
    std::vector<int> indexOrder;
    std::vector<std::string> variableNames;
    for (unsigned int i = 0; i < p.returnParameters().size(); ++i) {

        if (p.returnParameters()[i].toString()[0] == '\'') {
            *relation = relation->select(i,p.returnParameters()[i].toString());
        }
        else if ( variableMap.find(p.returnParameters()[i].toString()) == variableMap.end() ) {
            std::string key = p.returnParameters()[i].toString();
            variableMap.insert(std::pair<std::string,int>(key,i));
            indexOrder.push_back(i);
            variableNames.push_back(p.returnParameters()[i].toString());
        }
        else if (variableMap.find(p.returnParameters()[i].toString()) != variableMap.end()) {
            *relation = relation->select(variableMap.find(p.returnParameters()[i].toString())->second,i);
        }
    }

    if (indexOrder.size() > 0) {
        relation = new Relation(relation->project(indexOrder));
        relation = new Relation(relation->rename(variableNames));
    }
    else {
        relation = new Relation(relation->project(indexOrder));
        relation = new Relation(relation->rename(variableNames));
    }





    return *relation;
}

Relation Interpreter::evaluateQueries(Predicate p) {
    return evaluatePredicate(p);
}

/*void Interpreter::addPredicate(Predicate p) {
    std::vector<std::string> header;
    std::string dummyString = "";
    for (unsigned int i = 0; i < p.getID().size(); ++i) {
        header.push_back(dummyString.insert(0,1,p.getID()[i]));
        dummyString = "";
    }
    Relation *editRelation = nullptr;
    if (database.getTables().find(p.getID()) == database.getTables().end()) {
        editRelation = new Relation(p.getID(), Header(header));
    }
    else {
       editRelation = database.getTables().find(p.getID())->second;

    }

}
*/