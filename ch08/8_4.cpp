#include <iostream>
#include <cstring>

using namespace std;

struct stringy{
    char * str;
    int ct;
};

void set(stringy &, char *);
void show(const stringy &, int n = 0);
void show(const char *, int n = 0);

int main(void)
{
    stringy beauy;
    char testing[] = "Reality isn't what it used to be.";

    set(beauy, testing);
    show(beauy);
    show(beauy, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy & beauy, char * str)
{
    int len = strlen(str);

    beauy.str = new char [len];
    strcpy(beauy.str, str);

    beauy.ct = len;
}

void show(const stringy & beauy, int n)
{
    if (n == 0)
    {
        cout << beauy.str << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            cout << beauy.str << endl;
        }
    }
}

void show(const char * str, int n)
{
    if (n == 0)
    {
        cout << str << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            cout << str << endl;
        }
    }
}

