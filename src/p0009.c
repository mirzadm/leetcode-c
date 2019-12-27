/*
 * Determine whether an integer is a palindrome.
 * An integer is a palindrome when it reads the same backward as forward.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 50


bool is_palindrome(int num)
{
    char str[MAX_LEN];
    int left, right, length;

    sprintf(str, "%d", num);
    left = 0;
    right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    if (is_palindrome(121))
        printf("Yes");
    else
        printf("No");
}
