#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool czy_pierwsza(int n)
{
    if (n == 0 || n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<int> rozloz_na_czynniki(int n)
{
    vector<int> czynniki;
    for (int i = 2; i <= n; i++)
    {
        if (czy_pierwsza(i))
        {
            while (n % i == 0)
            {
                czynniki.push_back(i);
                n /= i;
                if (n == 1)
                {
                    return czynniki;
                }
            }
        }
    }
    return czynniki;
}
vector<int> zwroc_unikaty(vector<int> numbers)
{
    set<int> unikaty;
    vector<int> wyniki;
    for (auto n : numbers)
        unikaty.insert(n);
    for (auto n : unikaty)
        wyniki.push_back(n);

    return wyniki;
}
void zad1(vector<string> numbers)
{
    int cnt = 0;
    string first_correct;
    for (auto num : numbers)
    {
        if (num[0] == num[num.length() - 1])
        {
            cnt++;
            if (cnt == 1)
            {
                first_correct = num;
            }
        }
    }
    cout << cnt << " " << first_correct << endl;
}

void zad2(vector<int> numbers)
{
    int ma_najwiecej;
    vector<int> najwiecej_czynnikow;
    for (auto n : numbers)
    {
        vector<int> aktualne = rozloz_na_czynniki(n);
        if (aktualne.size() > najwiecej_czynnikow.size())
        {
            najwiecej_czynnikow = aktualne;
            ma_najwiecej = n;
        }
        else if (aktualne.size() == najwiecej_czynnikow.size() && ma_najwiecej > n)
        {
            najwiecej_czynnikow = aktualne;
            ma_najwiecej = n;
        }
    }
    cout << ma_najwiecej << " " << najwiecej_czynnikow.size() << endl;
}
void zad3(vector<int> numbers)
{
    int ma_najwiecej;
    vector<int> najwiecej_unikatowych_czynnikow;
    for (auto n : numbers)
    {
        vector<int> aktualne = rozloz_na_czynniki(n);
        aktualne = zwroc_unikaty(aktualne);
        if (aktualne.size() > najwiecej_unikatowych_czynnikow.size())
        {
            najwiecej_unikatowych_czynnikow = aktualne;
            ma_najwiecej = n;
        }
        else if (aktualne.size() == najwiecej_unikatowych_czynnikow.size() && ma_najwiecej > n)
        {
            najwiecej_unikatowych_czynnikow = aktualne;
            ma_najwiecej = n;
        }
    }
    cout << ma_najwiecej << " " << najwiecej_unikatowych_czynnikow.size() << endl;
}
bool sprawdz_nke(vector<int> nka)
{
    if (zwroc_unikaty(nka).size() != nka.size())
        return false;
    for (int i = 1; i < nka.size(); i++)
    {
        if (nka[i] % nka[i - 1] != 0)
            return false;
    }
    return true;
}

bool compare(const vector<int> &a, const vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}
void zad4(vector<int> numbers)
{
    vector<vector<int>> trojki;
    for (auto x : numbers)
    {
        for (auto y : numbers)
        {
            for (auto z : numbers)
            {
                vector<int> trojka = {x, y, z};
                if (sprawdz_nke(trojka))
                {
                    trojki.push_back(trojka);
                }
            }
        }
    }
    sort(trojki.begin(), trojki.end(), compare);
    cout << trojki.size() << endl;
    for (auto trojka : trojki)
    {
        cout << trojka[0] << " " << trojka[1] << " " << trojka[2] << endl;
    }
}
void zad5(vector<int> numbers)
{
    // to nie jest najpiekniejsze rozwiazanie.
    // lepiej byloby zrobic rekurencyjnie
    sort(numbers.begin(), numbers.end());
    int piatki_cnt = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (!sprawdz_nke({numbers[i], numbers[j]}))
                continue;
            for (int k = j + 1; k < numbers.size(); k++)
            {
                if (!sprawdz_nke({numbers[i], numbers[j], numbers[k]}))
                    continue;
                for (int l = k + 1; l < numbers.size(); l++)
                {
                    if (!sprawdz_nke({numbers[i], numbers[j], numbers[k], numbers[l]}))
                        continue;
                    for (int m = l + 1; m < numbers.size(); m++)
                    {
                        vector<int> piatka = {numbers[i], numbers[j], numbers[k], numbers[l], numbers[m]};
                        if (sprawdz_nke(piatka))
                        {
                            piatki_cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << piatki_cnt << endl;
}
int main()
{
    int zad_number;
    string number_str;
    int number;

    cin >> zad_number;
    vector<string> numbers_str;
    vector<int> numbers;
    for (int i = 0; i < 200; i++)
    {
        cin >> number_str;
        numbers_str.push_back(number_str);

        number = stoi(number_str);
        numbers.push_back(number);
    }
    switch (zad_number)
    {
    case 1:
        zad1(numbers_str);
        break;
    case 2:
        zad2(numbers);
        break;
    case 3:
        zad3(numbers);
        break;
    case 4:
        zad4(numbers);
        break;
    case 5:
        zad5(numbers);
        break;
    default:
        break;
    }
    return 0;
}