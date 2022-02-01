int main(void)
{
	int n;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");

	printf("Password:");

	scanf("%d", n);

	if (n != 5276)
	{
		puts("\nInvalid Password!");
		return 1;
	}

	puts("Authenticated!");
	system("/bin/sh");
	return 0;

}
