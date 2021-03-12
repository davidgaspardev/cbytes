# Understanding about "string" in c

Everything is based on a series of uniformly creasing addresses, to which each address has a binary value and that value corresponds to character in the **ASCII table**.


## Character array and character pointer 

What is the difference between character array and character pointer ?
Consider the following example:
```c
char arr[] = "Hello World"; // array version
char ptr* = "Hello World"; // pointer version
```