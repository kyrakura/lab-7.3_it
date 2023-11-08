#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

void Create(int** a, const int row, const int col, const int Low, const int High);// ��������� ������� � ����������� ����������
void Input(int** a, const int row, const int col);// �������� ������� � ���������
void Print(int** a, const int row, const int col);// ��������� ������� �� �����
int SumWithoutNegatives(int** a, const int row, const int col);// ���������� ���� �������� � �������� ��� ��'����� ��������
void DiagonalSum(int** a, const int row, const int col);// ����������� ������ ����� ��� ������ �������� ���������

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int row, col;
    cout << "row = "; cin >> row;
    cout << "col = "; cin >> col;

    int** a = new int* [row];
    for (int i = 0; i < row; i++)
    a[i] = new int[col];

    Create(a, row, col, Low, High);
    Print(a, row, col);

    int sumWithoutNegatives = SumWithoutNegatives(a, row, col);
    cout << "����� ��������� � �������� ��� �������: " << sumWithoutNegatives << endl;
    DiagonalSum(a, row, col);

    for (int i = 0; i < row; i++)
    delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int row, const int col, const int Low, const int High)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int row, const int col)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumWithoutNegatives(int** a, const int row, const int col)
{
    int sum = 0;

    for (int j = 0; j < col; j++)
    {
        bool hasNegative = false;
        for (int i = 0; i < row; i++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
        {
            for (int i = 0; i < row; i++)
                sum += a[i][j];
        }
    }
    return sum;
}

void DiagonalSum(int** a, const int row, const int col)
{
    int minDiagonalSum = INT_MAX;

    for (int k = 0; k < row + col - 1; k++)
    {
        int diagonalSum = 0;
        if (k < row)
        {
            for (int i = 0; i <= k; i++)
            {
                int j = k - i;
                if (j < col)
                {
                    diagonalSum += abs(a[i][j]);
                }
            }
        }
        else
        {
            for (int i = k - row + 1; i < row; i++)
            {
                int j = k - i;
                if (j < col)
                {
                    diagonalSum += abs(a[i][j]);
                }
            }
        }
        if (diagonalSum < minDiagonalSum)
        {
            minDiagonalSum = diagonalSum;
        }
    }
    cout << "����������� ����� ���������� �������� ����������: " << minDiagonalSum << endl;
}
