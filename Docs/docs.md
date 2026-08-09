# VastNova Language Reference

VastNova is a statically typed, compiled language designed for simplicity and performance. This document describes every aspect of the language in detail.

## 1. Comments

VastNova supports three forms of comments:

- `//` – single-line comment (C++ style)
- `#` – single-line comment (shell style)
- `!# ... #!` – multi-line comment (blocks can span any number of lines)

```vastnova
// this is a comment
# this is also a comment
!# this is a multi‑line comment
   it can contain anything
   until the closing marker #!
```

## 2. Types

VastNova has four primitive types:

| Type  | Description               | Example literals |
|-------|---------------------------|------------------|
| `i32` | 32‑bit signed integer     | `42`, `-5`       |
| `i64` | 64‑bit signed integer     | `1000000`        |
| `f64` | 64‑bit IEEE‑754 float     | `3.14`, `-0.001` |
| `str` | UTF‑8 string (heap‑allocated) | `"Hello"`   |

All types are **static** but can be **inferred** when a value is given.

## 3. Variables and Constants

### Variable Declaration

```vastnova
var name             // declared but uninitialized (defaults to 0 for numbers, empty for str)
var name = value     // type inferred from value
var name : type      // explicit type, no initial value
var name : type = value  // explicit type with initial value
```

Examples:
```vastnova
var a                 // a is i32, value = 0
var b = 42            // b is i32
var c : f64 = 3.14    // c is f64
var d : str = "text"  // d is str
```

### Constants

Constants are declared with `let` and **must** be initialized. They cannot be reassigned later.

```vastnova
let pi : f64 = 3.14159
let name = "Alice"    // type inferred as str
```

## 4. Arithmetic Expressions

Operators: `+` `-` `*` `/` with standard precedence (multiplication/division before addition/subtraction). Parentheses can override precedence.

All arithmetic is **type‑aware**:
- If both operands are integers, result is integer (truncating division).
- If either operand is float, result is float.
- String `+` performs **concatenation** (only between strings).

Examples:
```vastnova
var a = 10 + 5        // 15 (i32)
var b = 3.14 * 2      // 6.28 (f64)
var c = 20 / 3        // 6 (integer division)
var d = "Hello" + " " + "World"  // "Hello World" (str)
```

Note: Mixing numbers and strings in `+` is **not** allowed; use `str()` to convert numbers explicitly.

## 5. Output: `print`

`print` takes any number of arguments (numbers, strings, variables) and prints them separated by spaces, ending with a newline. It automatically chooses the correct formatting.

```vastnova
print("Hello")               // prints: Hello
print(a, b, c)               // prints the values of a, b, c separated by spaces
print("Result:", a + b)      // mixed literals and expressions
```

## 6. Input: `input`

`input` reads a line from standard input and returns it as a `str`. It can take an optional prompt argument (printed before reading).

```vastnova
var name = input("Enter your name: ")   // prints prompt, then reads
var age = input()                       // reads without prompt
print("Hello,", name, "age:", age)
```

`input` always returns a string; if you need a number, you must convert it explicitly (e.g., using `str()` is not needed; but currently no built‑in `int()` exists – numbers can be parsed later).

## 7. Conditionals: `if` / `else`

The `if` statement evaluates a condition and executes the `then` block if true; optionally an `else` block runs if false.

**Condition syntax:**  
Conditions can use comparison operators `>`, `<`, `==`, `!=` and logical operators `&&` (AND), `||` (OR). Parentheses are **not** required around the condition.

```vastnova
var score = 85
if score >= 90 {
    print("Excellent")
} else {
    if score >= 60 {
        print("Pass")
    } else {
        print("Fail")
    }
}
```

Both `then` and `else` blocks **must** be enclosed in `{ }`, even for a single statement.

## 8. String Operations

### Concatenation (`+`)
Two strings can be concatenated with `+`. The result is a newly allocated string.

```vastnova
var first = "Hello"
var last = "World"
var full = first + " " + last   // "Hello World"
```

### Conversion from numbers (`str()`)
The built‑in function `str(number)` converts an integer or float to its string representation. This is useful for embedding numbers in strings.

```vastnova
var pi = 3.14159
var pi_str = str(pi)          // "3.14159"
var msg = "Pi is " + pi_str
print(msg)                   // Pi is 3.14159
```

Note: `str()` currently supports only numbers; passing a string will cause an error.

## 9. Variable Reassignment

Variables declared with `var` can be reassigned at any time. The new value must be compatible with the variable's type (no implicit conversions between incompatible types).

```vastnova
var x = 10
x = 20          // OK
x = "text"      // ERROR: type mismatch (i32 vs str)
```

Constants (`let`) cannot be reassigned.

## 10. Complete Example Program

Below is a full program that uses almost every feature:

```vastnova
// Input and output
var name = input("What is your name? ")
var age = input("How old are you? ")

// Arithmetic
var birth_year = 2025 - age
var next_age = age + 1

// Conditions
if age >= 18 {
    print("You are an adult.")
} else {
    print("You are a minor.")
}

// String concatenation with number conversion
var message = "Hello, " + name + "! You will be " + str(next_age) + " next year."
print(message)
```

## 11. Errors and Limitations

- No arrays or dictionaries yet.
- No user‑defined functions.
- No explicit type casting except `str()`.
- All `if`/`else` blocks must use `{ }`; no single‑line shorthand.

## 12. Further Reading

For compiler internals and contribution guide, check the project's main documentation.