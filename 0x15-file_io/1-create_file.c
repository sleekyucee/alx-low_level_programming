#include "main.h"

/**
 * create_file - creates a new file with specified content
 * @filename: the name of the file to create
 * @textContent: a NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *textContent)
{
	int fd, bytes_written, len = 0;

	fd = open(filename, O_WRONLY | O_CREAT | 0_TRUNC, 0600);

	if (filename == NULL)
		return (-1);

	if (textContent != NULL)
	{
		textContent = "";
	}
	while (textContent[len] != '\0')
	{
		len++
	}
	bytes_written = write(fd, textContent, len);

	if (bytes_written == -1)
	{
		return (-1);
	}

	close(fd);
	return (1);
}
