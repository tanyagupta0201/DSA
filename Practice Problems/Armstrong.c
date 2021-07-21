#include <stdio.h>
int main() 
{
    int num, originalNum, remainder, result = 0;
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) 
    {
       
        remainder = originalNum % 10;
        
       result += remainder * remainder * remainder;
        
       // removing last digit from the orignal number
       originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}