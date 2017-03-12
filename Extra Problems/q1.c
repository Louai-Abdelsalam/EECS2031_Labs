#include <stdio.h>

void main()
{
	int n, x, space, count;
	scanf("%d", &n);
	
	if ((n%2) == 0)
	{
		x = 2;
	}
	else
	{
		x = 1;
	}
//WHAT IF N = 1 OR 2???	
	while (x <= n)
	{
		space = (n-x)/2;
		count = 0;
		
		while (count < space)
		{
			printf(" ");
			count++;
		}
		
		count = 0;
		
		while (count < x)
		{
			printf("*");
			count++;
		}
		
		count = 0;
		
		printf("\n");
		x += 2;
	}
}


