#include <stdio.h>

void main()
{
	int count = 0, n = 10, x, max, index;
	
	while (count < n)
	{
		scanf("%d", &x);
		if (count != 0)
		{
			if (x > max)
			{
				max = x;
				index = count;
			}
		}
		else
		{
			max = x;
			index = count;
		}
		count++;
	}
	index++;
	printf("%d:%d\n", index, max);
}