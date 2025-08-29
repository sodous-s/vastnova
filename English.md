# VastNova Language Documentation
本文也有中文版本,请点击[这里](README.md)
## Overview

VastNova is a simple, lightweight scripting language designed for rapid prototyping and educational purposes. It features a clean syntax and intuitive command structure that makes it easy to learn and use.

## Language Features

### 1. Comments

VastNova supports two comment formats:

· Single-line comments using //
· Single-line comments using #

### 2. Variable Declaration

Use the var keyword to declare variables:

```vastnova
var variableName
var variableName = value
```

### 3. Constant Declaration

Use the const keyword to declare constants (must be assigned at declaration):

```vastnova
const constantName = value
```

### 4. Output Statements

Use the out keyword to output content:

```vastnova
out "Hello, World!"
out variableName, " ", anotherVariable
```

### 5. Data Types

VastNova supports the following data types:

· Numbers (integers and floating-point)
· Strings (wrapped in double quotes)

### 6. Variable Scope

All variables and constants have global visibility.

Code Examples

```vastnova
// Variable declaration and assignment
var name = "VastNova"
var version = 1.0

// Constant declaration
const AUTHOR = "Developer"

// Output information
out "Welcome to", name, "version", version
out "Created by", AUTHOR

// Mathematical operations (need to be handled in values)
var result = 10 + 5
out "10 + 5 =", result
```

## Usage

VastNova is implemented as a C++ header file. Simply include VastNova.h to use it in your C++ programs:

```cpp
#include "VastNova.h"

int main() {
    std::string code = R"(
        var message = "Hello from VastNova!"
        out message
    )";
    
    vast(code); // Execute VastNova code
    
    return 0;
}
```

## Language Limitations

1. Currently does not support control flow statements (like conditionals or loops)
2. Does not support custom functions
3. Variables are dynamically typed but become fixed after assignment
4. Simple error handling - undefined variables return empty strings

## Application Scenarios

· Programming introduction in educational environments
· Simple scripting tasks
· Basic configuration scripts for embedded systems
· As a sub-language or template language for more complex languages

VastNova is committed to providing the simplest and most intuitive scripting experience, allowing beginners to quickly grasp programming concepts.
