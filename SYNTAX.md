# StrongLang Syntax

## Types

_strong_ supports 3 native types
- String
- Numbers
- Arrays

## Operations in strong

There are different kinds of operations, which are categorized based on the returned type.

## Runtime Operations

These operations are used to define the behavior of the app.
All of these are written at the beginning of the code.

_All Runtime Operations are defined by a hash followed by a 5 letter word._

### `#rtarg`: Runtime argument

- Available Flags: 
  - [l] long or
  - [s] short;
  - [d] default

### `#entry`: Entrypoint

### `#using`: Including Package

### `#debug`: Debug mode

### `#break`: Break on Error

### `#const`: Defining a constant



## List Operations

_All List Operations are defined by a 5 letter word._

### `split`: Split a string into a list

#### `lines`: Split a string on newline

#### `words`: Split a string on whitespace

## String Operations

_All String Operations are defined by a 4 letter word._

### Conversion
### `join`: Join list to string
### `conc`: Concatinate list to string
### `base`: Covert number into string
- Arguments:
  - 1: Base (default 10)
- Example:
```
base_example => 
  1234
  base 10           ; Convert number to base 10 string
<= ; will return "1234"
```

### `subs`: Create substring
### `loop`: Repeat string
### `repl`: Replace 

### Prefix and Suffix
### `prfx`: Prefix string
### `sufx`: Suffix string


### Trim
### `trim`: Trim string
### `trms`: Trim start 
### `trme`: Trim end

### Case:
### `CASE`: All to uppercase 
### `case`: All to lowercase
### `Case`: First letter to uppercase

### Padding:
### `pads`: Pad start
### `padc`: Pad center
### `pade`: Pad end
