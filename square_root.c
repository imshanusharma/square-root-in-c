#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float binary_search(int n, int left, int p) {
    int right = n;
    float ans;
    while(left <= right) {
        int mid = (left + right)/2;
        if(mid * mid == n) {
            ans = mid;
            break;
        }
        if(mid * mid < n) {
            ans = left;
            left = mid + 1;
        }
        else {
            right = mid-1;
        }
    }
    float increment = 0.1;
    for(int i = 0; i <= p; i++) {
        while(ans * ans < n) {
            ans += increment;
        }
        ans -= increment;
        increment = increment/10;
    }
    int temp = ans * pow(10,p);
    ans = temp / pow(10,p);
    return ans;
}

int main()
{
    int n,p;
    float result;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Enter the precision : ");
    scanf("%d",&p);
    result = binary_search(n,0,p);
    printf("Answer is : %g",result);

    return 0;
}
