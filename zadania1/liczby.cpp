#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int rows = 5000;
vector<string> oct_numbers(rows);

bool first_last_digits_the_same(string oct) {
    return oct.at(0) == oct.at(oct.size() - 1);
}

void ex1() {
    int counter = 0;
    for (auto oct: oct_numbers) {
        if (first_last_digits_the_same(oct))
            counter++;
    }
    cout << counter << endl;
}

int to_dec_from_oct(string oct) {
    int dec = 0;
    int eight_power = 1;
    for (int i = oct.size() - 1; i >= 0; i--) {
        dec += eight_power * (oct.at(i) - '0');
        eight_power *= 8;
    }
    return dec;
}

void ex2() {
    int counter = 0;
    for (auto oct: oct_numbers) {
        int dec = to_dec_from_oct(oct);
        string str_dec = to_string(dec);
        if (first_last_digits_the_same(str_dec))
            counter++;
    }
    cout << counter << endl;
}

bool is_sorted(string oct) {
    string sorted_oct = oct;
    sort(oct.begin(), oct.end());
    return sorted_oct == oct;
}

void ex3() {
    int counter = 0;
    int max_v = -1;
    string max_v_oct;
    int min_v = INT32_MAX;
    string min_v_oct;
    for (auto oct: oct_numbers) {
        int current = to_dec_from_oct(oct);
        if (is_sorted(oct)) {
            counter++;
            if (min_v > current) {
                min_v = current;
                min_v_oct = oct;
            }
            if (max_v < current) {
                max_v = current;
                max_v_oct = oct;
            }
        }
    }
    cout << counter << endl << max_v_oct << endl << min_v_oct << endl;
}

int main() {
    int exercise;
    cin >> exercise;
    for (int i = 0; i < rows; i++) {
        cin >> oct_numbers[i];
    }
    switch (exercise) {
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
