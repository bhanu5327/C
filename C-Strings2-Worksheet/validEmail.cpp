/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	int i = 0, j, k, l = 0, c = 0,u;
	int m, n = 0, p = 0, h, z = 0, r, count = 0;
	if (email[6] == '_') return 0;
	while (email[i] != ' '&&email[i]!='\0')
	{
      i++;
	}
	if (email[i] == '\0')
	{
		return 0;
	}
	else
	{
		m = i; i++;
		while (email[i] == ' ')
		{
			i++;
		}
		z = i;
		k = email[i];
		if ((65 <= k&&k <= 90) || (k >= 97 && k <= 122))
		{
			i++;
			while (email[i] != '\0'&&i < 256)
			{
				k = email[i];
				if ((65 <= k&&k <= 90) || (97 <= k&& k <= 122) || k == 45 || k == 46 || k == 95 || (48 <= k&&k <= 57))
				{
					if (k == 46) break;
					n = 1;
				}
				else if (k == 64)
				{
					if (l == 0) r = i;
					l++;
					n = 0;
				}
				else
				{
					c = 1;
					break;
				}
				i++;
			}
		}
		else
		{
			p = -1;
		}
		if (p == -1 || l != 1 || n != 1 || email[i] == '\0' || c == 1 || i == 256)
		{
			return count;
		}
		else
		{
			count = 1; l = 0; u = 0;
			for (i = 0, j = z; i < m, j < r; i++, j++)
			{
				k = email[i];
				h = email[j];
				if ((k == h) ||(( k - h) == 32) ||(( h - k )== 32))
				{
					l++;
					if (l == m) break;
				}
				else
				{
					if (u == 0)
					{
						j = r - m - 1; i = -1; l = 0; u++;
					}
					else break;
				}
			}
			if (l == m) count++;
			return count;
		}
	}
}