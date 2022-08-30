#include <stdio.h>
struct student
{
	char firstName[50];
	int roll;
	float marks;
} s[3];
int main()
{
	int i;
	printf("Enter information of students: \n");
	for(i = 0; i < 3; ++i)
	{ 
		s[i].roll = i +1;
		printf("\nFor roll number%d,\n", s[i].roll);
		printf("Enter first name: ");
		scanf("%s", s[i].firstName);
		printf("Enter marks: ");
		scanf("%f", &s[i].marks);
	}
	printf("\nDisplaying Information:\n");
	for(i = 0; i < 3; ++i)
	{
		printf("\nRoll number: %d :-\n", i + 1);
		printf("First name: ");
		puts(s[i].firstName);
		printf("Marks: %.1f", s[i].marks);
		printf("\n");
	}
	return 0;
}