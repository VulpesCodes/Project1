//
// Created by iamaw on 11/1/2021.
//

#include "Header.h"

std::vector<std::string> Header::getHeaders() {
    return headerList;
}

Header::Header(std::vector<std::string> input) {
    headerList = input;
}

Header::Header() {

}

Header::~Header() {

}
