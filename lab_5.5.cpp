#include <iostream>
#include <iomanip>
using namespace std;

double toTwo(int number, int& depth);
double toEight(int number, int& depth);
double convertToBase(int number, int base, int& depth);

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
    cout << "----------------------------------------------------" << endl;
    cout << "|" << setw(10) << "System" << "  |"
        << setw(10) << "Result" << "  |"
        << setw(10) << "Depth" << "  |" << endl;
    cout << "----------------------------------------------------" << endl;


    // Переведення у двійкову систему
    depth = 0;
    double two = toTwo(number, depth);
    cout << "|" << setw(10) << "Two" << "  |"
        << setw(10) << setprecision(0) << two << "  |"
        << setw(10) << depth << "  |" << endl;

    // Переведення у вісімкову систему
    depth = 0;
    double eight = toEight(number, depth);
    cout << "|" << setw(10) << "Eight" << "  |"
        << setw(10) << setprecision(0) << eight << "  |"
        << setw(10) << depth << "  |" << endl;

    depth = 0;
    double convertedNumber = convertToBase(number, base, depth);

    cout << "|" << setw(8) << "Base " << base << "  |"
        << setw(10) << setprecision(0) << convertedNumber << "  |"
        << setw(10) << depth << "  |" << endl;

    cout << "----------------------------------------------------" << endl;

    return 0;
}

// Рекурсивна функція для переведення у двійкову систему
double toTwo(int number, int& depth)
{
    if (number == 0) return 0;

    depth++;
    return toTwo(number / 2, depth) * 10 + (number % 2);
}

// Рекурсивна функція для переведення у вісімкову систему
double toEight(int number, int& depth)
{
    if (number == 0) return 0;

    depth++;
    return toEight(number / 8, depth) * 10 + (number % 8);
}

// Рекурсивна функція для переведення числа у систему з основою N
double convertToBase(int number, int base, int& depth)
{
    if (number == 0) return 0;

    depth++;
    return convertToBase(number / base, base, depth) * 10 + (number % base);
}
