#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

#include "func.h"

int main()
{
    int size_array=0;
    std::cin>>size_array;
    std::cin.ignore();
    int* array=nullptr;
    if(size_array>0)
        array = create_init_array(size_array);
    else{
        std::cout<<"INVALID array size";
        return -1;
    }
    print_array(array,);
    



}   