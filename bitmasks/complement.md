 # unsigned integer

 The unsigned integer value `4294967290` is already in its unsigned form. However, if you meant to ask about its binary form or its signed equivalent, here's the breakdown:

- **Binary Representation**: The number `4294967290` in a 32-bit unsigned integer is `11111111111111111111111111111010`.
  
- **Signed Equivalent**: In a 32-bit signed integer system, the binary `11111111111111111111111111111010` represents `-6` (since the most significant bit is `1`, indicating a negative number in two's complement representation).

In summary:
- **Unsigned integer**: `4294967290`
- **Binary form**: `11111111111111111111111111111010`
- **Signed integer equivalent**: `-6`


### One's Complement Representation

One's complement is a method for representing signed numbers in binary form. In one's complement, positive numbers are represented as they are in binary, while negative numbers are represented by inverting all bits of the positive counterpart.

#### Example: Representing `+5` and `-5` in One's Complement

- **+5 in binary (8-bit representation)**: `00000101`
- **-5 in one's complement**: To get `-5`, invert all the bits of `+5`:
  - `00000101` becomes `11111010`

So:
- **+5** = `00000101`
- **-5** = `11111010` (one's complement of `+5`)

### Two's Complement Representation

Two's complement is another method for representing signed numbers in binary form. In two's complement, positive numbers are the same as their binary representation, but negative numbers are represented by inverting all bits (like one's complement) and then adding 1 to the least significant bit.

#### Example: Representing `+5` and `-5` in Two's Complement

- **+5 in binary (8-bit representation)**: `00000101`
- **-5 in two's complement**: 
  1. Invert all the bits of `+5`: `11111010` (same as one's complement).
  2. Add `1` to the least significant bit: `11111010 + 1 = 11111011`

So:
- **+5** = `00000101`
- **-5** = `11111011` (two's complement of `+5`)

### Summary

For an 8-bit system:
- **One's complement of `+5`**: `11111010`
- **Two's complement of `+5`**: `11111011`

In one's complement, the negative number is formed by inverting the bits, while in two's complement, it's formed by inverting the bits and adding 1.

---

### Understanding 2's Complement
The 2's complement of a binary number is a way of representing negative numbers in binary form. The 2's complement is obtained by:

1. **Inverting all the bits** (changing `0` to `1` and `1` to `0`) to get the 1's complement.
2. **Adding 1** to the resulting 1's complement to obtain the 2's complement.

### Example: 2's Complement of a Number
Let's take your binary number `00010100` as an example.

1. **Start with the binary number**: `00010100` (which is 20 in decimal).

2. **Invert the bits**: 
   - Original: `00010100`
   - Inverted: `11101011` (This is the 1's complement of the original number)

3. **Add 1 to the inverted bits**:
   - `11101011`
   - `+       1`
   - `------------`
   - `11101100`

So, the 2's complement of `00010100` is `11101100`.

### Interpretation in C
In C, binary numbers are usually represented using `int` or `unsigned int` types. The 2's complement is the standard way to represent signed integers. 

For example, let's say you have an `int` variable `x = 20`:

- In binary, `20` is represented as `00010100` in an 8-bit system.
- When you store `-20` in an `int`, it is stored as `11101100`, which is the 2's complement of `20`.

### Output Explanation
- The binary representation of `x = 20` is `00010100`.
- The binary representation of `y = -20` will be `11101100`.

### Summary
- The 2's complement process converts a positive number to its negative equivalent in binary.
- In C, when you use negative integers, they are stored in memory using the 2's complement form.
- Your example `00010100` becomes `11101100` when you apply the 2's complement process, which corresponds to `-20` in a signed 8-bit integer.


`00010100` 
`11101100`
128   64   32   16  8    4   2   1
2^7  2^6  2^5  2^4  2^3 2^2 2^1 2^0
 1    1    1    0    1   1   0   0 
 - `11101 011`
   `+      1`
   `------------`
    `11101100`