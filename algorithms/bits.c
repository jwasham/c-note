#include "btest.h"
#include <limits.h>

// Team Information Block
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "cburkhar+kraudoni", 
   /* Student name 1: Replace with the full name of first team member */
   "Casey Burkhardt",
   /* Login ID 1: Replace with the login ID of first team member */
   "cburkhar",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Kristin Raudonis",
   /* Login ID 2: Login ID of the second team member */
   "kraudoni"
};

// Problem / Solution Set
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) 
{
	// Applied DeMorgan's Law to expression:
	// ~(x|y)

	return (~x & ~y);
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y)
{
	// Applied DeMorgan's Law to expression:
	// (~x & y) | (x & ~y)
	// which resulted from expression:
	// x^y

	return (~(~(~x & y) & ~(x & ~y)));
}

/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y)
{
	// XOR operation can be used for equality evaluation
	// Double negation operation simplifies result from bit string to boolean value
	return(!!(x ^ y));
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
	// n << 3 adjusts n so its value is represented in bit form.
	// x is arithmetically shifted right to n*(2^3) bits.
	// The mask 0xFF is applied to return only the least significant byte, byte n
	return (0xFF & (x >> (n << 3)));
}

/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
	// x is first shifted left 31 bits to remove all but least significant bit.
	// x is then arithmetically shifted right 31 bits to copy the least significant bit to all positions.
	return ((x << 31) >> 31);
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n)
{
	// (x >> n) computes the arithmetic right shift of x by n.
	// ((1 << ((~n + 1) + 32)) + ~0) computes a dynamic mask that allows for arithmetically shifted bits to be converted to logical when necessary.
	return ((x >> n) & ((1 << ((~n + 1) + 32)) + ~0));
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
        // Mask 1 encompasses the 2 least significant bytes
        int mask1 = 0x11 | (0x11 << 8);

        // Mask 2 encompasses the final bytes
        int mask2 = mask1 | (mask1 << 16);

        // Sum will hold the number of 1 bits in the bit string
        // Computes the number of 1 bits within the first four bits
        int sum = x & mask2;
        sum = sum + ((x >> 1) & mask2);
        sum = sum + ((x >> 2) & mask2);
        sum = sum + ((x >> 3) & mask2);

        // At this point, sum represents the number of 1 bits within the first 4 bits.
        // in addition to extraneous bits beyond the first four bits.
        // As the binary position of these values do not represent their appropriate value in relation to the sum, they must be stripped.

        // Adjusts for overestimated sum value due to addition of 1 bits beyond first four bits.
        sum = sum + (sum >> 16);

        // Used to preserve current sum, and continue to mask 1 bits in the next byte.
        mask1 = 0xF | (0xF << 8);

        // Alternates the preserved bits of sum and adds alternating 4 bits together.
        sum = (sum & mask1) + ((sum >> 4) & mask1);

        // Shift sum value 1 byte and implement mask to limit resulting sum to 6 bits
        // Maximum representation of 6 bits, or a decimal value of 32, the word size for this problem set.
        return((sum + (sum >> 8)) & 0x3F);

/* Funny Solution
        int mask = 0x01;
        int sum = 0;

        sum = sum + (x & mask);
        sum = sum + (x >> 1 & mask);
        sum = sum + (x >> 2 & mask);
        sum = sum + (x >> 3 & mask);
        sum = sum + (x >> 4 & mask);
        sum = sum + (x >> 5 & mask);
        sum = sum + (x >> 6 & mask);
        sum = sum + (x >> 7 & mask);
        sum = sum + (x >> 8 & mask);
        sum = sum + (x >> 9 & mask);
        sum = sum + (x >> 10 & mask);
        sum = sum + (x >> 11 & mask);
        sum = sum + (x >> 12 & mask);
        sum = sum + (x >> 13 & mask);
        sum = sum + (x >> 14 & mask);
        sum = sum + (x >> 15 & mask);
        sum = sum + (x >> 16 & mask);
        sum = sum + (x >> 17 & mask);
        sum = sum + (x >> 18 & mask);
        sum = sum + (x >> 19 & mask);
        sum = sum + (x >> 20 & mask);
        sum = sum + (x >> 21 & mask);
        sum = sum + (x >> 22 & mask);
        sum = sum + (x >> 23 & mask);
        sum = sum + (x >> 24 & mask);
        sum = sum + (x >> 25 & mask);
        sum = sum + (x >> 26 & mask);
        sum = sum + (x >> 27 & mask);
        sum = sum + (x >> 28 & mask);
        sum = sum + (x >> 29 & mask);
        sum = sum + (x >> 30 & mask);
        sum = sum + (x >> 31 & mask);
        return(sum);
*/
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x)
{
	// The logical negative value of x.
	int negative_x = ~x + 1;

	// If (x != 0), then the most significant bit (or sign bit) of either x or -x will be 1.
	// XOR the sign bit of x or -x with the mask 0x01 to reproduce functionality of !
	return((((x >> 31) & 0x01) | ((negative_x >> 31) & 0x01)) ^ 0x01);
}

