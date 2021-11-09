//
// Created by iamaw on 11/1/2021.
//

#ifndef PROJECT1_STARTER_CODE_HEADER_H
#define PROJECT1_STARTER_CODE_HEADER_H
#include <vector>
#include <string>

class Header
{
private:
    std::vector<std::string> headerList;


public:
    Header();
    Header(std::vector<std::string>);
    ~Header();
    std::vector<std::string> getHeaders();

};

#endif //PROJECT1_STARTER_CODE_HEADER_H
