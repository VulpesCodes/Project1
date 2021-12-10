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

    evaluateRules();

    std::map<std::string,Relation*> tables = database.getTables();

    std::cout << "Rule Evaluation\n";

    std::string output="";
    std::map<std::string,Relation*>::iterator it;

    for ( int k = 0; k <= pass; ++k) {
        for (unsigned int i = 0; i < datalogProgram.getRules().size(); ++i) {




            for (it = tables.begin(); it != tables.end(); it++) {
                if (it->second->getName() == datalogProgram.getRules()[i].getHeadPred().getID()) {
                    output += datalogProgram.getRules()[i].toString() + "\n";
                    if (it->second->getPass() > k) {
                        output += it->second->toString();

                    }
                }
            }


        }
    }


    std::cout << output;

    //std::cout << database.printString4();

    std::cout << "\nSchemes populated after " + std::to_string(pass+1) + " passes through the Rules\n\n";


    std::cout << "Query Evaluation\n";
    for (unsigned int i = 0; i < datalogProgram.getQueries().size(); ++i) {
        Relation query = evaluatePredicate(datalogProgram.getQueries()[i]);
        std::cout <<  datalogProgram.getQueries()[i].toString() + "? " + query.toStringQ();
        if (i < datalogProgram.getQueries().size()-1) {
            std::cout << "\n";
        }


    }

    /*
std::cout << "\n";
std::cout << database.getTables().find("snap")->second->cross(*database.getTables().find("csg")->second,*database.getTables().find("snap")->second).toString();
std::cout << "\n";
std::cout << "\n";
std::cout << "\n";
std::cout << "rrr";
std::cout << database.getTables().find("snap")->second->join(*database.getTables().find("csg")->second).toString();*/



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

void Interpreter::evaluateRules() {

    bool addedTuples = true;


    while (addedTuples) {
        std::vector<int> numOfRelationsPost;
        std::vector<int> numOfRelationsPre;
        pass++;

        for (unsigned int i = 0; i < datalogProgram.getRules().size(); ++i) {
            Rule currRule = datalogProgram.getRules()[i];
            std::vector<Relation> evaledPred;



            for (unsigned int j = 0; j < currRule.getBodyPred().size(); ++j) {
                evaledPred.push_back(evaluatePredicate(currRule.getBodyPred()[j]));
            }
            for (unsigned int j = 1; j < evaledPred.size(); ++j) {
                evaledPred[0] = evaledPred[0].join(evaledPred[0], evaledPred[j]);
            }



            std::vector<int> projectindex;
            for (unsigned int j = 0; j < currRule.getHeadPred().getID().size(); ++j) {
                for (unsigned int k = 0; k < evaledPred[0].getHeader().getHeaders().size(); ++k) {
                    std::string evalHeader = evaledPred[0].getHeader().getHeaders()[k];
                    std::string ruleHeader;
                    ruleHeader.push_back(currRule.getHeadPred().getID()[j]);
                    if (evalHeader == ruleHeader) {
                        projectindex.push_back((int) k);
                    }
                }
            }

            evaledPred[0] =evaledPred[0].project(projectindex);





            std::vector<std::string> renameHeader;
            for (unsigned int j = 0; j < currRule.getHeadPred().getID().size(); ++j) {
                std::string temp;
                temp.push_back(currRule.getHeadPred().getID()[j]);
                renameHeader.push_back(temp);
            }
            evaledPred[0].setHeader(Header(renameHeader));






            for (auto const& x : database.getTables())
            {
                numOfRelationsPre.push_back((int)x.second->getTuple().size());
            }




            database.getTables().find(currRule.getHeadPred().getID())->second->unionize(evaledPred[0]);
            database.getTables().find(currRule.getHeadPred().getID())->second->setPass(pass);




            for (auto const& x : database.getTables())
            {
                numOfRelationsPost.push_back((int)x.second->getTuple().size());
            }






        }
        for (unsigned int j = 0; j < numOfRelationsPre.size(); ++j) {

            if (numOfRelationsPre[j] == numOfRelationsPost[j]) {
                addedTuples = false;
            }
        }

    }


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