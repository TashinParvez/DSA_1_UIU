#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
    /* The code is using the `system()` function to execute a series of commands in the command prompt
    (Windows). */
    system("del /S *.exe && del /S *.o");
    // system("git add .");
    // system("git commit -m\"add some code\"");
    // system("git push");
    return 0;
}