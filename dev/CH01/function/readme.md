```c
/* power: raise base to n-th power; n >= 0; version 2 */
int power(int base, int n) {
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```
The parameter n is used as a temporary variable, and is counted down (a for loop that runs backwards) until it becomes zero; there is no longer a need for the variable i. Whatever is done to n inside power has no effect on the argument that power was originally called with.


The story is different for arrays. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array - there is no copying of array elements. By subscripting this value, the function can access and alter any argument of the array. This is the topic of the next section.