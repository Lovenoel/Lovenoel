#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);
/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file which the buffer
 * is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer_1;

	buffer_1 = malloc(sizeof(char) * 1024);

	if (buffer_1 == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer_1);
}
/**
 * close_file - Closes the file descriptors.
 * @fd: The file descriptor which is to be closed.
 */
void close_file(int fd)
{
	int n;

	n = close(fd);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is  not correct - exit code 97.
 * If file_fr does not exist or can't be read - exit code 98.
 * If file_two can't be created or written on to - exit code 99.
 * If file_two or file_fr can't be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fr, two, rr, actual;
	char *buffer_1;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer_1 = create_buffer(argv[2]);
	fr = open(argv[1], O_RDONLY);
	rr = read(fr, buffer_1, 1024);
	two = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (fr == -1 || rr == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer_1);
			exit(98);
		}
		actual = write(two, buffer_1, rr);
		if (two == -1 || actual == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer_1);
			exit(99);
		}
		rr = read(fr, buffer_1, 1024);
		two = open(argv[2], O_WRONLY | O_APPEND);
	} while (rr > 0);
	free(buffer_1);
	close_file(fr);
	close_file(two);
	return (0);
}
