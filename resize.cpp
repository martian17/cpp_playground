#include <iostream>
#include <string>

int main(){
    std::string str = "0123";
    str.resize(str.length()+5,'?');
    std::cout << str << std::endl;
}