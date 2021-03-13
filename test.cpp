#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include "func.h"

int main()
{
    int size = 0, dsum = 0;
    std::cin >> size >> dsum;
    int *array = create_init_array(size);
    std::sort(array, array + (size));
    dsum_possible(array, size, dsum);
    delete[] array;
}