//
// Created by iamaw on 11/1/2021.
//

#include "Relation.h"

std::string Relation::toString() {
    std::string output ="";
    for (Tuple t :mySet) {
        output+= "\t";
        for (unsigned int i = 0; i < header.getHeaders().size(); ++i) {
            if (i >= 1) {
                output+= ", ";
            }
            output+= header.getHeaders()[i] + "=" + t.getTuple()[i] ;

        }
        output += "\n";
    }

    return output;
}

std::string Relation::toStringQ() {
    std::string output ="";
    int numberofTuples = 0;
    unsigned int j=0;
    for (Tuple t :mySet) {
        j++;
        numberofTuples++;
        output+= "\t";
        for (unsigned int i = 0; i < header.getHeaders().size(); ++i) {
            if (i >= 1) {
                output+= ", ";
            }
            output+= header.getHeaders()[i] + "=" + t.getTuple()[i] ;

        }
        if (j > 0 && output != "\t" && j < mySet.size()) {
            output += "\n";
        }

    }
    if (numberofTuples > 0 && output != "\t") {
        output = "Yes(" + std::to_string(numberofTuples) + ")\n" + output;
    }
    else if (numberofTuples > 0) {
        output = "Yes(" + std::to_string(numberofTuples) + ")";
    }
    else {
        output = "No";
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
            newTupleData = t.getTuple();
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

Relation Relation::cross(Relation A, Relation B) {




    //bool Cross = true;
    //cross product
    /*

    for (unsigned int i = 0; i < this->header.getHeaders().size() ; ++i) {
        for (unsigned int j = 0; i < B.header.getHeaders().size() ; ++i) {
            if (this->header.getHeaders()[i] == B.header.getHeaders()[j]) {
                Cross = false;
            }
        }
    }
    if (
    if (Cross) {
        std::string newName = this->getName()+B.getName();
        std::vector<std::string> headerString = this->header.getHeaders();
        for (unsigned int i = 0; i < B.header.getHeaders().size(); ++i) {
            headerString.push_back(B.header.getHeaders()[i]);
        }
        Header newHeader(headerString);

        Relation X = Relation(newName,newHeader);
        for (Tuple t :mySet) {
            std::vector<std::string> tupleValues = t.getTuple();
            for (Tuple v :B.mySet) {
                for (unsigned int i = 0; i < v.getTuple().size(); ++i) {
                    tupleValues.push_back(v.getTuple()[i]);
                }

            }
            X.addTuple(tupleValues);
        }
    }
*/
    std::string newName = A.getName()+B.getName();
    std::vector<std::string> headerString = A.header.getHeaders();
    for (unsigned int i = 0; i < B.header.getHeaders().size(); ++i) {
        headerString.push_back(B.header.getHeaders()[i]);
    }
    Header newHeader(headerString);

    Relation X = Relation(newName,newHeader);
    for (Tuple t :A.mySet) {

        for (Tuple v :B.mySet) {
            std::vector<std::string> tupleValues = t.getTuple();
            for (unsigned int i = 0; i < v.getTuple().size(); ++i) {
                tupleValues.push_back(v.getTuple()[i]);
            }

            X.addTuple(tupleValues);
        }

    }





    return X;
}

Relation Relation::join(Relation B) {

    std::vector<int> sameThisHeaders;
    std::vector<int> sameBHeaders;
    std::vector<std::string> newHeader = B.header.getHeaders();
    std::vector<int> projectionIndex;

    for (unsigned int i = 0; i < this->header.getHeaders().size() ; ++i) {
        for (unsigned int j = 0; j < B.header.getHeaders().size() ; ++j) {
            if (this->header.getHeaders()[i] == B.header.getHeaders()[j]) {
                sameThisHeaders.push_back(i);
                sameBHeaders.push_back(j);
                newHeader[j] = B.header.getHeaders()[j] + "*";
            }
        }
    }

    std::string newName = this->getName()+B.getName();
    std::vector<std::string> headerString = this->header.getHeaders();
    for (unsigned int i = 0; i < B.header.getHeaders().size(); ++i) {
        headerString.push_back(B.header.getHeaders()[i]);
    }
    Header addHeader(headerString);

    Relation X = Relation(newName,addHeader);


    B = B.rename(newHeader);
    X = cross(*this,B);

    for (unsigned int i = 0; i < sameThisHeaders.size(); ++i) {
        X = X.select(sameThisHeaders[i],this->header.getHeaders().size() + sameBHeaders[i]);
    }
    int index = 0;
    for (unsigned int i = 0; i < this->header.getHeaders().size() + B.header.getHeaders().size(); ++i) {

        bool indexadd = true;
        for (unsigned int j = 0; j < sameBHeaders.size(); ++j) {
            if ((int)this->header.getHeaders().size() +sameBHeaders[j] == index) {
                indexadd = false;
            }
        }
        if (indexadd) {
            projectionIndex.push_back(i);
        }
        index++;
    }

    X = X.project(projectionIndex);




    return X;
}
