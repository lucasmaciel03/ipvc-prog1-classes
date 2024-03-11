/*
 *
 * 2. Implement a recursive function that calculates the length of a string.
 * Unrecursive the function implemented previously.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate the length of a string using recursion
int string_length(char *str){ // *str is a pointer to the first character of the string
    if (*str == '\0') // \0 is the null character
    {
        return 0;
    }
    else
    {
        return 1 + string_length(str + 1); // str + 1 is the address of the next character
    }
}

// function to calculate the length of a string using iteration
int string_length_non_recursive(char *str_){
    int count = 0;
    while (*str_ != '\0') // \0 is the null character
    {
        count++;
        str_++;
    }
    return count;
}

int main(){
    char str[256];  
    int res = 0;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    res = string_length(str);
    printf("Recursion: Length of the string is %d\n", res);
    res = string_length_non_recursive(str);
    printf("Iteration: Length of the string is %d\n", res);
    
    
    return 0;
}