# VastNova 0 beta5 English Documentation

VastNova is a lightweight, easily embeddable scripting language designed for quick integration and interactive use. It features a minimalistic syntax, supports variables, constants, I/O, arithmetic operations, and conditional statements, making it ideal for game scripting, configuration files, or educational examples.

## Features

- Minimal syntax: only `out`, `var`, `const`, `in`, `if` keywords
- Dynamic typing: automatically distinguishes numbers and strings
- Arithmetic: `+` `-` `*` `/` with operator precedence
- Conditionals: `>` `<` `==` `!=` and `&&` `||`, with string comparison support
- Interactive input: via `input` or `in` commands
- Comments: single-line `//` or `#`, multi-line `!# ... #!`
- Header-only, depends only on C++ standard library, easy to embed

## Quick Start

### Integration into C++ Project

Copy `vastnova.h` into your project directory, then include it:

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

Compile with C++11 or later.

### Interactive Command Line

VastNova provides a simple interactive interpreter example (see `main.cpp`) that executes code line by line:

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

### Running Script Files

```bash
$ ./vastnova script.vn
```

## Language Reference

### Output `out`

```vastnova
out "Hello"          # output string
out 123              # output number
out a                # output variable value
out "value =" a      # mixed output
```

### Variable `var`

```vastnova
var a                # declare variable (initially empty)
var b = 10           # declare and assign
var c = "text"
var d = input "Prompt: "  # declare and assign from input
```

### Constant `const`

```vastnova
const PI = 3.14159   # constant must be assigned immediately and cannot be changed
```

### Input `input` / `in`

```vastnova
var x
x = input "Enter: "  # show prompt and read input
in x                  # simple input (no prompt), variable must already exist
```

### Assignment

```vastnova
a = 5                # reassign existing variable
b = a + 10           # expressions allowed
c = input "New value: "  # assign from input
```

### Arithmetic

Supports `+` `-` `*` `/` with standard precedence (multiplication/division before addition/subtraction).

```vastnova
var result = 10 + 5 * 2   # yields 20
```

### Conditional `if`

```vastnova
if a > b {
    out "a is greater than b"
}
if a == "admin" && b != 0 {
    out "condition satisfied"
}
```

- Comparison operators: `>` `<` `==` `!=`
- Logical operators: `&&` `||`
- Strings are compared lexicographically, numbers numerically
- Braces `{ }` must be matched, `{` must be on the same line as `if`

### Comments

```vastnova
// single-line comment
# also single-line comment
!# multi-line comment start
can span multiple lines
until closing marker #!
```

## Building the Example

If you use the provided `main.cpp`, compile with:

```bash
g++ -std=c++11 main.cpp -o vastnova
```

## Version History

- **0 beta5**: Added `if` statements and string comparison support

## License

MIT License
