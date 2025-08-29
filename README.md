# VastNova 语言介绍
This article is also available in [English](English.md)

## 概述

VastNova 是一种简单、轻量级的脚本语言，设计用于快速原型开发和教学目的。它具有简洁的语法和直观的命令结构，易于学习和使用。

语言特性

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
```

使用方式

VastNova 通过 C++ 头文件实现，只需包含 VastNova.h 即可在 C++ 程序中使用：

```cpp
#include "VastNova.h"

int main() {
    std::string code = R"(
        var message = "Hello from VastNova!"
        out message
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

## 应用场景

· 教育环境中的编程入门
· 简单脚本任务
· 嵌入式系统的简单配置脚本
· 作为更复杂语言的子语言或模板语言

VastNova 致力于提供最简单直观的脚本体验，让初学者能够快速上手编程概念。
