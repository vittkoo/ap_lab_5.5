#include <iostream>
#include <iomanip>
using namespace std;

double toTwo(int number, int level, int& depth);
double toEight(int number, int level, int& depth);
double convertToBase(int number, int base, int level, int& depth);

int main()
{
    int number, depth = 0;

    cout << "Enter number in 10th system: "; cin >> number;

    // Переведення у систему числення з основою N > 1
    int base;
    cout << "Enter base of computing system (N > 1): "; cin >> base;

    if (base < 2)
    {
        cout << "Base must be greater than 1." << endl;
        return 1;
    }

    cout << fixed;
    cout << "--------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "System" << "  |"
        << setw(12) << "Result" << "  |"
        << setw(10) << "Depth" << "  |" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Переведення у двійкову систему
    depth = 0;
    double two = toTwo(number, 1, depth);
    cout << "|" << setw(10) << "Two" << "  |"
        << setw(12) << setprecision(0) << two << "  |"
        << setw(10) << depth << "  |" << endl;

    // Переведення у вісімкову систему
    depth = 0;
    double eight = toEight(number, 1, depth);
    cout << "|" << setw(10) << "Eight" << "  |"
        << setw(12) << setprecision(0) << eight << "  |"
        << setw(10) << depth << "  |" << endl;

    // Переведення у систему з базою base
    depth = 0;
    double convertedNumber = convertToBase(number, base, 1, depth);
    cout << "|" << setw(9) << "Base " << base << "  |"
        << setw(12) << setprecision(0) << convertedNumber << "  |"
        << setw(10) << depth << "  |" << endl;

    cout << "--------------------------------------------------------" << endl;

    return 0;
}

// Рекурсивна функція для переведення у двійкову систему
double toTwo(int number, int level, int& depth)
{
    if (level > depth) {
        depth = level;
    }
    cout << "Level = " << level << endl;

    if (number == 0) return 0;
    return toTwo(number / 2, level + 1, depth) * 10 + (number % 2);
}

// Рекурсивна функція для переведення у вісімкову систему
double toEight(int number, int level, int& depth)
{
    if (level > depth) {
        depth = level;
    }
    cout << "Level = " << level << endl;

    if (number == 0) return 0;
    return toEight(number / 8, level + 1, depth) * 10 + (number % 8);
}

// Рекурсивна функція для переведення числа у систему з основою N
double convertToBase(int number, int base, int level, int& depth)
{
    if (level > depth) {
        depth = level;
    }
    cout << "Level = " << level << endl;

    if (number == 0) return 0;
    return convertToBase(number / base, base, level + 1, depth) * 10 + (number % base);
}
