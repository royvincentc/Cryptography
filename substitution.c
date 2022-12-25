#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int checkKey();
void substitute();
void alpha_arr_val(char pos, string key);

int main(int argc, string argv[])
{
    // terminal command numbers
    if (argc == 2)
    {
        // 26 characters in the alphabet
        if (strlen(argv[1]) == 26)
        {
            // check for string characters
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                // check for non - alphabet input
                if (! isalpha(argv[1][i]))
                {
                    // ask user to give 26-character key
                    printf("Key must contain 26 characters.\n");
                    // return error code 1
                    return 1;
                }
                // check for arg i characters
                for (int j = i + 1; j < strlen(argv[1]); j++)
                {
                    // check for repeating character, to upper ensure that repeating char even if lowercase can be checked
                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        // ask user to give nonrepeating characters
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            // make a function for substitution for argv 1
            substitute(argv[1]);
        }

        else
        {
            // if condition = false, ask again for 26-char key
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // condition met req = true
    return 0;
}

void substitute(string key)
{
    // get input from user, store variable to str(p)
    string p = get_string("Plain text: ");

    // print out the ciphered plain text using the key provided
    printf("ciphertext: ");

    // increment the value of the plain text provided
    for (int k = 0; k < strlen(p); k++)
    {
        // check if plain text provided is alphabet
        if (isalpha(p[k]))
        {
            // store value
            char d = p[k];
            if (islower(p[k]))
            {
                alpha_arr_val(tolower(d), key);
            }
            else
            {
                alpha_arr_val(toupper(d), key);
            }
        }
        else
        {
            // print characters such as punctuation marks
            printf("%c", p[k]);
        }
    }

    printf("\n");
}

void alpha_arr_val(char e, string key)
{
    // array of letters
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int l = 0; l < strlen(alpha); l++)
    {
        if (islower(e))
        {
            if (e == tolower(alpha[l]))
            {
                printf("%c", tolower(key[l]));
            }
        }
        else
        {
            if (e == toupper(alpha[l]))
            {
                printf("%c", toupper(key[l]));
            }
        }
    }
}
