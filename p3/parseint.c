#include "parseint.h"

/*
 * Returns the value of c or -1 on error
 */
int parseDecimalChar(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}

/*
 * Parses a non-negative integer, interpreted as octal when starting with 0,
 * decimal otherwise. Returns -1 on error.
 */
int parseInt(char *string)
{
    int charCount = 0;
    int res = 0;
    if (string[charCount] == '0')
    {
        while (string[charCount] != '\0')
        {
            if (parseDecimalChar(string[charCount]) == -1)
            {
                return -1;
            }
            res = res * 8 + parseDecimalChar(string[charCount]);
            charCount++;
        }
    }
    
    while (string[charCount] != '\0')
    {
        if (parseDecimalChar(string[charCount]) == -1)
        {
            return -1;
        }
        res = res * 10 + parseDecimalChar(string[charCount]);
        charCount++;
    }   
    return res;
}
