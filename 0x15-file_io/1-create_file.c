#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - creates a new file with specified content
 * @filename: the name of the file to create
 * @text_content: a NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | 0_TRUNC, 0600);
	bytes_written = write(fd, text_content, len);

	if (fd == -1 || bytes_written == -1)
	{
		return (-1);
	}
	close(fd);
	return (1);
}
