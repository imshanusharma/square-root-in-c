/*
 * Program to calculate square root of a given positive number without using any inbuilt function.
 *
 * Compilation: gcc -o square_root square_root.c
 * Execution: ./square_root
 *
 * @Ujjwal, 1910991390, 17/07/2021
 * Assignment 1 (Homework)
 */

#include <stdio.h>

/*
 * Function to calculate square root of a number
 * 
 * Parameters
 * number: integer number whose square root to be calculated
 * precision: integer number for precision
 * 
 * Return the square root of given integer number
 */

float square_root_binary_search(int number, int precision) {
    
    int left = 0;
    int right = number;
    float ans;
    while(left <= right) {
        int mid = (left + right)/2;
        if(mid * mid == number) {
            ans = mid;
            break;
        }
        if(mid * mid < number) {
            ans = left;
            left = mid + 1;
        }
        else {
            right = mid-1;
        }
    }
    float increment = 0.1;
    for(int i = 0; i < precision; i++) {
        while(ans * ans < number) {
            ans += increment;
        }
        ans -= increment;
        increment = increment/10;
    }
    return ans;
}

int main()
{
    int number,precision;
    float result;
    
    printf("Enter the number : ");
    scanf("%d",&number);
    printf("Enter the precision : ");
    scanf("%d",&precision);
    
    result = square_root_binary_search(number,precision);
    printf("Answer is : %g",result);

    return 0;
}
