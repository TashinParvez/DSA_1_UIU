#include <stdio.h>
#include <string.h>
int top = -1;
char Stack[4] = {'\0'};
void Push(char x)
{
    Stack[++top] = x;
    return;
}
char Pop(void)
{
    return Stack[top--];
}
int main()
{
    char Str1[4] = {'\0'};
    char Str2[4] = {'\0'};
    int i;
    strcpy(Str1, "CSE");
    for (i = 0; i < 3; ++i)
    {
        Push(Str1[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        Str2[i] = Pop();
    }
    printf("%s", Str2);
    return 0;
}
