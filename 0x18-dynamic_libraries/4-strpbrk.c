#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any set of bytes
 * @s: String to search
 * @accept: String containing bytes to search for
 * Return:  a pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s)
    {
        for (char *b = accept; *b; b++)
        {
            if (*s == *b)
            {
                return (s);
            }
        }
        s++;
    }
    return (NULL);
}
