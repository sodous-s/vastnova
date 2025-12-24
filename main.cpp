#include "vastnova.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    
    if (argc == 1) {
    std::cout << "Vastnova 0 beta4" << std::endl;
    std::cout << "Welcome!" << std::endl << std::endl;

        VastNovaInterpreter interpreter;
        std::string line;

        while (true) {
            std::cout << ">>> ";
            std::getline(std::cin, line);

            if (line == "exit" || line == "quit" || line == "exit()") {
                std::cout << "goodbye!" << std::endl;
                break;
            }

            if (!line.empty()) {
                interpreter.vast(line);
            }
        }
    }
    else if (argc == 2) {
        std::string filename = argv[1];
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            std::cerr << "错误: 无法打开文件 '" << filename << "'" << std::endl;
            return 1;
        }

        std::string code((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

        file.close();
        vast(code);
    }
    else {
        std::cerr << "error" << std::endl;
        return 1;
    }

    return 0;
}
