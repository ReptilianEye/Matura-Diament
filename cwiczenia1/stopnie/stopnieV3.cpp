#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip> // pozwalający na ustawienie precyzji

using namespace std;

int main()
{
    int F;
    cin >> F;
    double C = (F - 32.0) * 5.0 / 9.0;
    cout << fixed << setprecision(2);
    cout << C << endl;
}
