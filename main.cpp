#include "VastNova.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // 检查命令行参数数量
    if (argc != 2) {
        std::cerr << "用法: vastnova <脚本文件>" << std::endl;
        std::cerr << "错误: 需要提供1个脚本文件作为参数" << std::endl;
        return 1;
    }

    // 获取脚本文件名
    std::string filename = argv[1];
    std::ifstream file(filename);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "错误: 无法打开文件 '" << filename << "'" << std::endl;
        return 1;
    }

    // 读取整个文件内容
    std::string code((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    
    // 关闭文件并执行代码
    file.close();
    vast(code);
    
    return 0;
}
