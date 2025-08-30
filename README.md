# VastNova 语言介绍 (版本 0.0.1-beta2)
This article is also available in [English](English.md)
## 概述

VastNova 是一种简单、轻量级的脚本语言，设计用于快速原型开发和教学目的。它具有简洁的语法和直观的命令结构，易于学习和使用。版本 beta2 在原有基础上增加了用户输入功能，使语言更加实用和完善。

## 新特性

### 输入语句 (新增)

使用 in 关键字从标准输入读取数据并赋值给已声明的变量：

```vastnova
var userName
in userName
out "Hello,", userName
```

## 语言特性

### 1. 注释

VastNova 支持两种注释格式：

· 使用 // 的单行注释
· 使用 # 的单行注释

### 2. 变量声明

使用 var 关键字声明变量：

```vastnova
var variableName
var variableName = value
```

### 3. 常量声明

使用 const 关键字声明常量（必须在声明时赋值）：

```vastnova
const constantName = value
```

### 4. 输出语句

使用 out 关键字输出内容：

```vastnova
out "Hello, World!"
out variableName, " ", anotherVariable
```

### 5. 数据类型

VastNova 支持以下数据类型：

· 数字（整数和浮点数）
· 字符串（使用双引号包裹）

### 6. 变量作用域

所有变量和常量都是全局可见的。

示例代码

```vastnova
// 变量声明和赋值
var name = "VastNova"
var version = 1.0

// 常量声明
const AUTHOR = "Developer"

// 输出信息
out "Welcome to", name, "version", version
out "Created by", AUTHOR

// 数学运算（需要在值中处理）
var result = 10 + 5
out "10 + 5 =", result

// 用户输入示例 (1.0.1 新增)
var userName
out "Please enter your name:"
in userName
out "Hello,", userName, "! Welcome to VastNova!"
```

## 使用方式

VastNova 通过 C++ 头文件实现，只需包含 VastNova.h 即可在 C++ 程序中使用：

```cpp
#include "VastNova.h"

int main() {
    std::string code = R"(
        var message = "Hello from VastNova!"
        out message
        
        // 1.0.1 新增的输入功能
        var userInput
        out "Enter something:"
        in userInput
        out "You entered:", userInput
    )";
    
    vast(code); // 执行 VastNova 代码
    
    return 0;
}
```

## 语言限制

1. 目前不支持控制流语句（如条件判断、循环）
2. 不支持自定义函数
3. 变量类型是动态的，但一旦赋值后类型固定
4. 错误处理较为简单，未定义的变量会返回空字符串
5. 输入功能只能将值赋给已声明的变量

## 应用场景

· 教育环境中的编程入门
· 简单脚本任务
· 嵌入式系统的简单配置脚本
· 作为更复杂语言的子语言或模板语言
· 需要简单用户交互的脚本应用（1.0.1 新增）

VastNova 1.0.1 在保持简单直观的同时，增加了用户输入功能，让初学者能够更好地理解交互式编程的概念。
