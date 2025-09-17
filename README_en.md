# VastNova 0 Beta3 Introduction Documentation

## Overview

VastNova is a minimalist script interpreter, with the current version being 0 Beta3.

## New Features

Supports Python-like input functionality.

 Syntax:

```vastnova  
var a  
a = input "input"  
```

## Implemented Features

### 1. Variable Declaration

```vastnova  
var x      // Declare an empty variable  
var y = 5  // Declare and assign a value  
```

### 2. Output Function

```vastnova  
out "Hello"  // Output a string  
out y        // Output the value of a variable  
```

### 3. Input Function

```vastnova  
in x  // Read input from the console  
```

### 4. Constant Definition

```vastnova  
const PI = 3.14  // Define a constant  
```

### 5. Arithmetic Operations

Supports addition, subtraction, multiplication, and division.

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
out "Hello, " name  
```
