#include <stdio.h>

int main(void) {
  // Create variables Data Types
  int myNum = 5;            // Integer (whole number)
  float myFloatNum = 5.99;  // Floating point number
  char myLetter = 'D';      // The char data type is used to store a single character

  printf("Hello World! I am learning C. And it is awesome!\n");
  printf("My favorite number is: %d\n", myNum);
  printf("My number is %d and my letter is %c\n", myNum, myLetter);
  printf("\n");

  // Print values
  printf("%d\n", myNum);
  printf("%.2f\n", myFloatNum);
  printf("%c\n", myLetter);
  printf("\n");

  // Numeric types store a whole number and decimals
  int numI = 1000;
  float numF = 5.75;
  double numD = 19.99;

  printf("%d\n", numI);
  printf("%.3f\n", numF);
  printf("%.2lf\n", numD);
  printf("\n");

  // Scientific Numbers
  float f1 = 35e3;
  double d1 = 12E4;
  printf("%f\n", f1);
  printf("%lf\n", d1);
  printf("\n");

  int myInt = 15;
  int myOtherInt = 23;
  // Assign the value of myOtherNum (23) to myNum
  myInt = myOtherInt;
  // myNum is now 23, instead of 15
  printf("myNum = %d\n", myInt);
  printf("\n");

  // Set Decimal Precision
  float myFloat = 3.5;
  double myDouble = 19.99;

  printf("%f\n", myFloat);    // Outputs 3.500000
  printf("%lf\n", myDouble);  // Outputs 19.990000
  printf("\n");

  // remove the extra zeros
  printf("%f\n", myFloat);    // Default will show 6 digits after the decimal point
  printf("%.1f\n", myFloat);  // Only show 1 digit
  printf("%.2f\n", myFloat);  // Only show 2 digits
  printf("%.4f\n", myFloat);  // Only show 4 digits
  printf("\n");

  // Create a variable and assign the value 15 to it
  int myNums = 15;
  // Declare a variable without assigning it a value
  int myOther;
  // Assign the value of myNum to myOtherNum copy values to empty variables:
  myOther = myNums;

  // myOtherNum now has 15 as a value
  printf("myOtherNum = %d\n", myOther);
  printf("\n");

  // ASCII values to display certain characters.
  char a = 65, b = 66, c = 67;
  printf("Char-a = %c\n", a);
  printf("Char-b = %c\n", b);
  printf("char-c = %c\n", c);
  printf("\n");

  /**
  * The value -61 appears due to overflow in the char data type.
  * The actual computation involves wrapping around from
  * the maximum positive value to the minimum negative value.
  * Here's a step-by-step breakdown of the overflow:
      Maximum char value: 127
      195 - 127 - 1 = 67
  * So, we wrap around to the negative side by taking 67 steps from -128:
      -128 + 67 = -61
  *Thus, the value 195 wraps around to -61 when stored in a signed char
  */
  char as = 'a', bs = 'b', cs;
  cs = as + bs;
  printf("a = %d\n", as);
  printf("b = %d\n", bs);
  printf("c = %d\n", cs);
  printf("\n");

  // If you need to store the result of the addition without overflow,
  // you should use a larger data type, such as int.
  char as1 = 'a', bs1 = 'b';
  int cs1 = as1 + bs1;
  printf("a = %d\n", as1);
  printf("b = %d\n", bs1);
  printf("c = %d\n", cs1);
  printf("\n");

  // To store multiple characters/text
  char multipleCharacters[] = "Hello World!";
  printf("%s\n", multipleCharacters);
  printf("\n");

  int xs = 5, ys = 6, zs = 50;
  printf("The total = %d\n", xs + ys + zs);
  printf("\n");

  int num1, num2, num3;
  num1 = num2 = num3 = 50;
  printf("Result = %d\n", num1 + num2 + num3);
  printf("\n");

  // Good variable name
  int minutesPerHour = 60;
  printf("minutesPerHour = %d\n", minutesPerHour);
  printf("\n");

  // constant which means unchangeable and read-only:
  const double PI = 3.14;  // constant
  const int MYCONST = 15;  // myNum will always be 15
  const int MINUTESPERHOUR = 60;
  const int BIRTHYEAR = 1980;

  printf("Value of PI: %lf\n", PI);
  printf("Value of Int: %d\n", MYCONST);
  printf("Value of minutes: %d\n", MINUTESPERHOUR);
  printf("Value of birth: %d\n", BIRTHYEAR);
  printf("\n");

  // Arithmetic Operators addition + to add together two values
  int sum1 = 100 + 50;     // 150 (100 + 50)
  int sum2 = sum1 + 250;   // 400 (150 + 250)
  int sum3 = sum2 + sum2;  // 800 (400 + 400)
  printf("Sum1: %d\n", sum1);
  printf("Sum2: %d\n", sum2);
  printf("Sum3: %d\n", sum3);

  // Add two numbers and print sum
  int x = 5;
  int y = 6;
  int sum = x + y;
  printf("Sum: %d\n", sum);
  printf("\n");

  // Arithmetic Operators Subtracts '-' one value from another
  int term1 = 5;
  int term2 = 3;
  int difference = term1 - term2;
  printf("Difference: %d\n", difference);
  printf("\n");

  // 	Arithmetic Operators Multiplies  '*' two values
  int term3 = 5;
  int term4 = 2;
  int product = term3 * term4;
  printf("Product: %d\n", product);
  printf("\n");

  // Arithmetic Operators Divides '/' one value by another
  int m = 10;
  int n = 2;
  int divide = m / n;
  printf("Divide: %d\n", divide);
  printf("\n");

  // Arithmetic Operators '%' Returns the division remainder
  int z = 5;
  int r = 2;
  int remainder = z % r;
  printf("Remainder: %d\n", remainder);
  printf("\n");

  // Arithmetic Operators Increases '++' the value of a variable by 1
  int increase = 5;
  printf("Increase: %d\n", ++increase);
  printf("\n");

  // Arithmetic Operators Decreases '--' the value of a variable by 1
  int decrease = 5;
  printf("Decrease: %d\n", --decrease);
  printf("\n");

  // Assignment operator '='
  int assignment = 10;
  printf("Value: %d\n", assignment);
  printf("\n");

  // The addition assignment operator (+=):
  int addition = 10;
  addition += 5;
  printf("Addition: %d\n", addition);
  printf("\n");

  // The subtracts assignment operator (-=):
  int subtracts = 10;
  subtracts -= 5;
  printf("Subtracts: %d\n", subtracts);
  printf("\n");

  // The multiplies assignment operator (*=):
  int multiplies = 10;
  multiplies *= 5;
  printf("Multiplies: %d\n", multiplies);
  printf("\n");

  // The division assignment operator (/=):
  int divides = 10;
  divides /= 2;
  printf("Divide: %d\n", divides);
  printf("\n");

  // The modulus assignment operator (%=):
  int modulus = 5;
  modulus %= 2;
  printf("Modulus: %d\n", modulus);
  printf("\n");

  // The assignment operator (&=):
  int and = 5;
  and &= 3;
  printf("Modulus: %d\n", and);
  printf("\n");

  // The assignment operator (|=):
  int or = 5;
  or |= 3;
  printf("Modulus: %d\n", or);
  printf("\n");

  // The assignment operator (^=):
  int comp = 5;
  comp ^= 3;
  printf("Modulus: %d\n", comp);
  printf("\n");

  // The assignment operator (>>=):
  int greatThan = 5;
  greatThan >>= 3;
  printf("Modulus: %d\n", greatThan);
  printf("\n");

  // The assignment operator (<<=):
  int lessThan = 5;
  lessThan <<= 3;
  printf("Modulus: %d\n", lessThan);
  printf("\n");

  // Use of Bitwise Operators
  // a = 5(00000101), b = 9(00001001)
  unsigned int a = 5, b = 9;

  // The result is 00000001
  printf("a = %u, b = %u\n", a, b);
  printf("a&b = %u\n", a & b);

  // The result is 00001101
  printf("a|b = %u\n", a | b);

  // The result is 00001100
  printf("a^b = %u\n", a ^ b);

  // The result is 11111010
  printf("~a = %u\n", a = ~a);

  // The result is 00010010
  printf("b<<1 = %u\n", b << 1);

  // The result is 00000100
  printf("b>>1 = %u\n", b >> 1);
  return 0;
}
