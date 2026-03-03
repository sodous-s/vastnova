# VastNova 0 beta6 English Documentation

VastNova is a lightweight, easily embeddable scripting language designed for quick integration and interactive use. It features a minimalistic syntax, dynamic typing, arithmetic operations, conditionals, and I/O, making it ideal for game scripting, configuration files, or educational examples.

## Features

- Minimal syntax: intuitive keywords like `print` / `read` (backward compatible with `out` / `in`)
- Dynamic typing: automatically distinguishes numbers and strings
- Arithmetic: `+` `-` `*` `/` with operator precedence
- Conditionals: `>` `<` `==` `!=` and `&&` `||`, with string comparison support
- Interactive input: via `input` or `read`
- Comments: single-line `//` or `#`, multi-line `!# ... #!`
- Header-only, depends only on C++ standard library

## Quick Start

### Integration into C++ Project

Copy `vastnova.h` into your project directory and include it:

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

Compile with C++11 or later.

### Interactive Command Line

The provided `main.cpp` offers a simple interactive interpreter:

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

### Running Script Files

```bash
$ ./vastnova script.vn
```

## Language Reference

For detailed syntax examples, please refer to the `examples/` directory. Each example file is commented to illustrate specific language features.
Full documentation: [vastnova.pages.dev](https://vastnova.pages.dev)

## Building the Example

If you use the supplied `main.cpp`, compile with:

```bash
g++ -std=c++11 main.cpp -o vastnova
```

## Version History

- **0 beta6**: Added `print`/`read` keywords (backward compatible with `out`/`in`); error messages and comments now in English

## License

MIT License