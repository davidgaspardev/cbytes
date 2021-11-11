# Understanding about "string" in c

Everything is based on a series of uniformly creasing addresses, to which each address has a binary value and that value corresponds to character in the **ASCII table**.


## Character array and character pointer 

What is the difference between character array and character pointer ? </br>
Consider the following example:

```c
char arr[] = "Hello World"; // array version
char ptr* = "Hello World"; // pointer version
```
The type of both the variables is a pointer to `char` or `(char\*)`, so you can pass either of them to a function whose formal argument accepts an array of characters or character pointer. In C programming, the name of an array always points to the base address, roughly speaking, an array is a pointer.

Here are differences:
- 1 `arr` is an array of `12` characters. When compiler sees the statement:
    ```c
    char arr[] = "Hello World";
    ```
    It allocates `12` consecutive bytes of memory and associates the address of the first allocated byte with `arr`.
    ![allocations for char array in c](https://overiq.com/media/uploads/character-array-in-memory-1504599203175.png)
    On the other hand when the compiler sees the statement.
    ```c
    char ptr* = "Hello World";
    ```
    It allocates `12` consecutive bytes for string literal `"Hello World"` and `4` extra bytes for pointer variable `ptr`. And assigns the address of the string literal to `ptr`. So, in this case, a total of `16` bytes are allocated.
    ![allocations for char pointer in c](https://overiq.com/media/uploads/2020/07/26/character-pointer-and-string-literal-1504599248003.png)

## This library

In this library we have the following functions for manipulating strings:
- `length`: get the length of a string.
- `equal`: check if two strings are the same.
- `copy`: copy characters from one string to another string.
- `subcopy`: copy a specific portion of a string, using the starting index and an ending index, to another string.
- `subcopy_len`: copy a specific portion of a string, using the length, to another string.
- `subcopy_index_len`: copy a specific portion of a string, using the starting index and the length, to another string.