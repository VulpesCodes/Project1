//
// Created by iamaw on 11/1/2021.
//

#ifndef PROJECT1_STARTER_CODE_TUPLE_H
#define PROJECT1_STARTER_CODE_TUPLE_H
#include <vector>
#include <string>

class Tuple
{
private:
    std::vector<std::string> itemList;
    std::vector<bool> constantValue;

public:
    Tuple();
    Tuple(std::vector<std::string>);
    ~Tuple();
    std::vector<std::string> getTuple();
    std::vector<bool> getTupleConst();

    bool operator< (const Tuple &rhs) const;

};

#endif //PROJECT1_STARTER_CODE_TUPLE_H
