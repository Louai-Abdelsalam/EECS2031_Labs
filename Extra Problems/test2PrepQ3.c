#include <stdio.h>

void main()
{
	int count1 = 0, count2 = 0, sum = 0, diagVal, val, n, bool = 1;
	
	scanf("%d", &n);
	while (count1 < n && bool == 1)
	{
		count2 = 0;
		sum = 0;
		while(count2 < n)
		{
			scanf("%d", &val);
			if (count1 == count2)
			{
				diagVal = val;
			}
			else
			{
				sum += val;
			}
			
			count2++;
		}
		
		if (diagVal < sum)
		{
			bool = 0;
		}
		
		count1++;
	}
	
	if (bool == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
/*
3x3

<6> 2   1
 3 <5>  2
 1  3  <10>


<[0][0]> [0][1]   [0][2]
 [1][0] <[1][1]>  [1][2]
 [2][0]  [2][1]  <[2][2]>
 */