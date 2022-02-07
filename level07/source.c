void            clear_stdin(void)
{
    char c; // epb - 0x9

    while (c != 0xff)
    {
        c = getchar();
        if (c == '\n')
            return ;
    }
}

unsigned int                get_unum(void)
{
    unsigned int    u; // ebp - 0xc

    u = 0;
    fflush(stdout);
    scanf("%u", &u);
    clear_stdin();
    return (u);
}

int            read_number(int array[])
{
    unsigned int    u; // ebp - 0xc

    u = 0;
    printf(" Index: ");
    u = get_unum();
    printf(" Number at data[%u] is %u\n", u, *(int *)((void *)array + (unsigned long)(u << 2)));
    return (0);
}

int store_number(char *s)
{
	printf(" Number: ");
	unsigned int n = get_unum(); //0x10
	printf(" Index: ");
	unsigned int i = get_unum(); //0xc
	if ((i - (((i * 0xaaaaaaab) >> 1) * 3)) == 0 || (n >> 24) == 0xb7) // i % 114 == 0
	{
/*
python
>>> 0b01000000000000000000000001110010
1073741938
--> 4159090384 (system) print system
116 (116 << 2 = 464 = 0x1d0 (sub esp, 0x1d0))
--> 4160264172 (/bin/sh) find {addresse de system}, +999999999, "/bin/sh"
*/
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	s[i << 2] = n;
	return (0);
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	char buffer[100]; //0x24
	int v = 0; //0x1b4
	char buffer2[20];//0x1b8
	//On n'a pas marque qu'il y avait genre 6 variables a genre 0

	bzero(buffer, 100); //+114 +128

	while (av[i] != NULL) //0x1c
	{
		// jmp + 132
		memset(av[i], 0, strlen(av[i]); //+114 +189
		i++;
	}
	i = 0;
	while (env[i] != NULL) //0x1c
	{
		// jmp + 132
		memset(env[i], 0, strlen(env[i]); //+114 +189
		i++;
	}
	puts("----------------------------------------------------\n
	Welcome to wil's crappy number storage service!\n
	----------------------------------------------------\n");
	while (v == 0 )
	{
		printf("Input command: ");
		v = 1; //0x1b4
		fgets(buffer2, 20, stdin);
		buffer2[strlen(buffer2) - 1] = '\0';
		if (strncmp("store", buffer2, 5) == 0) //448
		{
			v = store_number(buffer);
			//jmp a 578
			
		} else if (strncmp("read", buffer2, 4) == 0) //513
		{
			v = read_number(buffer);
			//jmp a 578

		} else if (strncmp("quit", buffer2, 4) == 0) //511
		{
			return (0);
		}
		if (v == 0)
		{
			printf(" Completed %s command successfully\n", buffer2);
			buffer2[0] = 0;
			buffer2[1] = 0;
			buffer2[2] = 0;
			buffer2[3] = 0;
			buffer2[4] = 0;
			//revient vers printf input command
		}
	}
	return 0;
}
