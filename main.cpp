#include "Lexer.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    std::string FileName = argv[1];
    //std::cout << FileName << std::endl;
    std::ifstream file;
    file.open(FileName);
    std::string data;

    //if (argc < 2) {std::cerr << "Please provide name of input file";}
    //if (!file) {std::cout << "Unable to open file" << std::endl;}


    while(file.peek() != EOF){
        data += file.get();
    }

    lexer->Run(data);

    delete lexer;

    return 0;
}