#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100] = "This journey is";
    char str2[100] = "beautiful";
    int j;

    strncpy(str1, str2, 8);
    // ekhane str 1 er 8 ta char er por

    printf("String 1:%s\n", str1);
    // printf("String 2:%s\n", str2);

    for (j = 3; str1[j] != '\0'; j++)
        str1[j] = str2[strlen(str1) - j];

    // printf("String 1:%s\n", str1);
    strncat(str2, str1, 3);
    printf("String  1:%s\n", str1);
    printf("String  2:%s\n", str2);

    str2[j - 2] = '\0';
    printf("String 2: %s\n", str2);

    for (j = 5; j > 2; j--)
    {
        strrev(str1);
    }
    printf("Final: %s", str1);

    return 0;
}