#include <stdio.h>
#include <string.h>

struct Book
{
	char title[61], author[51], publisher[51];
	float price;
};

void main()
{
	FILE *fp;
	fp = (fopen("book.dat", "rb"));
	int recCount = 0, boolean = 0, count = 0, helpercount = 0;
	char t[61], a[51], p[51];
	char c;
	float pr;
	struct Book library[40];

	while ((fp != NULL) && (fscanf(fp, "%s %s %s %f", t, a, p, &pr) == 4) && (recCount < 40))
	{
		strcpy(library[recCount].title, t);
		strcpy(library[recCount].author, a);
		strcpy(library[recCount].publisher, p);
		library[recCount].price = pr;
		recCount++;
	}

	fp = (fopen("book.dat", "wb"));
	printf("book.dat contains %02d records\n", recCount);
	printf("%02d is the number of records and is less than or equal 40\n", recCount);
	if (recCount == 40)
	{
		printf("The file is full\n");
	}

	while ((recCount < 40) && (boolean == 0))
	{
		printf("Enter the name of the book\n");
		printf("To stop entering, press enter at the beginning of a line\n");
		if ((c = getchar()) == '\n')
		{
			boolean = 1;
		}
		else
		{
			library[recCount].title[0] = c;
			library[recCount].title[1] = '\0';
			scanf("%s", t);
			strcat(library[recCount].title, t);
			printf("Enter the author\n");
			scanf("%s", library[recCount].author);
			printf("Enter the publisher\n");
			scanf("%s", library[recCount].publisher);
			printf("Enter the price\n");
			scanf("%f", &library[recCount].price);
			recCount++;
			getchar();
		}
	}

	while (helpercount < recCount)
	{
		fprintf(fp, "%s %s %s %lf\n", library[helpercount].title, library[helpercount].author,
			library[helpercount].publisher, library[helpercount].price);

		helpercount++;
	}


	printf("Enter Q to end, or T or A to search for title and author\n");
	scanf("%c", &c);
	while (c != 'Q')
	{
		boolean = 0;
		count = 0;
		if (c == 'T')
		{
			printf("Enter the book title\n");
			scanf("%s", t);
			while (count < recCount)
			{
				if (strcmp(library[count].title, t) == 0)
				{
					printf("Title: %s\n", library[count].title);
					printf("Author: %s\n", library[count].author);
					printf("Price: %lf\n", library[count].price);
					boolean = 1;
				}
				count++;
			}
		}
		else if (c == 'A')
		{
			printf("Enter the book author\n");
			scanf("%s", a);
			while (count < recCount)
			{
				if (strcmp(library[count].author, a) == 0)
				{
					printf("Title: %s\n", library[count].title);
					printf("Author: %s\n", library[count].author);
					printf("Price: %lf\n", library[count].price);
					boolean = 1;
				}
				count++;
			}
		}

		if (boolean == 0)
		{
			printf("No such book\n");
		}
		scanf(" %c", &c);
	}
}
