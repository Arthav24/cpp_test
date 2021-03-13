#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "func.h"

float SqrtNewRap_fp(float x)
{
    float y = Sqrt_fp(x);
    return (y * y + x) / (2 * y);
}

float Sqrt_fp(float x)
{
    if (x < 0)
        return -1;
    return AsFloat((AsInt(x) >> 1) + (OneAsInt >> 1));
}

float Pow_fp(float x, float p)
{
    return AsFloat(int(p * ((AsInt(x) - OneAsInt) * ScaleDown) * ScaleUp) + OneAsInt);
}

float Exp2_fp(float x)
{
    return AsFloat(int(x * ScaleUp) + OneAsInt);
}

float Log2_fp(float x)
{
    if (x < 0)
        return -1;
    else
        return float(AsInt(x) - OneAsInt) * ScaleUp;
}

inline unsigned int AsInt(float f)
{
    return *(unsigned int *)&f;
}

inline float AsFloat(unsigned int i)
{
    return *(float *)&i;
}

float NegateFloat(float f)
{
    return AsFloat(AsInt(f) ^ 0x80000000);
}

void deletea2d(int **&a2d, int &r)
{
    for (int i = 0; i < r; i++)
        delete[] a2d[i];
    delete[] a2d;
}

int **create_init_a2d(int r, int c)
{
    int **a2d = new int *[r];

    for (int i = 0; i < r; i++)
        a2d[i] = new int[c];

    std::string in;
    int s;
    int k = 0;
    std::cin.ignore();
    for (int i = 0; i < r; i++)
    {
        std::getline(std::cin, in);
        for (int j = 0; j < c; j++)
        {
            a2d[i][j] = in[k];
            k += 2;
        }
        k = 0;
        in.clear();
    }
    return a2d;
}

void printa2d(int **&a2d, int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << a2d[i][j] - '0' << " ";
        }
        std::cout << std::endl;
    }
}

void swapfirst_last_col(int **&a2d, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int temp = a2d[i][0];
        a2d[i][0] = a2d[i][c - 1];
        a2d[i][c - 1] = temp;
    }
}

int Alpha_num_sum(std::string in_)
{
    int s_len = in_.length();
    if (s_len == 0)
        return 0;
    else
    {
        int sum = 0;
        for (auto i : in_)
        {
            if ((int)i > 47 && (int)i < 58)
                sum += ((int)i - '0');
            // std::cout<<i-'0'<<std::endl;
        }
        return sum;
    }
}
//Quake 3 fast inverse root
float Q_rsqrt(float num)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5f;
    x2 = num * 0.5f;
    y = num;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    // y=y*(threehalfs-(x2*y*y));
    return y;
}

int *create_init_array(int &size)
{
    int *array = new int[size];
    std::cin.ignore();
    std::string in;
    std::getline(std::cin, in);
    int k = in.length() - 1, count = 0, no = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        for (; in[k] != ' ' && k >= 0;)
        {
            no = no + ((in[k] - '0') * std::pow(10, count));
            k--;
            count++;
        }
        k--;
        array[i] = no;
        no = 0;
        count = 0;
    }
    return array;
}
void dsum_possible(int *&array, int &size, int &dsum)
{

    int *array_front = array;
    int *array_back = array + (size - 1);

    for (; *array_front + *array_back != dsum;)
    {
        if (*array_front + *array_back < dsum)
            array_front++;
        else if (*array_front + *array_back > dsum)
            array_back--;
        if (array_front == array_back)
        {
            std::cout << "no";
            break;
        }
    }
    std::cout << std::endl;
    std::cout << *array_front << std::endl;
    std::cout << *array_back << std::endl;
}