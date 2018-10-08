  
  /* Iltikin Wayet
   * Credit Program; More comfortable.
   * 9/29/18
   */
   
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

string card(long num)
{
    if ((num > 3400000000000 && num < 3500000000000) || (num > 3700000000000 && num < 3800000000000))
    {
        return "AMEX";
    }
    else if (num > 5100000000000000 && num < 5600000000000000)
    {
        return "MASTERCARD";
    }
    else if ((num > 4000000000000 && num < 500000000000) || (num > 4000000000000000 && num < 5000000000000000))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

int luhns(long num)
{
    int sum = 0, sum2 = 0;
    // 2x's every other number starting at second to last, then adds all of their digits together.
    for (int i = num / 10; i >= 1; i /= 100)
    {
        if (2 * (i % 10) >= 10)
            sum += (2 * (i % 10) / 10) + (2 * (i % 10) % 10);
        else
            sum += 2 * (i % 10);
    }
    // Adds all of the remaining numbers.
    for (int i = num; i >= 1; i /= 100)
    {
        sum2 += i % 10;
    }
    return sum + sum2;
}

string validate(long num)
{
    int luhnNum;
    string typeCard;
    
    typeCard = card(num);
    luhnNum = luhns(num);
    
    if (luhnNum % 10 == 0)
        return typeCard;
    else
        return "INVALID";
}

int main(void)
{
    int creditNum;
    string legit;
    
    printf("Number:");
    creditNum = get_long();
    legit = validate(creditNum);
    printf("%s\n", legit);
}
