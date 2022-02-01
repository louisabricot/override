void decrypt(int n)
	int i; // ebp -0x28
	int len; // ebp - 0x24
	char key[16] = "Q}|u`sfg~sf{}|a3"; // ebp - 0x1d -> ebp - 0x11

	len = strlen(key);
	for (i = 0; i < len; i++)
		key[i] ^= n;
	if (!strncmp(key, "Congratulations!", 17))
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}

void test(int d, int f)
{
	f -= d;
	if ((unsigned int)f <= 21)
	{
		void (*p)(void) = f;
		p = (unsigned int)*(p << 2) + 0x80489f0; //jump a cette addresse
		p();
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
		decrypt(f);
		return ;
	}
	decrypt(rand());
	return ;
	//+259

}
int main(void)
{
	int d; // 0x1c

	srand(time(0));
	puts("************************************");
	puts("*\t\tlevel03\t\t**");
	puts("************************************");
	printf("Password:");
	scanf("%d", d);
	test(d, 0x1337d00d);
	return 0;
}
