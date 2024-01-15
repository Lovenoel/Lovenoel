#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: string to search for
 * Return:  a pointer to the beginning of the located substring,
 *  or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
    char *k, *e;

    while (*haystack)
    {
        k = haystack;
        e = needle;

        while (*e && (*k == *e))
        {
            k++;
            e++;
        }
        if (*e == '\0')
        {
            return (haystack);
        }
        haystack++;
    }
    return (NULL);
}
