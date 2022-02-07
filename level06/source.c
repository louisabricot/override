int auth(char *login, int serial) {
	int a; //0x14
	int b; //0x10
	//int len; 0xc
	size_t n = strcspn(login, '\n');

	login[n] = '\0';
	int len = strnlen(login, 32); //0xc
	if (len > 5)
	{
		if (ptrace(PTRACE_ME, 0, 1, 0) == -1)
		{
			puts("\033[32m.---------------------------.");
			puts("\033[31m| !! TAMPERING DETECTED !!  |");
			puts("\033[32m.---------------------------.");
			return (1);
		}
		b = &login[3] ^ 0x1337 + 0x5eeded;
		a = 0;
		while (a < len) //+278 +281
		{
			if (login[a] < ' ')
				return 1;
			int x = &(&login[a])[3] ^ b;
			x -= ((((x * 0x88233b2b - 0x88233b2b) >> 1) + 0x88233b2b) >> 0xa) * 0x539;
			b += x;	
			//multiplie ea * 0x539
			//(&(&login[a])[3] ^ b) * 0x539
			a++;
		}
		if (b == serial)	//+286 +289
			return (0);
	}
	return (1);
}

int main(void)
{
	int		serial; //esp + 0x28
	char	login[32]; //esp + 0x2c
	//truc avec gs voir plus tard
	puts("************************************");
	puts("*\t\tlevel06\t\t  *`");
	puts("************************************");
	printf("-> Enter Login: ");
	fgets(login,32, stdin);
	puts("************************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("************************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (auth(login, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
