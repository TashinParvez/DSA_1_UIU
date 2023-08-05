//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int main()
{
    string s;
    getline(cin, s); // take line

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            cout << s[i];
        else
            cout << '_';
    }
    cout << '_';
    cout << '_';

    cout << nl;

    CRACKED;
}
