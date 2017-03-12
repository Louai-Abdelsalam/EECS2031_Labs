#include <stdio.h>
#include <string.h>

void main()
{
	int count1 = 0, count2 = 0, count = 0, gCount = 0, x, y, c = 0;
	char arithmetic, num1[32], num2[32], ans[32];
	scanf("%s %c %s", num1, &arithmetic, num2);

//determining size of both num1 and num2
	while (num1[count1] != '\0' || num2[count2] != '\0')
	{
		if (num1[count1] != '\0')
		{
			count1++;
		}

		if (num2[count2] != '\0')
		{
			count2++;
		}
	}

	count1--;
	count2--;

	if (count1 >= count2)
	{
		count = count1;
	}
	else
	{
		count = count2;
	}

	count++;

//implementing 2's compliments of num2
	if (arithmetic == '-')
	{
		int localCount = 0;
		int z;
//adjusting size of num2 so that it's the same size as num1 for inversion
		if ((count1 - count2) > 0)
		{
			strcpy(ans, num2);
			while (localCount < (count1 - count2))
			{
				num2[localCount] = '0';
				localCount++;
			}
			num2[localCount] = '\0';
			strcat(num2, ans);
			count2 = count1;
			localCount = 0;
		}
//inverting num2 bits
		while (num2[localCount] != '\0')
		{
			if (num2[localCount] == '1')
			{
				num2[localCount] = '0';
			}
			else
			{
				num2[localCount] = '1';
			}
			localCount++;
		}

		localCount--;
		c = 1;
//adding 1 to inverted num2 and its followup arithmetics
		while (c == 1)
		{
			z = ((num2[localCount] - '0') + c);

			if (z == 2)
			{
				num2[localCount] = '0';
				c = 1;
			}
			else if (z == 3)
			{
				num2[localCount] = '1';
				c = 1;
			}
			else
			{
				num2[localCount] = z + '0';
				c = 0;
			}
			localCount--;
		}
	}

//addition loop between num1 and num2
	c = 0;
	while (gCount < count)
	{
		if (count1 >= 0)
		{
			x = num1[count1] - '0';
		}
		else
		{
			x = 0;
		}

		if (count2 >= 0)
		{
			y = num2[count2] - '0';
		}
		else
		{
			y = 0;
		}

		c += x + y;

		if (c < 2)
		{
			ans[gCount] = c + '0';
			c = 0;
		}
		else if (c == 2)
		{
			ans[gCount] = 0 + '0';
			c = 1;
		}
		else
		{
			ans[gCount] = 1 + '0';
			c = 1;
		}

		count1--;
		count2--;
		gCount++;

	}

	ans[gCount] = '\0';
	gCount--;

//printing answer
	while (gCount >= 0)
	{
		printf("%c", ans[gCount]);
		gCount--;
	}

	printf("\n");
}
