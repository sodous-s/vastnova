# VastNova 编译器

VastNova 是一种轻量级、静态类型的编程语言，语法简洁，可直接编译为本地可执行文件，后端基于 LLVM。

## 特性

- 简洁易读的语法：`var`、`let`、`print`、`input`、`if`、算术运算、字符串操作。
- 类型推断，也支持显式类型：`i32`、`i64`、`f64`、`str`。
- LLVM 后端 – 通过 `clang` 生成高效机器码。
- 命令行编译器 – 无运行时依赖。

## 安装

### 依赖

- C++17 编译器（GCC、Clang 或 MSVC）
- LLVM（≥ 14）及其开发头文件
- `clang`（用于将 IR 编译为可执行文件）
- `llvm-config`（通常随 LLVM 一起提供）

### 从源码构建

```bash
git clone https://github.com/sodous-s/vastnova.git
cd vastnova
g++ -std=c++17 src/main.cpp src/CodeGen.cpp -I include $(llvm-config --cxxflags --ldflags --libs core) -fexceptions -o vastnova
```

执行 `vastnova` 即为编译器程序。

## 使用方法

### 编译 `.vn` 文件

```bash
./vastnova 源文件.vn [输出可执行文件名]
```

- 读取 `源文件.vn`，生成 LLVM IR，然后编译为本地可执行文件。
- 如果未指定输出文件名，则根据输入文件名自动生成（Windows 下添加 `.exe` 后缀）。

### 仅生成 LLVM IR（不编译为可执行文件）

```bash
./vastnova 源文件.vn --no-run
```

IR 文件保存为 `源文件.ll`。

## 语言参考

### 注释
```
// 单行注释
# 也是单行注释
!# 多行注释
   内容 #!
```

### 变量与常量
```
var a = 10                 // 类型推断为 i32
var b : i32 = 20           // 显式类型
var c : f64 = 3.14
var name : str = "Alice"
let pi : f64 = 3.14159     // 常量（必须初始化）
```

### 输出
```
print("Hello", a, b)       // 参数用空格分隔，末尾换行
```

### 输入
```
var age = input("请输入年龄：")
var x = input()            // 无提示
```

### 算术运算
```
var sum = a + b
var mixed = a + b * 2 - c / 3  // 标准优先级
```

### 条件判断
```
if a > b {
    print("a 大于 b")
}
if a == 10 && b < 20 {
    print("两个条件都成立")
}
```

## 项目结构
```
vastnova/
├── include/
│   ├── vastnova_ast.h
│   ├── vastnova.h
│   └── CodeGen.h
├── src/
     ├── main.cpp
     └── CodeGen.cpp
```

## 许可证

MIT License。