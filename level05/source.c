int main(void)
{
	char buffer[100] ; //0x28
	int i = 0; //0x8c +14 ou alors un pointeur et en fait c'est un double tableau[2] = NULL

	fgets(buffer, 100, stdin);
	//jump a +143
	while ( i < strlen(buffer)) //+143 - +186
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'Z') // +67-+81 +85-+99 hex 41 - 59
		{
			buffer[i] += 32; //to min
		}
		//jump to +135
		i++;
	}
	printf(buffer);
	exit(0);
}
