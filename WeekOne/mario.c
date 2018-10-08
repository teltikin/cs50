
/* Iltikin Wayet
 * Mario Program; More Comfortable
 * 9/26/18
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    printf("Height:");
    height = get_int();
    
    while (height > 8 || height <= 0)
    {
        printf("Height:");
        height = get_int();
    }
    
    for (int a = 1; a <= height; a++)
    {
        for (int b = height - a; b >= 1; b--)
        {
            printf(" ");
        }
        for (int c = 0; c < a; c++)
        {
            printf("#");
        }
        printf(" ");
        for (int c = 0; c < a; c++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}