/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x)
{
        // The logical negative value of x.
	int negative_x = ~x + 1;

	// x and the logical negative value of x combined with the & operator properly produce the desired mask.
	return(x & negative_x);
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
	// Constant representing binary value: 1000 0000
	int x = 0x80;

	// The compliment of the binary value 1000 0000 shifted 24 bits to the left produces the following binary value:
	// 0111 1111 1111 1111 1111 1111 1111 1111
	// This is the largest 32-bit two's compliment integer
	return(~(x << 24));
}

/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x)
{

        // Boolean value indicating sign of x
        // 1 = Negative
        // 0 = Non-Negative
        int sign_x = x >> 31;
	
	// The negation of the sign bit of value x computes the appropriate boolean return value.
	return (!(sign_x));
}

/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
        // Boolean value indicating sign of x
        // 1 = Negative
        // 0 = Non-Negative
        int sign_x = x >> 31;

        // Boolean value indicating sign of y
        // 1 = Negative
        // 0 = Non-Negative
        int sign_y = y >> 31;

	// if the signs are equal, then
	// if x is larger, sign bit of (~y + x) is 0
	// if y is larger, sign bit of (~y + x) is 1
	int equal = !(sign_x ^ sign_y) & ((~y + x) >> 31);

	// if signs are not equal, these principles are reversed.
	int notEqual = sign_x & !sign_y;

	// this | returns 0 when it is x is greater, so you have to negate it.
	return !( equal | notEqual);
}

/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >> *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n)
{
	// Something is needed to account for x >> n if positive and x >> n + 1 if negative

	// Subtract 1 from 2^n
	// This accounts for the need to + 1
	int mask = (1 << n) + ~0;

	// Use & operator on mask and sign bit of x 
	int equalizer = (x >> 31) & mask;

	// Adds 1 if x was originally negative
	// Adds 0 if x was originally positive
	return (x + equalizer) >> n;
}

/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x)
{
        // Boolean value indicating sign of x
        // 1 = Negative
        // 0 = Non-Negative
        int sign_x = x >> 31;

	// XOR of value x and the sign bit of value x plus 1 plus the compliment of the sign bit of x returns the absolute value of x.
	return((x ^ (sign_x)) + (1 + ( ~(sign_x))));
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
	// The sum of x and y
	int xy_sum = x + y;
	
	// Boolean value indicating sign of x
	// 1 = Negative
	// 0 = Non-Negative
	int sign_x = x >> 31;

        // Boolean value indicating sign of y
        // 1 = Negative
        // 0 = Non-Negative
	int sign_y = y >> 31;

        // Boolean value indicating sign of the sum of x and y
        // 1 = Negative
        // 0 = Non-Negative
	int sign_sum_xy = xy_sum >> 31;

	// An overflow occurs when the sign of x and y are the same, but the sign of the sum of x and y is different
	return !(~(sign_x ^ sign_y) & (sign_x ^ sign_sum_xy));
}
