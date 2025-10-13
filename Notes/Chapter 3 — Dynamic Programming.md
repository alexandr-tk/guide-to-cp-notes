
## Dynamic Programming

- **Key idea:** breaking a problem into smaller subproblems and gradually build a solution
- **Usage:** any problem where an answer depends on a smaller subproblem
- Commonly involves 2D arrays and used when constraints are small
- Don't fall into the greedy trap. DP is the opposite of greedy
```
There should always be base case (ex. dp[0]=0)
```

## Bit sets & Bit masks

Bit sets in C++ automatically manage a binary number with n bits, keeping all the binary operations. Complexity is n/64 or n/32 depending on how numbers are stored in the operating system.

```cpp
bitset<n> a;
```

Bitmasks can be used to solve dp problems when 2^n gives appropriate time complexity.

```cpp
__builtin_popcount(i) // Count the number of bits = 1 in i
__builtin_ctz(i) // Count the number of trailing zeros
```


## Digit DP

Large numbers can be broken into digits using their string representation to calculate the numbers in the range that satisfy certain condition (ex. sum of digits equals S). 

