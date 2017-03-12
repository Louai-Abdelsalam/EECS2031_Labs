#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calcGrade(int * examMark, int * midMark,
	float * quiz1, float * quiz2, float * quiz3, int count)
	{
		float grade = ((*(examMark + count) * 0.6) + (*(midMark + count) * 0.25) +
			(*(quiz1 + count) * (10 * 0.05)) + (*(quiz2 + count) * (10 * 0.05)) +
				(*(quiz3 + count) * (10 * 0.05)));
// quizes * 10 first to equate to 100% since they are out of 10, not 100.
		return grade;
	}

void main()
{
	int n;

	scanf("%d", &n);

	int * studentID = malloc((sizeof(int)) * n);
	int * midMark = malloc((sizeof(int)) * n);
	int * examMark = malloc((sizeof(int)) * n);
	float * quiz1 = malloc((sizeof(float)) * n);
	float * quiz2 = malloc((sizeof(float)) * n);
	float * quiz3 = malloc((sizeof(float)) * n);
	char * command = malloc(sizeof(char) * 7);
	int count = 0, count1 = 0, boolean = 0;
	float grade = 0;
	char c;
	char ** firstName;
	char ** lastName;
//allocating memory for firstName then lastName
	firstName = malloc(sizeof(char *) * n);
	lastName= malloc(sizeof(char *) * n);
	while (count < n)
	{
		*(firstName + count) = malloc(sizeof(char) * 8);
		*(lastName + count) = malloc(sizeof(char) * 8);

		count++;
	}

	count = 0;

//taking inputs loop
	while (count < n)
	{
//take studentID
		scanf("%d", (studentID + count));
//take firstName
		scanf("%s ", *(firstName + count));
//take lastName
		scanf("%s ", *(lastName + count));
//take examMark then midMark
		scanf("%d %d", (examMark + count), (midMark + count));
//take quiz1 then quiz2 then quiz3
		scanf("%f %f %f", (quiz1 + count), (quiz2 + count), (quiz3 + count));
		count++;
	}

	// taking commands loop
	while (boolean != 1 && scanf("%s", command) != EOF)
	{
		count = 0;
		grade = 0;

	// implementation of q or Q
		if (strcmp(command, "q") == 0 || strcmp(command, "Q") == 0)
		{
			printf("Thanks\n");
			boolean = 1;
		}
	// implementation of F command
		else if(strcmp(command, "F") == 0)
		{
			while (count < n)
			{
				grade = calcGrade(examMark, midMark, quiz1, quiz2, quiz3, count);

				if (grade < 50)
				{
					printf("%08d\n", *(studentID + count));
				}

				count++;
			}
		}
	// implementation of top command
		else if (strcmp(command, "top") == 0)
		{
			float maxGrade;
			int * index = malloc(sizeof(int) * n);
			*index = -1; // saving indices of students with top grades

			while (count < n)
			{
				grade = calcGrade(examMark, midMark, quiz1, quiz2, quiz3, count);

				if (count == 0)
				{
					maxGrade = grade;
					*index = 0;
					*(index + 1) = -1;
				}
				else
				{
					if (grade > maxGrade)
					{
						maxGrade = grade;
						*index = count;
						*(index + 1) = -1;
					}
					else if (grade == maxGrade)
					{
						count1 = 0;
						while (*(index + count1) != -1)
						{
							count1++;
						}
						*(index + count1) = count;
						*(index + (count1 + 1)) = -1;
						count1 = 0;
					}
				}

				count++;
			}

			count1 = 0;
			while (*(index + count1) != -1)
			{
				printf("%08d  %s\n", *(studentID + *(index + count1)),
					*(lastName + *(index + count1)));

					count1++;
			}
			count1 = 0;
		}
	// implementation of A command
		else if (strcmp(command, "A") == 0)
		{
			while (count < n)
			{
				grade = calcGrade(examMark, midMark, quiz1, quiz2, quiz3, count);

				if (grade >= 80)
				{
					printf("%08d  %s\n", *(studentID + count), *(lastName + count));
				}

				count++;
			}
		}
	// implementation of PerA command
		else if (strcmp(command, "PerA") == 0)
		{
			count1 = 0;
			while (count < n)
			{
				grade = calcGrade(examMark, midMark, quiz1, quiz2, quiz3, count);

				if (grade >= 80)
				{
					count1++;
				}

				count++;
			}

			printf("Percentage of students with an average of A:%.2lf%\n",
			 	(((float)count1 / (float)n) * 100.00));
			count1 = 0;
		}
	// implementation of Anomaly
		else if (strcmp(command, "Anomaly") == 0)
		{
			int countA = 0, countF = 0;

			if (n > 15)
			{
				while (count < n)
				{
					grade = calcGrade(examMark, midMark, quiz1, quiz2, quiz3, count);

					if (grade >= 80)
					{
						countA++;
					}
					if (grade < 50)
					{
						countF++;
					}

					count++;
				}

				if ((((countA / n) * 100) > 30.00) || (((countF / n) * 100) > 30.00))
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}

/*
00000000   AAA  BBB            70  60  9 1 7
12345678   Mokhtar   Aboelaze   100 80 10 9 8
23456789   Mohamed   Aboelaze   95  77 8 8 8
45678901   John Doe 56 23 3 6 9
56789012   Jane Doe 86 23 5 8 9
98765432  XXX  yyy  56 23 4 8 6
3456789   Mxhamed   Axoelaze   100  80 10 8 9
*/
