#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int n = 10;
    int a[n];

    srand(time(0));

    // Генерація масиву
    cout << "Початковий масив:\n";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 101 - 50; // від -50 до 50
        cout << a[i] << " ";
    }
    cout << "\n\n";

    // Підрахунок додатніх елементів і їх добутку
    int countPositive = 0;
    long long product = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            countPositive++;
            product *= a[i];
        }
    }

    if (countPositive == 0)
        cout << "Додатніх елементів немає.\n";
    else
        cout << "Кількість додатніх елементів = " << countPositive
             << "\nДобуток = " << product << "\n";

    cout << "\n";

    // --- Сортування методом екстремальних елементів (selection sort) ---
    int b[n];
    for (int i = 0; i < n; i++) b[i] = a[i];

    for (int j = 0; j < n - 1; j++) {
        int minim = j;
        for (int i = j + 1; i < n; i++) {
            if (b[i] < b[minim]) {
                minim = i;
            }
        }
        // обмін
        int temp = b[j];
        b[j] = b[minim];
        b[minim] = temp;
    }

    cout << "Після сортування методом екстремальних елементів:\n";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n\n";

    // --- Сортування методом бульбашки (bubble sort) ---
    int c[n];
    for (int i = 0; i < n; i++) c[i] = a[i];

    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - j - 1; i++) {
            if (c[i] > c[i + 1]) {
                int temp = c[i];
                c[i] = c[i + 1];
                c[i + 1] = temp;
            }
        }
    }

    cout << "Після сортування методом бульбашки:\n";
    for (int i = 0; i < n; i++) cout << c[i] << " ";
    cout << "\n";

    return 0;
}

