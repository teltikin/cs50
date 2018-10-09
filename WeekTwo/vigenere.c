#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{    
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }
    else 
    {
        for (int x = 0, y = strlen(argv[1]); x < y; x++)
        {
            if (!isalpha(argv[1][x]))
            {
                printf("Usage: ./vigenere keyword");
                return 1;
            }    
        }
        
        printf("plainttext: ");
        string text = get_string();

        string key = argv[1];
        int keyLength = strlen(key);

        printf("cipertext: ");
        for (int x = 0, y = 0, z = strlen(text); x < z; x++)
        {            
            int cipher = tolower(key[y % keyLength]) - 'a';

            if (isupper(text[x]))
            {
                y++;
                printf("%c", 'A' + (text[x] - 'A' + cipher % 26));
            }
            else if (islower(text[x]))
            {
                y++;
                printf("%c", 'a' + (text[x] - 'a' + cipher) % 26);
            }
            else
            {
                printf("%c", text[x]);
            }
        }
        printf("\n");
    }
    return 0;
}
