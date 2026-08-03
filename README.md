# VastNova Compiler

VastNova is a lightweight, statically typed language with a simple syntax. It compiles source files directly to native executables using LLVM.

## Features

- Simple, readable syntax: `var`, `let`, `print`, `input`, `if`, arithmetic, and string operations.
- Type inference with optional explicit types: `i32`, `i64`, `f64`, `str`.
- LLVM backend – generates efficient machine code via `clang`.
- Command‑line compiler – no runtime dependencies.

## Installation

### Prerequisites

- C++17 compiler (GCC, Clang, or MSVC)
- LLVM (≥ 14) with development headers
- `clang` (to compile generated IR to executable)
- `llvm-config` (usually included with LLVM)

### Build from source

```bash
git clone https://github.com/sodous-s/vastnova.git
cd vastnova
g++ -std=c++17 src/main.cpp src/CodeGen.cpp -I include $(llvm-config --cxxflags --ldflags --libs core) -fexceptions -o vastnova
```

The executable `vastnova` will be created in the current directory.

## Usage

### Compile a `.vn` file

```bash
./vastnova source.vn [output_executable]
```

- Reads `source.vn`, compiles it to LLVM IR, then produces a native executable.
- If `output_executable` is omitted, the output name is derived from the input file (adds `.exe` on Windows).

### Only generate LLVM IR

```bash
./vastnova source.vn --no-run
```

The IR is saved as `source.ll`.

## Language Reference

### Comments
```
// single-line
# also single-line
!# multi-line
   comment #!
```

### Variables and Constants
```
var a = 10                 // inferred type (i32)
var b : i32 = 20           // explicit type
var c : f64 = 3.14
var name : str = "Alice"
let pi : f64 = 3.14159     // constant (must be initialized)
```

### Output
```
print("Hello", a, b)       // arguments are space‑separated, ends with newline
```

### Input
```
var age = input("Enter age: ")
var x = input()            // no prompt
```

### Arithmetic
```
var sum = a + b
var mixed = a + b * 2 - c / 3  // standard precedence
```

### Conditionals
```
if a > b {
    print("a is greater")
}
if a == 10 && b < 20 {
    print("both true")
}
```

## Project Structure
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

## License

MIT License.