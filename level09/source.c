

void			secret_backdoor()
{
	char s[128]; //rbp - 0x80
	fgets(s, 128, stdin);
	system(s);
}

typedef struct	s_leet
{
	char		msg[140]; // 0x00
	char		username[40]; // 0x8c
	int			len;//  0xb4
}				leet;

// leet -> rbp - 0x408
void			set_msg(leet *leet)
{
	char buffer[1024]; //rbp - 0x400

	bzero(buffer, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buffer, 1024, stdin);
	strncpy(leet->msg, buffer, leet->len);
}
// leet -> rbp - 0x98
void			set_username(leet *leet)
{
	char buffer[128]; //rbp - 0x90
	int i; //rbp - 0x4

	bzero(buffer, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buffer, 128, stdin);
	i = 0;
	while(i <= 40 && buffer[i] != '\0')
	{
		leet->username[i] = buffer[i];
		i++;
	}
	printf(">: Welcome, %s", leet->username);
}

void			handle_msg()
{
	leet		leet;

	bzero(leet->username, 40);
	leet.len = 140;
	set_username(&leet);
	set_msg(&leet);
	puts(">: Msg sent!");
}

int				main(void)
{
	puts("-------------------------------------------- \
		\n|   ~Welcome to l33t-m$n ~    v1337        | \
		\n--------------------------------------------");

	handle_msg();
	return (0);
}
