#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxNameSize = 50;

struct node
{
	char * name;
	struct node * next;
};

struct node * instantiateHashMap(struct node * hashMap)
{
	int count = 0;
	const int maxHashMapSize = 256;

	hashMap = malloc((sizeof(struct node)) * maxHashMapSize);
	while (count < maxHashMapSize)
	{
		(hashMap + count)->name = malloc((sizeof(char)) * maxNameSize);
		*((hashMap + count)->name) = '\0';
		(hashMap + count)->next = NULL;
		count++;
	}
	return hashMap;
}

void main()
{
	FILE * fp;
	fp = fopen("input.txt", "r");
	int count = 0, count1 = 0, collisionCount = 0, unusedCount;
	int k = 0, intValue = 0;
	char * name = malloc((sizeof(char)) * maxNameSize);
	struct node * hashMap;
	struct node * current;

	hashMap = instantiateHashMap(hashMap);
	scanf("%d", &k);
	unusedCount = k;
	while ((count < k) && ((fgets(name, maxNameSize, fp)) != NULL))
	{
		count1 = 0;
		while (*(name + count1) != '\0')
		{

			if (*(name + count1) == '\n')
			{

				*(name + (count1 - 1)) = '\0';
				count1 = maxNameSize;
			}
			count1++;
		}
		
		count1 = 0;
		intValue = 0;
		while (*(name + count1) != '\0')
		{
			intValue += (int)(*(name + count1));

			count1++;
		}
		count1 = 0;
		intValue %= k;
		if (*((hashMap + intValue)->name) == '\0')
		{
			strcpy(((hashMap + intValue)->name), name);
			unusedCount--;
		}
		else
		{
			current = (hashMap + intValue);
			if (current->next == NULL)
			{
				collisionCount++;
			}
			while(current->next != NULL)
			{
				current = current->next;
			}
				current = current->next;
				current = malloc((sizeof(struct node)));
				current->name = malloc(sizeof(char) * maxNameSize);
				strcpy((current->name), name);
				current->next = NULL;

		}
		count++;
	}

	printf("The number of entries with collision is %d\n", collisionCount);
	printf("The number of unused entries is %d\n", unusedCount);
}
