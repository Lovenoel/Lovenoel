#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file which is
 *  to be created.
 * @text_content: A pointer to a string which is to be written
 * to the file.
 *
 * Return: -1 If the function fails
 * Otherwise return - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fD, actual, lens = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (lens = 0; text_content[lens];)
			lens++;
	}
	fD = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	actual = write(fD, text_content, lens);
	if (fD == -1 || actual == -1)
		return (-1);
	close(fD);
	return (1);
}
