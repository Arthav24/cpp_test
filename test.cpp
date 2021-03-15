#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include "func.h"

int main()
{   int no_s=0;
 std::string in="";
std::cin>>no_s;

while(no_s!=0){
in.clear();
std::cin.ignore();
std::getline(std::cin,in);
int flag = pangramCheck(in);
flag == 1 ? std::cout<<"1":std::cout<<"0";
std::cout<<std::endl;
--no_s;
}



}