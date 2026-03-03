# VastNova 0 beta6 中文文档

VastNova 是一种轻量级、易嵌入的脚本语言，设计用于快速集成和交互式使用。语法极简，支持变量、常量、输入输出、算术运算及条件判断，适合游戏脚本、配置文件或教学演示。

## 特性

- 极简语法：`print` / `read` 等直观关键字，同时兼容旧版 `out` / `in`
- 动态类型：自动区分数字和字符串
- 算术运算：`+` `-` `*` `/` 及运算优先级
- 条件判断：`>` `<` `==` `!=` 与 `&&` `||`，字符串也可比较
- 交互输入：`input` 或 `read` 获取用户输入
- 注释：单行 `//` 或 `#`，多行 `!# ... #!`
- 头文件仅依赖 C++ 标准库，极易嵌入

## 快速开始

### 集成到 C++ 项目

将 `vastnova.h` 复制到项目目录，然后在代码中调用：

```cpp
#include "vastnova.h"

int main() {
    vast(R"(
        print "Hello, VastNova!"
        var name = input "What's your name? "
        print "Nice to meet you, " name
    )");
    return 0;
}
```

编译时启用 C++11 或更高版本。

### 交互式命令行

附带示例 `main.cpp` 提供了简单的交互式解释器：

```bash
$ ./vastnova
Vastnova 0 beta6
Welcome!

>>> print "Hello"
Hello
>>> var a = 10
>>> a = a * 2
>>> print a
20
>>> exit
goodbye!
```

### 运行脚本文件

```bash
$ ./vastnova script.vn
```

## 语法参考

详细的语法示例请参见项目中的 `examples/` 目录。每个示例文件均包含注释，展示不同特性的用法。
完整文档请访问：[vastnova.pages.dev](https://vastnova.pages.dev)

## 构建示例

如果您使用提供的 `main.cpp`，编译命令如下：

```bash
g++ -std=c++11 main.cpp -o vastnova
```

## 版本历史

- **0 beta6**：新增 `print`/`read` 关键字（兼容旧版 `out`/`in`），错误信息和注释改为英文

## 许可证

MIT License