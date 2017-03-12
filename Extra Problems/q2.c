#include <stdio.h>

void main()
{
	int w, wCount = 0, h, hCount = 0, space;
	char c;
	scanf("%d %d %c", &w, &h, &c);
	
	while (hCount < h)
	{
		wCount=0;
		while (wCount < w)
		{
			if (hCount != 0 && hCount != (h - 1))
			{
				if (wCount == 0 || wCount == (w - 1))
				{
					printf("%c", c);
				}
				else
				{
					printf(" ");
				}
			}
			else
			{
				printf("%c", c);
			}
			wCount++;
		}
		printf("\n");
		hCount++;
	}
}