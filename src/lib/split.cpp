#include <iostream>
using namespace std;

int split(string str, char delimeter, string splits[])
{
    const int str_size = str.size();
    cout << "The size of the string is " << str_size << endl;

    int i = 0;
    int j = 0; // For the splits array
    string s;

    while (i < str_size)
    {
        if (str[i] == delimeter)
        {
            // cout << s << endl;
            splits[j] = s; // Put string s at the immediate next position of the splits array
            ++j;
            s = "";
        }
        else if (i == (str_size - 1)) // At the last character
        {
            s += str[i];
            // cout << s << endl;
            splits[j] = s; // Put string s at the immediate next position of the splits array
        }
        else
        {
            s += str[i];
        }
        i++;
    }

    return j + 1;
}