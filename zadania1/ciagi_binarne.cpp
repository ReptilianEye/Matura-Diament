#include <iostream>
#include <vector>
#include <string>

using namespace std;

int rows = 500;
vector<string> bin_numbers(rows);

bool first_last_digits_the_same(string bin) {
    int mid = bin.size() / 2;
    for (int i = 0; i < bin.size() / 2; i++) {
        if (bin[i] != bin[mid + i]) {
            return false;
        }
    }
    return true;
}

void ex1() {
    int two_cyclic_count = 0;
    string longest_two_cyclic = "";
    for (auto bin: bin_numbers) {
        if (first_last_digits_the_same(bin)) {
            two_cyclic_count++;
            if (longest_two_cyclic.size() < bin.size())
                longest_two_cyclic = bin;
        }
    }
    cout << two_cyclic_count << endl << longest_two_cyclic << endl << longest_two_cyclic.size() << endl;
}

int to_dec_from_oct(string bin) {
    int dec = 0;
    int two_power = 1;
    for (int i = bin.size() - 1; i >= 0; i--) {
        if (bin[i] == '1')
            dec += two_power;
        two_power *= 2;
    }
    return dec;
}

bool is_valid(string bin) {
    for (int i = 0; i < bin.size(); i = i + 4) {
        string current_segment = bin.substr(i, 4);
        if (to_dec_from_oct(current_segment) > 9)
            return false;
    }
    return true;
}

void ex2() {
    int invalid_count = 0;
    int len_of_shortest_invalid = INT32_MAX;
    for (auto bin: bin_numbers) {
        if (!is_valid(bin)) {
            invalid_count++;
            len_of_shortest_invalid = min(len_of_shortest_invalid, (int) bin.size());
        }
    }
    cout << invalid_count << endl << len_of_shortest_invalid << endl;
}

void ex3() {
    int max_v = 0;
    string max_v_bin = "";
    for (auto bin: bin_numbers) {
        int current = to_dec_from_oct(bin);
        if (current > 65535) continue;

        if (max_v < current) {
            max_v = current;
            max_v_bin = bin;
        }
    }
    cout << max_v_bin << endl << max_v << endl;
}

int main() {
    int exercise;
    cin >> exercise;
    for (int i = 0; i < rows; i++) {
        cin >> bin_numbers[i];
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
