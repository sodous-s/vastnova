# VastNova 0 Beta4 Introduction Documentation

## Overview

VastNova is a minimalist script interpreter, currently at version 0 Beta4.

## Beta 4 Latest Features

Supports multiline comments

```vastnova
var a
#This is a single-line comment
!#This is a multiline comment
It can comment for a long time
#!
```

## Beta 3 Features

Supports Python-like input

Syntax

```vastnova
var a
a = input "input"
```

## Basic Functions

### 1. Variable Declaration

```vastnova
var x      // Declare an empty variable
var y = 5  // Declare and assign a value
```

### 2. Output Function

```vastnova
out "Hello"  // Output a string
out y        // Output a variable's value
```

### 3.Input Function

```vastnova
in x  // Read input from the console
```

### 4. Constant Definition

```vastnova
nova
const PI = 3.14  // Define a constant
```

### 5. Arithmetic Operations

Addition, subtraction, multiplication, and division operations can be used.

## Notes

1. Currently supports only numeric and string data types.
2. Variables must be declared before use.
3. Constants cannot be modified after definition.
4. Error handling is very basic.

## Example Code

```vastnova
// Simple example
var name
out "Please enter your name:"
in name
out "Hello，" name
var age
age = input "Please enter your age"
out age
!#
The above is a simple example.
#!
```
