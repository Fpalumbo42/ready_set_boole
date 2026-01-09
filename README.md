# Ready, Set, Boole!

An introduction to Boolean Algebra and Bitwise Operations - 42 École Project

## Table of Contents
- [Understanding Bits](#understanding-bits)
- [Binary Number System](#binary-number-system)
- [Bitwise Operators](#bitwise-operators)
- [Binary Arithmetic](#binary-arithmetic)
- [Type Sizes and Memory](#type-sizes-and-memory)
- [Resources](#resources)

---

## Understanding Bits

### What is a Bit?

A **bit** (binary digit) is the smallest unit of information in computing. It can have only two values:
- **0** (false, off)
- **1** (true, on)

Everything in a computer - numbers, text, images, programs - is ultimately stored as sequences of bits.

### Why Binary?

Computers use binary because:
- Electronic circuits have two stable states (on/off, high voltage/low voltage)
- Binary logic is simple and reliable
- All mathematical operations can be performed using just 0s and 1s

---

## Binary Number System

### Place Value System

Just like decimal uses powers of 10, binary uses powers of 2:

```
Decimal: 1234 = 1×10³ + 2×10² + 3×10¹ + 4×10⁰
Binary:  1011 = 1×2³  + 0×2²  + 1×2¹  + 1×2⁰ = 8 + 0 + 2 + 1 = 11 (decimal)
```

### Converting Decimal to Binary

**Example: Convert 13 to binary**

```
Position:  3   2   1   0
Power:     2³  2²  2¹  2⁰
Value:     8   4   2   1

13 = 8 + 4 + 1
   = 1   1   0   1  (binary)
```

![Binary conversion diagram](readme_images/bits.png)

**Visual explanation**: Each bit position represents a power of 2. To convert from binary to decimal, multiply each bit by its corresponding power of 2 and sum the results.

### 8-bit Representation

An 8-bit number can represent values from 0 to 255 (2⁸ - 1):

```
Bit position:  7   6   5   4   3   2   1   0
Power of 2:    128 64  32  16  8   4   2   1

Example: 13 in 8 bits
Binary:        0   0   0   0   1   1   0   1
Calculation:   0 + 0 + 0 + 0 + 8 + 4 + 0 + 1 = 13
```

---

## Bitwise Operators

Bitwise operators work on individual bits of numbers.

### AND operator (&)

Returns 1 only if **both** bits are 1:

```
  0101  (5)
& 0011  (3)
------
  0001  (1)

Truth table:
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```

**Use case**: Checking if specific bits are set, masking

### OR operator (|)

Returns 1 if **at least one** bit is 1:

```
  0101  (5)
| 0011  (3)
------
  0111  (7)

Truth table:
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1
```

**Use case**: Setting specific bits, combining flags

### XOR operator (^)

Returns 1 if bits are **different**:

```
  0101  (5)
^ 0011  (3)
------
  0110  (6)

Truth table:
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```

**Use case**: Toggling bits, detecting differences, addition without carry

### NOT operator (~)

Inverts all bits (0→1, 1→0):

```
~ 0101  (5 in 4-bit)
------
  1010  (10 in 4-bit, or -6 in signed)
```

**Note**: Result depends on the number of bits in the type!

### Left Shift (<<)

Shifts bits to the left, filling with zeros on the right:

```
  0101  (5)
<< 1
------
  1010  (10)

  0101  (5)
<< 2
------
 10100  (20)
```

**Effect**: Multiplies by 2 for each shift position

### Right Shift (>>)

Shifts bits to the right:

```
  1010  (10)
>> 1
------
  0101  (5)

  1010  (10)
>> 2
------
  0010  (2)
```

**Effect**: Divides by 2 for each shift position (integer division)

---

## Binary Arithmetic

### Addition by Hand

Adding binary numbers works like decimal addition, but with carry rules:

```
Rule:
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10 (0, carry 1)

Example: 5 + 3
    0101  (5)
  + 0011  (3)
  ------
    1000  (8)

Step by step (right to left):
Position 0: 1 + 1 = 0, carry 1
Position 1: 0 + 1 + carry(1) = 0, carry 1
Position 2: 1 + 0 + carry(1) = 0, carry 1
Position 3: 0 + 0 + carry(1) = 1
```

### Key Observation for Adder

When adding two bits:
- **XOR gives the sum without carry**: `1 ^ 1 = 0` (we write 0 and carry)
- **AND detects where carries occur**: `1 & 1 = 1` (both bits set means carry)
- **Shift left positions carries correctly**: carry affects the next position

---

## Type Sizes and Memory

### Fixed-Size Types

In C++ (and most languages), integer types have fixed sizes:

```cpp
uint8_t   x;  // Always 8 bits  (0 to 255)
uint16_t  y;  // Always 16 bits (0 to 65,535)
uint32_t  z;  // Always 32 bits (0 to 4,294,967,295)
uint64_t  w;  // Always 64 bits (0 to 18,446,744,073,709,551,615)
```

### Leading Zeros

**Important**: Small numbers still use all bits of their type!

```cpp
uint32_t a = 5;

// In memory (all 32 bits):
// 00000000 00000000 00000000 00000101

// We often write just: 0101
// But the leading zeros are always there!
```

### Why This Matters

When using bitwise operators:

```cpp
uint32_t a = 5;   // 32 bits: 00...00101
uint32_t b = 3;   // 32 bits: 00...00011

// Operations work on ALL 32 bits:
a & b  // AND applied to all 32 bit positions
a | b  // OR applied to all 32 bit positions
a ^ b  // XOR applied to all 32 bit positions
```

### Complexity Implications

For fixed-size types like `uint32_t`:
- Maximum value n = 2³² - 1
- Number of bits = log₂(n) ≈ 32
- O(log n) time = O(32) = **O(1)** in practice

For arbitrary-precision integers:
- Number of bits grows with the value
- O(log n) actually varies with input size

---

## Resources

### Official Documentation
- **Subject PDF**: `en.subject.pdf` - The ultimate reference
- **CLAUDE.md**: Project-specific guidelines and constraints

### Concepts to Study
- Binary number system and conversions
- Logic gates (AND, OR, NOT, XOR)
- Boolean algebra laws (De Morgan's, distributivity)
- Reverse Polish Notation (RPN)
- Propositional logic
- Normal forms (NNF, CNF)
- SAT solving
- Set theory operations

### Practice Exercises
1. Convert decimal numbers to binary and back
2. Perform binary addition on paper
3. Try XOR, AND, OR operations manually
4. Trace through how carries propagate in addition

---

## Project Structure

```
ready_set_boole/
├── ex00/          # Adder (bitwise only, no +)
├── ex01/          # Multiplier (bitwise only, no *)
├── ex02/          # Gray code
├── ex03/          # Boolean evaluation (RPN)
├── ex04/          # Truth table generation
├── ex05/          # Negation Normal Form
├── ex06/          # Conjunctive Normal Form
├── ex07/          # SAT solver
├── ex08/          # Powerset
├── ex09/          # Set evaluation
├── ex10/          # Space-filling curve (bonus)
├── ex11/          # Inverse curve (bonus)
└── en.subject.pdf
```

---

**Note**: This is an educational project. The goal is to **understand** how computers work at the bit level. Take time to work through examples on paper before coding!

**Last updated**: January 2026
