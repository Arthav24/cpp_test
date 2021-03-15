#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include "func.h"

int main()
{   
    int x=0,y=0,a=0,b=0;
    std::cin>>a>>b;
    std::cout<<gcdExtended(a,b,&x,&y)<<" "<<x<<" "<<y;
}