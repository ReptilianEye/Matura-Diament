#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n_malpek;
    cin >> n_malpek;
    for (int i = 0; i < n_malpek+2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "#";
    for (int i = 0; i < n_malpek; i++)
    {
        cout << "@" << "";
    }
    cout << "#" << endl;
    for (int i = 0; i < n_malpek + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
}
