//
// Created by iamaw on 11/1/2021.
//

#include "Tuple.h"

bool Tuple::operator< (const Tuple &rhs) const {
    return itemList < rhs.itemList;
}

Tuple::~Tuple() {

}

std::vector<std::string> Tuple::getTuple() {
    return itemList;
}

Tuple::Tuple(std::vector<std::string> items) {
    itemList = items;
    for (unsigned int i = 0; i < items.size(); ++i) {
        std::string itemString = items[i];
        std::string quote = "'";
        if (itemString.at(0) == quote.at(0)  ) {
            constantValue.push_back(true);
        }
        else {
            constantValue.push_back(false);
        }
    }
}

