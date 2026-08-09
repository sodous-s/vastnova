#include "vastnova.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    using namespace vastnova;

    if (argc < 2) {
        std::cerr << "Usage: vastnova_test <input.vn>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::ifstream in(inputFile);
    if (!in.is_open()) {
        std::cerr << "Error: Cannot open file '" << inputFile << "'" << std::endl;
        return 1;
    }
    std::string code((std::istreambuf_iterator<char>(in)),
                     std::istreambuf_iterator<char>());
    in.close();
    
    try {
        auto ast = parse(code);
        if (!ast) {
            std::cerr << "Parsing failed." << std::endl;
            return 1;
        }
        
        std::cout << "=== AST Output ===" << std::endl;
        printAST(ast.get());
        std::cout << "\nParsing successful!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
