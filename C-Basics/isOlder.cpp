/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int k = 0, l = 0, a, b, s = 0, t, j, p, m, n,f,e=0,d=0, z, h = 0,o=0;
	int x[6];
	while (dob1[k] != '\0')
		k++;
	while (dob2[l] != '\0')
		l++;
	if (k == 10 && l == 10)
	{
		a = k - 1; b = l - 1; z = k;
		while (a != -1)
		{
			p = 0;
			s = 0;
			if (dob1[a] == '-' || a == 0)
			{
				n = a;
				
				if (a != 0) n++; if (a == 0) p--;
				f = dob1[n];
				if (48 <= f&&f <= 57)
				{
					while (n != z)
					{

						m = dob1[n] - 48;
						for (j = z - a - 2; j > p; j--)
						m = m * 10;
						p++;
						s = s + m;
						n++;
					}
					x[h] = s; h++;
					z = a;
				}
				else {
					d = 1;
					break;
				}
			}
			a--;
		}

		if (d == 0)
		{
			z = l; b = l - 1;
			while (b != -1)
			{
				p = 0;
				s = 0;
				if (dob2[b] == '-' || b == 0)
				{
					n = b;
					if (b != 0) n++; if (b == 0) p--;
					f = dob1[n];
					if ((65 <= f &&f <= 91) || (97 <= f&&f <= 123))
					{
						e = 1; break;
					}
					while (n != z)
					{
						m = dob2[n] - 48;
						for (j = z - b - 2; j > p; j--)
							m = m * 10;
						p++;
						s = s + m;
						n++;
					}
					x[h] = s; h++;
					z = b;
				}
				b--;
			}
			if (e == 0)
			{
				a = 0; b = 3;
				if (x[1] <= 12 && x[4] <= 12)
				{
					if ((x[1] == 2 && x[2] > 28 && x[0] % 4 != 0) || (x[1]==2&& x[2] > 29 && x[0] % 4 == 0)||(x[4] == 2 && x[5] > 28 && x[3] % 4 != 0) || (x[4]==2&&x[5] > 29 && x[3] % 4 == 0))
						return -1;
					else
					{
						while (a != 4 && b != 6)
						{
							if (x[a] == x[b])
							{
								a++; b++;
								if (a == 3)return 0;
							}
							else if ((x[a] - x[b]) > 0)
								return 2;
							else if ((x[a] - x[b]) < 0)
								return 1;
						}
					}
				}
				else return -1;
			
			}
		}
		if (d == 1 || e == 1)
			return -1;
	}

else
		return -1;

}