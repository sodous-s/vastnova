#ifndef VASTNOVA_H
#define VASTNOVA_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

class VastNovaInterpreter {
private:
    std::unordered_map<std::string, std::string> variables;
    std::unordered_map<std::string, std::string> constants;
    
    void trim(std::string& str) {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), str.end());
    }
    
    void removeComments(std::string& line) {
        size_t commentPos = line.find("//");
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        commentPos = line.find("#");
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        trim(line);
    }
    
    bool isNumber(const std::string& s) {
        if (s.empty()) return false;
        
        // 检查是否为整数或浮点数
        size_t dotCount = 0;
        bool hasSign = (s[0] == '-' || s[0] == '+');
        
        for (size_t i = (hasSign ? 1 : 0); i < s.size(); i++) {
            if (s[i] == '.') {
                dotCount++;
                if (dotCount > 1) return false;
            } else if (!std::isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }
    
    bool isStringLiteral(const std::string& s) {
        return s.size() >= 2 && s.front() == '"' && s.back() == '"';
    }
    
    std::string getValue(const std::string& token) {
        if (isNumber(token)) {
            return token;
        } else if (isStringLiteral(token)) {
            return token.substr(1, token.size() - 2);
        } else {
            if (constants.find(token) != constants.end()) {
                return constants[token];
            }
            if (variables.find(token) != variables.end()) {
                return variables[token];
            }
            return ""; // 未定义变量返回空字符串
        }
    }

    std::vector<std::string> tokenizeLine(const std::string& line) {
        std::vector<std::string> tokens;
        std::string currentToken;
        bool inString = false;
        
        for (char c : line) {
            if (c == '"') {
                inString = !inString;
                currentToken += c;
            } else if (std::isspace(c) && !inString) {
                if (!currentToken.empty()) {
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
            } else {
                currentToken += c;
            }
        }
        
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
        }
        
        return tokens;
    }

    bool isVariable(const std::string& name) {
        return variables.find(name) != variables.end();
    }

    bool isConstant(const std::string& name) {
        return constants.find(name) != constants.end();
    }

    std::string evaluateExpression(const std::string& expr) {
        // 简单的表达式求值，支持 +, -, *, /
        std::vector<std::string> tokens;
        std::string currentToken;
        
        for (char c : expr) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (!currentToken.empty()) {
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
                tokens.push_back(std::string(1, c));
            } else if (!std::isspace(c)) {
                currentToken += c;
            }
        }
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
        }
        
        if (tokens.empty()) return "";
        
        // 解析操作数
        std::vector<double> values;
        std::vector<char> operators;
        
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                operators.push_back(token[0]);
            } else {
                std::string valueStr = getValue(token);
                if (valueStr.empty() || !isNumber(valueStr)) {
                    return ""; // 无效的操作数
                }
                values.push_back(std::stod(valueStr));
            }
        }
        
        if (values.size() != operators.size() + 1) {
            return ""; // 表达式格式错误
        }
        
        // 先处理乘除法
        for (size_t i = 0; i < operators.size();) {
            if (operators[i] == '*' || operators[i] == '/') {
                double result;
                if (operators[i] == '*') {
                    result = values[i] * values[i + 1];
                } else {
                    if (values[i + 1] == 0) {
                        std::cout << "错误: 除以零" << std::endl;
                        return "";
                    }
                    result = values[i] / values[i + 1];
                }
                values[i] = result;
                values.erase(values.begin() + i + 1);
                operators.erase(operators.begin() + i);
            } else {
                i++;
            }
        }
        
        // 再处理加减法
        double result = values[0];
        for (size_t i = 0; i < operators.size(); i++) {
            if (operators[i] == '+') {
                result += values[i + 1];
            } else if (operators[i] == '-') {
                result -= values[i + 1];
            }
        }
        
        // 转换为字符串返回
        std::stringstream ss;
        ss << result;
        return ss.str();
    }

public:
    void vast(const std::string& code) {
        std::istringstream stream(code);
        std::string line;
        
        while (std::getline(stream, line)) {
            removeComments(line);
            if (line.empty()) continue;
            
            std::vector<std::string> tokens = tokenizeLine(line);
            if (tokens.empty()) continue;
            
            if (tokens[0] == "out") {
                if (tokens.size() < 2) continue;
                
                std::string output;
                for (size_t i = 1; i < tokens.size(); i++) {
                    std::string value = getValue(tokens[i]);
                    if (!value.empty()) {
                        if (!output.empty()) output += " ";
                        output += value;
                    }
                }
                if (!output.empty()) {
                    std::cout << output;
                }
                std::cout << std::endl;
            }
            else if (tokens[0] == "var") {
                if (tokens.size() < 2) continue;
                
                std::string varName = tokens[1];
                if (tokens.size() == 2) {
                    variables[varName] = "";
                } else if (tokens.size() >= 4 && tokens[2] == "=") {
                    std::string value;
                    for (size_t i = 3; i < tokens.size(); i++) {
                        if (i > 3) value += " ";
                        value += tokens[i];
                    }
                    // 检查是否是表达式
                    if (value.find('+') != std::string::npos ||
                        value.find('-') != std::string::npos ||
                        value.find('*') != std::string::npos ||
                        value.find('/') != std::string::npos) {
                        variables[varName] = evaluateExpression(value);
                    } else {
                        variables[varName] = getValue(value);
                    }
                }
            }
            else if (tokens[0] == "const") {
                if (tokens.size() < 4 || tokens[2] != "=") continue;
                
                std::string constName = tokens[1];
                std::string value;
                for (size_t i = 3; i < tokens.size(); i++) {
                    if (i > 3) value += " ";
                    value += tokens[i];
                }
                constants[constName] = getValue(value);
            }
            else if (tokens[0] == "in") {
                if (tokens.size() != 2) continue;
                
                std::string varName = tokens[1];
                if (variables.find(varName) == variables.end()) {
                    std::cout << "错误: 变量 '" << varName << "' 未定义，无法使用 in 命令" << std::endl;
                    continue;
                }
                
                std::string input;
                std::getline(std::cin, input);
                trim(input);
                variables[varName] = input;
            }
            else if (tokens.size() >= 3 && tokens[1] == "=") {
                // 变量直接赋值语法: a = 12 或 a = b + 5
                std::string varName = tokens[0];
                
                if (isConstant(varName)) {
                    std::cout << "错误: 常量 '" << varName << "' 不能被重新赋值" << std::endl;
                    continue;
                }
                
                if (!isVariable(varName)) {
                    std::cout << "错误: 变量 '" << varName << "' 未定义，无法赋值" << std::endl;
                    continue;
                }
                
                std::string value;
                for (size_t i = 2; i < tokens.size(); i++) {
                    if (i > 2) value += " ";
                    value += tokens[i];
                }
                
                // 检查是否是表达式
                if (value.find('+') != std::string::npos ||
                    value.find('-') != std::string::npos ||
                    value.find('*') != std::string::npos ||
                    value.find('/') != std::string::npos) {
                    variables[varName] = evaluateExpression(value);
                } else {
                    if (isNumber(value) || isStringLiteral(value)) {
                        variables[varName] = getValue(value);
                    } else if (variables.find(value) != variables.end()) {
                        variables[varName] = variables[value];
                    } else if (constants.find(value) != constants.end()) {
                        variables[varName] = constants[value];
                    } else {
                        variables[varName] = "";
                    }
                }
            }
        }
    }
};

// 全局函数接口
void vast(const std::string& code) {
    static VastNovaInterpreter interpreter;
    interpreter.vast(code);
}

#endif // VASTNOVA_H
