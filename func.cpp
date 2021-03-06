#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "func.h"

// using String = std::string;


float functions::SqrtNewRap_fp(float x)
{
    float y = Sqrt_fp(x);
    return (y * y + x) / (2 * y);
}

float functions::Sqrt_fp(float x)
{
    if (x < 0)
        return -1;
    return AsFloat((AsInt(x) >> 1) + (OneAsInt >> 1));
}

float functions::Pow_fp(float x, float p)
{
    return AsFloat(int(p * ((AsInt(x) - OneAsInt) * ScaleDown) * ScaleUp) + OneAsInt);
}

float functions::Exp2_fp(float x)
{
    return AsFloat(int(x * ScaleUp) + OneAsInt);
}

float functions::Log2_fp(float x)
{
    if (x < 0)
        return -1;
    else
        return float(functions::AsInt(x) - OneAsInt) * ScaleUp;
}

inline unsigned int functions::AsInt(float f)
{
    return *(unsigned int *)&f;
}

inline float functions::AsFloat(unsigned int i)
{
    return *(float *)&i;
}

float functions::NegateFloat(float f)
{
    return AsFloat(functions::AsInt(f) ^ 0x80000000);
}

void functions::deletea2d(int **&a2d, int &r)
{
    for (int i = 0; i < r; i++)
        delete[] a2d[i];
    delete[] a2d;
}

int** functions::create_init_a2d(int r, int c)
{
    int **a2d = new int *[r];

    for (int i = 0; i < r; i++)
        a2d[i] = new int[c];

    String in;
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

void functions::printa2d(int **&a2d, int r, int c)
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

void functions::swapfirst_last_col(int **&a2d, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int temp = a2d[i][0];
        a2d[i][0] = a2d[i][c - 1];
        a2d[i][c - 1] = temp;
    }
}

int functions::Alpha_num_sum(String in_)
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
float functions::Q_rsqrt(float num)
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

int* functions::create_init_array(int &size)
{
    int *array = new int[size];
    // std::cin.ignore();
    String in;
    std::getline(std::cin, in);
    int k = in.length()-1, count = 0, no = 0;
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
void functions::print_array(int* &array,int& size){
 std::cout<<std::endl;
for(int i=0;i<size;i++){
    std::cout<<array[i]<<" ";

    }
    std::cout<<std::endl;

}

void functions::dsum_possible(int *&array, int &size, int &dsum)
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
int functions::gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
}

void functions::pangramCheck(String &in){
    int alpha[26];
    for (int i = 0; i < 27; i++)
    {
        alpha[i] = 0;
    }
    int s_in = in.length();
    for (int i = 0; i < s_in; i++)
    {
        char c = in[i];
        if (c == ',' || c == ' ')
            continue;
        if (c >= 'A' && c <= 'Z')
        {

            alpha[c - 'A'] = 1;
        }

        if (c >= 'a' && c <= 'z')
        {
            alpha[c - 'a'] = 1;
        }
    }
    int flag = 1;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] != 1)
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    try{
        flag == 1 ? std::cout<<"1":std::cout<<"0";
    }
    catch(const std::exception &e){
        std::cout<<e.what();
    }
    
}