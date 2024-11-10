#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int rows = 1000;
vector<string> bin_numbers(rows);

bool first_last_digits_the_same(string bin) {
    if (bin.size() % 2 == 1)
        return false;

    int mid = bin.size() / 2;
    for (int i = 0; i < bin.size() / 2; i++) {
        if (bin[i] != bin[mid + i]) {
            return false;
        }
    }
    return true;
}

void ex1() {
    for (auto bin: bin_numbers) {
        if (first_last_digits_the_same(bin))
            cout << bin << endl;
    }
}

bool two_ones_are_nbours(string bin) {
    for (int i = 0; i < bin.size() - 1; i++) {
        if (bin[i] == '1' && bin[i + 1] == '1')
            return true;
    }
    return false;
}

void ex2() {
    int counter = 0;
    for (auto bin: bin_numbers) {
        if (!two_ones_are_nbours(bin)) counter++;
    }
    cout << counter << endl;
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

// w zadaniu 3 bardzo czesto wywolujemy funkcje is_prime co moze być nieefektywne, poniewaz prawodopodobnie wywolujemy ja dla tej samej wartosci
// lepszym rozwiazaniem byloby:
// 1. wykorzystanie algorytmy sita (np. sito eratostenesa)
// albo
// 2. zapisywanie gdzies poprzednio policzonych liczb pierwszych (na przyklad w secie) i wykorzystywanie go przed wywolaniem funkcji 'is_prime' - taki mechanizm nazywa sie "CACHE"
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }
    return true;
}

bool is_half_prime(int num) {
    for (int factor1 = 2; factor1 < num; factor1++) {
        // potrzebujemy pary liczb pierwszych
        if (!is_prime(factor1)) continue; // jesli pierwszy czynnik nie jest liczbą pierwszą, szukamy dalej

        if (num % factor1 == 0) {
            int factor2 = num / factor1; // obliczamy drugi czynnik
            if (is_prime(factor2)) return true; // jesli tez jest liczba pierwsza, to 'bin' jest liczba pol pierwsza
        }
    }
    return false;
}

void ex3() {
    int counter = 0;
    int max_v = -1;
    int min_v = INT32_MAX;
    for (auto bin: bin_numbers) {
        int current = to_dec_from_oct(bin);
        if (is_half_prime(current)) {
            counter++;
            min_v = min(min_v, current);
            max_v = max(max_v, current);
        }
    }
    cout << counter << endl << max_v << endl << min_v << endl;
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
