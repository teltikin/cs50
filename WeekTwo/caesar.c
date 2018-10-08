#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("%s\n", "Usage: ./caesar key");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]) % 26;
        if (key == 0)
            printf("Enter a valid key.");
        
        printf("plaintext: ");
        string plaintext = get_string();
        if (plaintext == NULL)
            printf("Enter valid plaintext.");
        
        printf("cipertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int character;
            int char1 = (((int)plaintext[i] - 65 + key) % 26);
            int char2 = (((int)plaintext[i] - 97 + key) % 26);
            if (isupper(plaintext[i]))
            {
                character = char1 + 65;
                printf("%c", (char) character);
            }
            else if (islower(plaintext[i]))
            {
                character = char2 + 97;
                printf("%c", (char) character);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
