#include <stdio.h>
#include <string.h>

int		main(void)
{
	char str[17] = "Q}|u`sfg~sf{}|a3";
	char res[17];

	bzero(res, 17);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 16; j++)
			res[j] = str[j] ^ i;
		if (!strcmp(res, "Congratulations!"))
			printf("%d: %s\n", i, res);
	}
}
