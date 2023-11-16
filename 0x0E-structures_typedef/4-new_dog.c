#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char *_strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _strlen - finds the length of a string
 * @str: the string to be measured
 * Return: the length of a string
*/

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcopy - copies a string pointed to by src, including the
 * terminating null byte, to a buffer pointed to by dest
 * @dest: the buffer storing the string copy
 * @src: the source string
 *
 * Return: the pointer to dest
*/

char *_strcopy(char *dest, char *src)
{
	int index, len;

	while (src[len] != '\0')
	{
		len++;
	}

	for (index = 0;index < len; index++)
	{
		dest[index] = src[index];
	}

	dest[index] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new dog
 * @name: name of the new dog
 * @age:age of the new dog
 * @owner: owner of the new dog
 *
 * Return: the new struct dog
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog2;
	int len1 len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	dog2 = malloc(sizeof(dog_t));
	if (dog2 == NULL)
		return (NULL);

	dog2->name = malloc(sizeof(char) * (len1 + 1));
	if (dog2->name == NULL)
	{
		free(dog2);
		return (NULL);
	}

	dog2->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog2->owner == NULL)
	{
		free(dog2->name);
		free(dog2);
		return (NULL);
	}

	 _strcpoy(dog2->name, name);
	dog2->age = age;
	_strcopy(dog2->owner, owner);

	return (dog2);
}
