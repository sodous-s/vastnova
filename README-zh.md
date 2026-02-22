# VastNova 0 beta5 中文文档

VastNova 是一种轻量级、易嵌入的脚本语言，专为快速集成和交互式使用而设计。其语法简洁，支持变量、常量、输入输出、数学运算以及条件判断，非常适合用作游戏脚本、配置文件或教学示例。

## 特性

- 极简语法：仅包含 `out`、`var`、`const`、`in`、`if` 等关键字
- 动态类型：自动区分数字和字符串
- 数学运算：支持 `+` `-` `*` `/` 及运算优先级
- 条件判断：支持 `>` `<` `==` `!=` 以及 `&&` `||`，字符串也可比较
- 交互式输入：通过 `input` 或 `in` 获取用户输入
- 注释：单行 `//` 或 `#`，多行 `!# ... #!`
- 头文件仅依赖 C++ 标准库，极易嵌入任何 C++ 项目

## 快速开始

### 集成到 C++ 项目

将 `vastnova.h` 复制到项目目录，然后在代码中包含：

```cpp
#include "vastnova.h"
#include <iostream>

int main() {
    vast(R"(
        out "Hello, VastNova!"
        var name = input "What's your name? "
        out "Nice to meet you, " name
    )");
    return 0;
}
```

编译时确保使用 C++11 或更高版本。

### 交互式命令行

VastNova 提供了一个简单的交互式解释器示例（见 `main.cpp`），可逐行执行代码：

```bash
$ ./vastnova
Vastnova 0 beta4
Welcome!

>>> out "Hello"
Hello
>>> var a = 10
>>> a = a * 2
>>> out a
20
>>> exit
goodbye!
```

### 运行脚本文件

```bash
$ ./vastnova script.vn
```

## 语法参考

### 输出 `out`

```vastnova
out "Hello"          # 输出字符串
out 123              # 输出数字
out a                # 输出变量值
out "value =" a      # 混合输出
```

### 变量 `var`

```vastnova
var a                # 声明变量（默认为空）
var b = 10           # 声明并赋值
var c = "text"
var d = input "提示"  # 声明并从输入赋值
```

### 常量 `const`

```vastnova
const PI = 3.14159   # 常量必须立即赋值且不可修改
```

### 输入 `input` / `in`

```vastnova
var x
x = input "请输入："   # 显示提示并读取输入
in x                  # 简单输入（无提示），变量需已定义
```

### 赋值

```vastnova
a = 5                # 对已定义变量重新赋值
b = a + 10           # 支持表达式
c = input "新值："    # 从输入赋值
```

### 数学运算

支持 `+` `-` `*` `/`，遵循先乘除后加减的优先级。

```vastnova
var result = 10 + 5 * 2   # 结果为 20
```

### 条件判断 `if`

```vastnova
if a > b {
    out "a 大于 b"
}
if a == "admin" && b != 0 {
    out "条件满足"
}
```

- 比较运算符：`>` `<` `==` `!=`
- 逻辑运算符：`&&` `||`
- 字符串比较按字典序，数值比较按大小
- 花括号 `{ }` 必须配对，`{` 必须与 `if` 在同一行

### 注释

```vastnova
// 单行注释
# 这也是单行注释
!# 多行注释开始
可以跨越多行
直到遇到结束标记 #!
```

## 构建示例

如果您使用提供的 `main.cpp`，可以这样编译：

```bash
g++ -std=c++11 main.cpp -o vastnova
```

## 版本历史

- **0 beta5**：新增 `if` 语句及字符串比较支持

## 许可证

MIT License
