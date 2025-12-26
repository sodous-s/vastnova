# VastNova 0 Beta4 介绍文档

## 概述
VastNova 是一个极简的脚本解释器，当前版本为 0 Beta4。

## beta 4最新功能
支持多行注释
```vastnova
var a
#这是一个单行注释
!#这是一个多行注释
它可以注释很长
#!
```

## beta 3功能
支持类似Python的input

语法
```vastnova
var a
a = input "input"
```

## 基本功能

### 1. 变量声明
```vastnova
var x      // 声明空变量
var y = 5  // 声明并赋值
```

### 2. 输出功能
```vastnova
out "Hello"  // 输出字符串
out y        // 输出变量值
```

### 3. 输入功能
```vastnova
in x  // 从控制台读取输入
```

### 4. 常量定义
```vastnova
const PI = 3.14  // 定义常量
```

### 5. 四则运算
可以使用加、减、乘、除来进行运算

## 注意事项
1. 当前仅支持数字和字符串两种数据类型
2. 变量必须先声明后使用
3. 常量定义后不可修改
4. 错误处理非常基础

## 示例代码
```vastnova
// 简单示例
var name
out "请输入你的名字:"
in name
out "你好，" name
var age
age = input "请输入你的年龄"
out age
!#
以上为简单的例子
#!
```
