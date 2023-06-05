#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> keys = {"", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};

void keypad (string str, string asf)
{
    int i;
    if (str.size() == 0)
    {
        cout << asf << " ";
        return;
    }

    string num = str.substr(0, 1);
    int curr = stoi(num);

    for (i = 0; i < keys[curr].size(); ++i)
    {
        keypad (str.substr(1), asf + keys[curr][i]);
    }
}

int main()
{
    int n;
    cin >> n;
    string str = to_string (n);
    
    keypad (str, "");
    
    return 0;
}