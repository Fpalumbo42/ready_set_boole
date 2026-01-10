# Ready, Set, Boole!

Boolean Algebra and Bitwise Operations - Personal Learning Notes

## Binary Number System

### Binary ↔ Decimal Conversion

![Binary conversion diagram](readme_images/bits.png)

Each bit position = a power of 2

**Key concept**: Binary uses powers of 2 (like decimal uses powers of 10)

## Bitwise Operators

### AND (&) - Both must be 1
```
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```
**Use**: Detect where both bits are 1

### OR (|) - At least one is 1
```
  0101  (5)
| 0011  (3)
------
  0111  (7)
```

### XOR (^) - Different bits = 1
```
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```
**Use**: Sum without carry

### NOT (~) - Flip all bits
```
~ 0101 → 1010
```

### Shifts (<< >>)
```
0101 << 1 → 1010   (multiply by 2)
1010 >> 1 → 0101   (divide by 2)
```

## Exercises

### ex00 - Adder
Build addition using ONLY bitwise operators (no `+`)
- Complexity: O(log n) time, O(log n) space

**Complexity explanation**:
- O(log n) measures how execution time grows with input size
- For our adder: n = max value representable, iterations = number of bits
- uint32_t needs 32 bits → log₂(2³²) = 32 iterations max
- No matter the values (5+3 or 4 billion+1), max 32 iterations
- O(log n) = O(32) = O(1) for fixed-size types
![Binary conversion diagram](readme_images/ex00_adder.png)

### ex01 - Multiplier
Build multiplication using ONLY bitwise operators (no `*`)
- Complexity: O(1) time, O(1) space

**Algorithm**: Shift and add
1. Check if last bit of `b` is 1 → if yes, add `a` to result
2. Shift `a` left (×2) and `b` right (÷2)
3. Repeat until `b` becomes 0

![Multiplier diagram](readme_images/ex01_multiplier.png)

### ex02 - Gray Code
Convert binary to Gray code using ONLY bitwise operators
- Complexity: O(1) time, O(1) space

**What is Gray Code?**
A binary encoding where consecutive values differ by only 1 bit.

**Why useful?** Prevents errors in encoders, sensors, and data transmission.

**Formula**: `gray(n) = n ^ (n >> 1)`

**How it works:**
- Shift n right by 1 → compares each bit with its neighbor
- XOR original with shifted → each result bit = difference with previous bit

**Example: n = 5**
```
n     = 0101 (5)
n>>1  = 0010
XOR   = 0111 (7 in Gray code)
```

**Sequence 0-7:**
```
Decimal | Binary | Gray | Bits changed
--------|--------|------|-------------
   0    | 0000   | 0000 |     -
   1    | 0001   | 0001 |     1
   2    | 0010   | 0011 |     1
   3    | 0011   | 0010 |     1
   4    | 0100   | 0110 |     1
   5    | 0101   | 0111 |     1
   6    | 0110   | 0101 |     1
   7    | 0111   | 0100 |     1
```

### ex03-09
Boolean logic, truth tables, SAT solving, set theory...
