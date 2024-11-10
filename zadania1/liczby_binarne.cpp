#include <iostream>
#include <vector>
#include <string>

using namespace std;

int rows = 1000;

int count_zeros(string bin)
{
    int count = 0;
    for (int i = 0; i < bin.length(); i++)
    {
        if (bin[i] == '0')
            count++;
    }
    return count;
}
void ex1()
{
    string bin;
    int count_more_ones = 0;
    for (int i = 0; i < rows; i++)
    {
        cin >> bin;
        if (count_zeros(bin) > bin.length() / 2)
            count_more_ones++;
    }
    cout << count_more_ones;
}
bool is_divisible_by_2(string bin)
{
    return bin[bin.length() - 1] == '0';
}
bool is_divisible_by_8(string bin)
{
    bool is_divisible = true;
    for (int i = 0; i < 3; i++)
    {
        if (bin[bin.length() - 1 - i] != '0')
        {
            is_divisible = false;
            break;
        }
    }
    return is_divisible;
}
void ex2()
{
    string bin;
    int divisible_by_2 = 0;
    int divisible_by_8 = 0;
    for (int i = 0; i < rows; i++)
    {
        cin >> bin;
        if (is_divisible_by_2(bin))
            divisible_by_2++;
        if (is_divisible_by_8(bin))
            divisible_by_8++;
    }
    cout << divisible_by_2 << " " << divisible_by_8;
}
int compare_bin(string bin1, string bin2)
{
    int length_diff = bin2.length() - bin1.length();
    if (length_diff != 0) return length_diff;

    for (int i = 0; i < bin1.length(); i++)
    {
        int diff = int(bin2[i]) - int(bin1[i]);
        if (diff != 0) return diff;
    }
    return 0;
}
void ex3()
{
    string bin;
    cin >> bin;
    string biggest_num = bin;
    string lowest_num = bin;
    int biggest_num_idx = 1;
    int lowest_num_idx = 1;

    for (int i = 2; i <= rows; i++)
    {
        cin >> bin;
        if (compare_bin(biggest_num, bin) >= 0)
        {
            biggest_num_idx = i;
            biggest_num = bin;
        }
        if (compare_bin(bin,lowest_num) >= 0)
        {
            lowest_num_idx = i;
            lowest_num = bin;
        }
    }
    cout << lowest_num_idx << " " << biggest_num_idx;
}
int main()
{
    int exercise;
    cin >> exercise;
    switch (exercise)
    {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    case 3:
        ex3();
        break;
    default:
        break;
    };
}
