#include <iostream>
#include <string>
#include <cmath>    
#include <map>

using namespace std;

const int symbol_count = 15;
char Z[symbol_count] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'}; 
map<char,int> Z_inv = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14}
};

string from_dec_to_system(int n, int p)
{
    string result = "";
    while (n > 0)
    {
        result = Z[n % p] + result;
        n /= p;
    }
    return result;
}
int idx_of(char c)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (Z[i] == c)
        {
            return i;
        }
    }
    return -1;
}
int from_system_to_dec(string input, int p)
{
    int result = 0;
    int current_pow = 0;
    for (int i = input.length() - 1; i >= 0; i--)
    {
        // result += idx_of(input[i]) * pow(p, current_pow);
        result += Z_inv[input[i]] * pow(p, current_pow);
        current_pow++;
    }
    return result;

}

// compile with g++ -std=c++11 convert.cpp -o convert
int main()
{
    int n, p;
    cin >> n >> p;
    string result = from_dec_to_system(n, p);
    cout << "Liczba " << n << " w systemie " << p << ": " << result << endl;
    cout << "Liczba " << result << " w systemie 10: " << from_system_to_dec(result, p) << endl;
}

