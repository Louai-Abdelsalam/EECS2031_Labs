#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record
{
	char first[50];
	char middle[50]; //optional
	char last[50];
	int midterm;
	int final;
	struct record * next;
};

int hashLocationCalc(char * first, char * middle, char * last)
{
		char c = ' ';
		int x = 0;
		int count = 0;
		while (count < strlen(first))
		{
			x += (int)first[count];
			count++;
		}
		count = 0;
		x += (int)c;
		while (count < strlen(middle))
		{
			x += (int)middle[count];
			count++;
		}
		count = 0;
		if (strlen(middle) != 0)
		{
			x += (int)c;
		}
		while (count < strlen(last))
		{
			x += (int)last[count];
			count++;
		}
		return x;
}

void main()
{
	int k, x, count, state; // x is assistant integer
	char c;
	FILE * fp;
	fp = fopen("records.txt", "r");
	struct record reader;
	struct record * current;
	struct record * memory;
	scanf("%d", &k);
	
//implementation of hashing
	//initializing hash table
	memory = malloc((sizeof(struct record)) * k);// malloc((sizeof(struct record)) * k);
	count = 0;
	while (count < k)
	{
		memory[count].first[0] = '\0';
		memory[count].middle[0] = '\0';
		memory[count].last[0] = '\0';
		memory[count].midterm = -1;
		memory[count].final = -1;
		
		//memory[count].next = malloc(sizeof(struct record));
		memory[count].next = NULL;
		//(memory[count].next)->first[0] = '\0';
		count++;
	}
	
	//processing records into the hash table
	while (fscanf(fp, "%s %s", reader.first, reader.middle) != EOF)
	{
		//Taking in records from records.txt	
		if (fscanf(fp, "%d", &reader.midterm) == 0)
		{
			fscanf(fp, "%s", reader.last);
			fscanf(fp, "%d %d", &reader.midterm, &reader.final);
		}
		else
		{
			strcpy(reader.last, reader.middle);
			reader.middle[0] = '\0';
			fscanf(fp, "%d", &reader.final);
		}
		
//printf("first=\"%s\", middle=\"%s\", last=\"%s\"\n", reader.first, reader.middle, reader.last);		
		//calculating location in hash table
		x = hashLocationCalc(reader.first, reader.middle, reader.last);
	
		//Storing in the hash table		
		if (memory[x % k].first[0] == '\0')
		{
//printf("Filling new block. (x%k)=%d.\n", (x % k));
			strcpy(memory[x % k].first, reader.first);
			strcpy(memory[x % k].middle, reader.middle);
			strcpy(memory[x % k].last, reader.last);
			memory[x % k].midterm = reader.midterm;
			memory[x % k].final = reader.final;
			memory[x % k].next = malloc(sizeof(struct record));
			(memory[x % k].next)->first[0] = '\0';
			//memory[x % k].next = NULL;
//printf("midterm = %d and final = %d.\n", memory[x % k].midterm, memory[x % k].final);
//printf("Mfirst=\"%s\", Mmiddle=\"%s\", Mlast=\"%s\"\n", memory[x % k].first, memory[x % k].middle, memory[x % k].last);
		}
		else
		{
			count = 0;
			current = &memory[x % k];
			//current = current->next;
//printf("Branching out once. (x%k)=%d.\n", (x % k));			
			while (/*current != NULL*/current->first[0] != '\0')
			{
//printf("Current->FirstName=\"%s\", Current->LastName=\"%s\".\n", current->first, current->last);

				current = current->next;
				count++;
//printf("Branching out more than once.\n");
			}
			//current = malloc(sizeof(struct record));
			strcpy(current->first, reader.first);
			strcpy(current->middle, reader.middle);
			strcpy(current->last, reader.last);
			current->midterm = reader.midterm;
			current->final = reader.final;
			
			current->next = malloc(sizeof(struct record));
			//current->next = NULL;
			(current->next)->first[0] = '\0';
//printf("branching out level %d.\n", count);
//printf("midterm = %d and final = %d.\nThis is branched out.\n", current->midterm, current->final);
//printf("reader.first=%s, reader.last=%s.\n", reader.first, reader.last);
//printf("current->first=%s, current->last=%s.\n\n", current->first, current->last);
//printf("Cfirst=\"%s\", Cmiddle=\"%s\", Clast=\"%s\"\n", current->first, current->middle, current->last);
		}			
	}
//printf("\nFilling hash table successfull.\n")	;
/* 
//Printing out hash table
	count = 0;
	while(count < k)
	{
		if (memory[count].first[0] == '\0')
		{
			printf("Location %d is an empty block.\n", count);
		}
		else
		{
//printf("\nELSE. FirstName=\"%s\", LastName=\"%s\", Final=%d\n\n", memory[count].first, memory[count].last, memory[count].final);		
			current = &memory[count];
			printf("Location %d is %s", count, current->first);
			if (strlen(current->middle) != 0)
			{
				printf(" %s", current->middle);
			}
			printf(" %s (%d).", current->last, current->final);
			
			current = memory[count].next;
			while (current->first[0] != '\0')
			{
				printf("%s", current->first);
				if (strlen(current->middle) != 0)
				{
					printf(" %s", current->middle);
				}
				printf(" %s (%d).", current->last, current->final);
				current = current->next;
			}
			printf("\n");
		}
		count++;
	}		
//*/	
//Taking input from user for look-up in the hash table
	count = -1;
	while((c = getchar()) != EOF/*(x = scanf("%s %s", reader.first, reader.last)) != EOF*/)
	{
		//ungetc(c, stdin);
		if (count != -1) //making sure it doesn't ungetc the first time
		{
			ungetc(c, stdin);
		}//*/
//printf("%c 1", c);
		count = 0;
		state = 0;
		while ((c = getchar()) != '\n')
		{
//printf("%c", c);
			if (c == ' ')
			{
				if (state == 0)
				{
					reader.first[count] = '\0';
				}
				else if (state == 1)
				{
					reader.middle[count] = '\0';
				}
				else if (state == 2)
				{
					reader.last[count] = '\0';
				}
				state++;
				count = -1;
			}
			else
			{
				if (state == 0)
				{
					reader.first[count] = c;
				}
				else if (state == 1)
				{
					reader.middle[count] = c;
				}
				else if (state == 2)
				{
					reader.last[count] = c;
				}
			}
			count++;
		}
		
		if (c == '\n')
		{
			if (state == 1)
			{
				reader.middle[count] = '\0';
			}
			else if (state == 2)
			{
				reader.last[count] = '\0';
			}
		}
		if (state == 1)
		{
			strcpy(reader.last, reader.middle);
			reader.middle[0] = '\0';
		}
		
//printf("reader.first=\"%s\", reader.middle=\"%s\", reader.last=\"%s\",", reader.first, reader.middle, reader.last);		
		
		//calculating position in hash table
		x = hashLocationCalc(reader.first, reader.middle, reader.last);

//printf("x=%d.\n");		
		//finding how many branching out steps and printing output		
		count = 0;
		state = 0;
		current = &memory[x % k];
		if (strcmp(current->first, reader.first) == 0)
		{
			count++;
			printf("%d %d %d\n", current->midterm, current->final, count);
		}
		else
		{
			count = 1;
			while (/*current != NULL*/current->first[0] != '\0')
			{
				if (strcmp(current->first, reader.first) == 0)
				{
					state = 1;
					printf("%d %d %d\n", current->midterm, current->final, count);
				}
				count++;
				current = current->next;
			}
			
			if (state == 0)
			{
				printf("The name does not exist in the file\n");
			}
		}
		count = 0;
//printf("current->first=\"%s\", reader.first=\"%s\".\n", current->first, reader.first);
	}
}