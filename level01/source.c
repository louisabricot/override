char a_user_name[256];

void verify_user_pass(char *password)
{
	return strncmp(password, "admin", 5);
}

void verify_user_name()
{
	puts("verifying username...\n");
	return strncmp(a_user_name, "dat_wil", 7); 
}

int main(void)
{
	char buffer[64];//0x1c
	int  n;//0x5c
	
	bzero(buffer, 64);
	n = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	if (verify_user_name() != 0)
	{
		puts("nope, incorrect username...\n");
		return 1;

	}
	puts("Enter password:");
	fgets(buffer, 100,stdin);
	if (verify_user_pass(buffer) != 0)
	{
		puts("nope, incorrect password...\n");
		return 1;
	}
	else 
	{
		puts("nope, incorrect password...\n");
		return 1;
	}
	return 0;
}
