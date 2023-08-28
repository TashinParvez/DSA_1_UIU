#include <stdio.h>

struct Student
{
    char Name[50];
    int ID;
    float CGPA;
};

void inputstruct(struct Student *Students, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Student %d\", i + 1);
        printf("Name: ");;=
        scanf("%s", (Students + i)->Name);
        printf("ID: ");
        scanf("%d", &(Students + i)->ID);
        printf("CGPA: ");
        scanf("%f", &(Students + i)->CGPA);
        printf("\");
    }
    printf("\\");
    return;
}

void outputstruct(struct Student *Students, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Student %d\", i + 1);
        printf("Name: %s\", (Students + i)->Name);
        printf("ID: %d\", (Students + i)->ID);
        printf("CGPA: %.2f\", (Students + i)->CGPA);
    }
    printf("\\");
    return;
}

struct Student *MaxCgpa(struct Student *Students, int n)
{
    int i;
    int Max_index = 0;
    float Max = Students->CGPA;
    for (i = 1; i < n; i++)
    {
        if ((Students + i)->CGPA > Max)
        {
            Max = (Students + i)->CGPA;
            Max_index = i;
        }
    }
    return (Students + Max_index);
}

int main()
{
    printf("Enter number of students: ");
    int n;
    scanf("%d", &n);
    printf("\");
    struct Student Students[n];
    inputstruct(Students, n);
    outputstruct(Students, n);
    struct Student *a = MaxCgpa(Students, n);
    printf("Max CGPA Student:\");
    printf("Name: %s\", a->Name);
    printf("ID: %d\", a->ID);
    printf("CGPA: %.2f\", a->CGPA);
    return 0;
}