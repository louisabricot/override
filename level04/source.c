int		main(void)
{
	int	status; // 0x1c
	char buffer[128]; // 0x20
	int a; // 0xa8
	// 12 bytes
	int ret; // 0xac

	ret = fork();
	bzero(buffer, 128);
	a = 0;
	b = 0;
	if (ret == 0)
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP); // trapped bitch
		ptrace(PTRACE_ME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buffer);
		return (0);
	}
	else
	{
		while (wait(&status))
		{
			if (!WIFSTOPPED(status))
			{
				if (((WIFSTOPPED(status) + 1) >> 1)[0] > 0)// weird shit
				{
					puts("child is exiting...");
					return (0);
				}
				if (ptrace(PTRACE_PEEKUSER, ret, 44, 0) == 11) // jmp 160 if not
				{
					puts("no exec() for you");
					kill(ret, 9);
				}
			}
		}
	}
	return (0);
}
