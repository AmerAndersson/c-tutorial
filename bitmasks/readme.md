
The `stdint.h` header file is part of the C standard library and is used to define a set of integer types with specified widths. This header was introduced in the C99 standard and provides a consistent and portable way to use integer types across different platforms and compilers. Here are the main features of `stdint.h`:

### Fixed-width Integer Types
These types have an exact width, ensuring portability and predictability across different systems:

- `int8_t`, `uint8_t`: Signed and unsigned 8-bit integers
- `int16_t`, `uint16_t`: Signed and unsigned 16-bit integers
- `int32_t`, `uint32_t`: Signed and unsigned 32-bit integers
- `int64_t`, `uint64_t`: Signed and unsigned 64-bit integers

### Minimum-width Integer Types
These types are guaranteed to be at least the specified width, but can be wider if the system's native integer types are wider:

- `int_least8_t`, `uint_least8_t`: Signed and unsigned integers with a minimum width of 8 bits
- `int_least16_t`, `uint_least16_t`: Signed and unsigned integers with a minimum width of 16 bits
- `int_least32_t`, `uint_least32_t`: Signed and unsigned integers with a minimum width of 32 bits
- `int_least64_t`, `uint_least64_t`: Signed and unsigned integers with a minimum width of 64 bits

### Fastest Minimum-width Integer Types
These types are the fastest integer types that are at least the specified width:

- `int_fast8_t`, `uint_fast8_t`: Fastest signed and unsigned integers with a minimum width of 8 bits
- `int_fast16_t`, `uint_fast16_t`: Fastest signed and unsigned integers with a minimum width of 16 bits
- `int_fast32_t`, `uint_fast32_t`: Fastest signed and unsigned integers with a minimum width of 32 bits
- `int_fast64_t`, `uint_fast64_t`: Fastest signed and unsigned integers with a minimum width of 64 bits

### Integer Types Capable of Holding Object Pointers
These types are guaranteed to be able to hold any pointer to an object:

- `intptr_t`: Signed integer type capable of holding a pointer
- `uintptr_t`: Unsigned integer type capable of holding a pointer

### Greatest-width Integer Types
These types represent the widest integer types supported by the implementation:

- `intmax_t`: The widest signed integer type
- `uintmax_t`: The widest unsigned integer type

### Limits of Specified-width Integer Types
The header also defines macros that specify the limits for each of these integer types. For example:

- `INT8_MIN`, `INT8_MAX`: Minimum and maximum values for `int8_t`
- `UINT8_MAX`: Maximum value for `uint8_t`
- `INT16_MIN`, `INT16_MAX`, `UINT16_MAX`: Similar limits for 16-bit integers
- `INT32_MIN`, `INT32_MAX`, `UINT32_MAX`: Similar limits for 32-bit integers
- `INT64_MIN`, `INT64_MAX`, `UINT64_MAX`: Similar limits for 64-bit integers

### Example Usage
Here's a simple example demonstrating how to use some of these types:



 This header file helps ensure that your code behaves consistently on different systems,
    especially when working with data that needs to be a specific size.


By running this program, you can see the changes in the `storage` variable after each bit manipulation operation.



 ## The binary representation

 The binary representation of the decimal number 9, 68,8,74 and 36
 9 = 0000 1001
 128 64 32 16 8 4 2 1 = 9
 0   0  0  0  1 0 0 1
-------------------------------------
 128 64 32 16 8 4 2 1  = 68
 0    1  0  0 0 0 1 0
-------------------------------------
 01000010 OR 00001000 == 01001010
-------------------------------------
 128 64 32 16  8  4  2  1  = 8
 0   0  0  0   1  0  0  0
-------------------------------------
 128  64   32   16   8   4   2    1  = 74
 2^7  2^6  2^5  2^4  2^3 2^2 2^1 2^0
 0   1  0  0   1  0  1  0
-------------------------------------
 128  64   32   16   8    4    2    1  = 36
 2^7  2^6  2^5  2^4  2^3 2^2 2^1 2^0
 0    0    1     0   0   1    0    0
 -------------------------------------
 
x:  9 =  00001001
y: 24 =  00011000
result x & y = 00001000 = 8
result x | y = 00011001 = 8


X << 2 = 36  00100100
X << 1 = 18  00010010
X >> 2 = 2   00000100
X >> 1 = 4   00001000

##  NOT (`~`)
The variable `x` is an unsigned integer with a value of `9`, and you are applying the bitwise NOT (`~`) operator to it. Let's break down the process to understand why the output seems like `x = -10`.

### Understanding Bitwise NOT and Unsigned Integers

1. **Bitwise NOT Operation**:
   - The bitwise NOT operator (`~`) inverts all the bits of the given number. Each `1` in the binary representation of the number becomes `0`, and each `0` becomes `1`.

2. **Binary Representation of `x = 9`**:
   - For a 32-bit unsigned integer, `9` is represented as:
     ```
     00000000 00000000 00000000 00001001
     ```

3. **Applying the Bitwise NOT (`~`)**:
   - Inverting all the bits of the above binary representation:
     ```
     11111111 11111111 11111111 11110110
     ```

4. **Interpreting the Result**:
   - The result of the bitwise NOT operation is now `11111111 11111111 11111111 11110110`, which is the binary representation of `4294967286` as an unsigned integer (since unsigned integers cannot be negative).
   - However, when you print this value using `%d`, it is interpreted as a **signed integer**. In a 32-bit signed integer representation, `11111111 11111111 11111111 11110110` corresponds to `-10`.

### Summary
- The actual result after `~x` is `4294967286` when treated as an unsigned integer.
- When you use the `%d` format specifier in `printf`, it interprets the result as a signed integer, which is `-10`.

To correctly print the result as an unsigned integer, you should use the `%u` format specifier:

```c
printf("~X : %u\n", r);
```

This will print `4294967286`, which is the unsigned interpretation of the bitwise NOT operation on `9`.