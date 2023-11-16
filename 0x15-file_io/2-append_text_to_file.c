#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file which is
 *  to be created.
 * @text_content: The string to be added to the end of the file.
 *
 * Return: -1 on failure or if the filename is NULL
 * If the file does not exist the user should not create it.
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist
 * or if you do not have the required permissions to write the file1
 * on success
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int m, actual, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	m = open(filename, O_WRONLY | O_APPEND);
	actual = write(m, text_content, len);
	if (m == -1 || actual == -1)
		return (-1);
	close(m);
	return (1);
}
