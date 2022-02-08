//          rbp -             v 0x118     v 0x120     v 0x128
void		log_wrapper(FILE *fs, char *str, char *filename)
{
	char buffer[255]; // 0x110

	strcpy(buffer, str);
	strlen() strlen(buffer);
	snprintf(buffer + strlen(buffer), 254 - strlen(buffer), filename);
	strcspn(buffer, "\n");
	fprintf(fs, "LOG: %s\n", buffer);
}

//          rbp -    v 0x94      v 0xa0
int			main(int ac, char **av)
{
	FILE *log_fs; // rbp - 0x88
	FILE *file_fs; // rbp - 0x80
	int fd = -1; // rbp - 0x78
	char c = -1; // rbp - 0x71
	char filename[100]; // rpb - 0x70

	if (ac != 2)
		printf("Usage: %s filename\n", av[0]);
	log_fs = fopen("./backups/.log", "w");
	if (log_fs == NULL)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log_fs, "Starting back up: ", av[1]);
	file_fs = fopen(av[1], "r");
	if (file_fs == NULL)
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}
	filename = "./backups/";
	strncat(filename, av[1], 99 - strlen(filename));
	fd = open(filename, O_WRONLY|O_CREAT|O_EXCL, 0660);
	if (fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}
	do
	{
		write(fd, &c, 1);
		c = fgetc(file_fs);
	}
	while (c != -1)
	log_wrapper(log_fs, "Finished back up ", av[1]);
	fclose(file_fs);
	close(fd);
	return (0);
}
