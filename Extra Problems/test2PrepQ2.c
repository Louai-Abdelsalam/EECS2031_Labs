#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <cstring>

void main()
{
	const int maxDNA = 250;
	int count = 0, count1 = 0, patternCount = 0;
	char * dna = malloc(sizeof(char) * maxDNA);
	char c;
	
	while ((c = getchar()) != '\n' && (count < maxDNA))
	{
		if (c == 'A' || c == 'C' || c == 'G' || c == 'T')
		{
			*(dna + count) = c;
			
			if (c == 'A' && count1 == 0)
			{
				count1++;
			}
			else if (c == 'C' && count1 == 1)
			{
				count1++;
			}
			else if (c == 'G' && count1 == 2)
			{
				count1++;
			}
			else if (c == 'T' && count1 == 3)
			{
				count1++;
			}
			else
			{
				count1 = 0;
			}
			
			if (count1 == 4)
			{
				patternCount++;
				count1 = 0;
			}
		}
		else
		{
			count = maxDNA;
			patternCount = 0;
			printf("Invalid Sequence\n");
		}
		
		count++;
	}

	if (patternCount != 0)
	{	
		printf("Valid Sequence\n%d\n", patternCount);
	}
}


