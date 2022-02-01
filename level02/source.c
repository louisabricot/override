int main(void)
{
	char	password[100]; //0x110 
	// 12 bytes
	char	flag[41]; //0xa0
	//a 7-byte padding for optmization
	char	username[100]; //0x70
	size_t	n;//0xc
	FILE	*fd; //0x8

	bzero(username, 100);
	bzero(flag, 41);
	bzero(password, 100);
	n = 0;
	fd = 0;

	fd = fopen("/home/users/level03/.pass", "r");
	if (fd == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	n = fread(flag, 1, 41, fd);
	flag[strcspn(flag, "\n")] = '\0';
	if (n != 41) //je +361
	{
		 fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		 fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		 exit(1);
	}
	fclose(fd);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\***************************************/");
	printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(password, 100, stdin);
	password[strcspn(password, "\n")] = '\0';	
	puts("\\***************************************/");
	if (strncmp(flag, password, 41) == 0) 
	{
		printf("Greetings, %s!\n", username);
		system("/bin/sh");
		return 0;
	}
	printf(username);
	puts("does not have access!");
	exit(1);

}
