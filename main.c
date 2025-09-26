#include <unistd.h>
#include <fcntl.h>

int file_get_char(int fd, char *c);
void put_char(char c);

int main(void)
{
	char c;
	int fd;
	
	fd = open("file.txt", O_RDONLY);
	while (file_get_char(fd, &c) > 0)
		put_char(c);
	close(fd);
	return (0);
}

void put_char(char c)
{
	write(1, &c, 1);
}

int file_get_char(int fd, char *c)
{
	return read(fd, c, 1);
}
