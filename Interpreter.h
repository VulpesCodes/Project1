//
// Created by iamaw on 11/1/2021.
//

#ifndef PROJECT1_STARTER_CODE_INTERPRETER_H
#define PROJECT1_STARTER_CODE_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include <string>
#include <map>
#include <iostream>

class Interpreter
{
private:
    Database database;
    DatalogProgram datalogProgram;

public:
    Interpreter(DatalogProgram);
    //void addPredicate(Predicate);
    Relation evaluatePredicate(Predicate);
    void evaluateScheme(Predicate);
    void evaluateFact(Predicate);
    void evaluateRules();
    Relation evaluateQueries(Predicate);
    void run();
};

#endif //PROJECT1_STARTER_CODE_INTERPRETER_H
