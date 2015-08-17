/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int re = 0;

        while(0 != n)
        {
            n = n&(n - 1);
            ++re;
        }

        return re;
    }
};
/*
n = 0x110100    n-1 = 0x110011      n&(n - 1) = 0x110000 
n = 0x110000    n-1 = 0x101111      n&(n - 1) = 0x100000 
n = 0x100000    n-1 = 0x011111      n&(n - 1) = 0x0 
*/