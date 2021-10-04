//
// Created by iamaw on 10/4/2021.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H

#include <string>
#include <vector>

class Parameter
{
private:
    std::string description = "";


public:
    Parameter();
    Parameter(std::string);
    ~Parameter();
    void setString(std::string );
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_PARAMETER_H
