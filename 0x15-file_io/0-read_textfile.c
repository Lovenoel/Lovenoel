#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- reads a text file and prints it
 * to the standard output
 * @filename: text file to be read
 * @letters: number of letters to be read and printed
 * Return: actual number of bytes read and printed,
 * 0 if the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fD;
	ssize_t actual_num;
	ssize_t td;

	fD = open(filename, O_RDONLY);
	if (fD == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	td = read(fD, buffer, letters);
	actual_num = write(STDOUT_FILENO, buffer, td);
	free(buffer);
	close(fD);
	return (actual_num);
}
