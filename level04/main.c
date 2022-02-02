#include <stdio.h>
#include <sys/ptrace.h>
#include <unistd.h>

int		main(void)
{
	int ret = fork();

	if (ret == 0)
	{
		ptrace(PTRACE_ME, 0, 0, 0);
		execve("/bin/sh", "sh");
		return (0);
	}
	else
	{
		while (wait(&status))
		{
				if (ptrace(PTRACE_PEEKUSER, ret, 44, 0) == 11) // jmp 160 if not
				{
					puts("no exec() for you");
					kill(ret, 9);
				}
		}
	}
	return (0);
}
