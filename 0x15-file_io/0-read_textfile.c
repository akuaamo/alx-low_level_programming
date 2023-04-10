#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and writes its contents to standard output
 * @filename: the name of the file to read
 * @letters: the maximum number of bytes to read from the file
 *
 * Return: the actual number of bytes read, or -1 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, ret;
	ssize_t nread;
	char *buf;

	if (filename == NULL)
		return (ssize_t)-1;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ssize_t)-1;

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		goto error;

	nread = read(fd, buf, letters);
	if (nread == -1)
		goto error;

	ret = write(STDOUT_FILENO, buf, nread);
	if (ret == -1 || (size_t)ret != nread)
		goto error;

	free(buf);
	close(fd);
	return nread;

error:
	free(buf);
	close(fd);
	return (ssize_t)-1;
}

