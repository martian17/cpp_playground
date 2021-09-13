#include <iostream>
#include <string>
#include <stdio.h>
#include <regex>

//testing the regular expression

int main(){
    //base string: (%[sd])|(%\{(?![*+?])(?:[^\r\n\[\/\\]|\\.|\[(?:[^\r\n\]\\]|\\.)*\])+\})
    std::string str = "(%[sd])|(%\\{(?![*+?])(?:[^\\r\\n\\[\\/\\\\]|\\\\.|\\[(?:[^\\r\\n\\]\\\\]|\\\\.)*\\])+\\})";
    //std::string str = "(%[sd]|%\\{.+\\})";
    std::cout << str << std::endl;
    
    
    std::string clistr = 
    "===========\n"
    "Wiggler\n"
    "===========\n"
    "Use [Tab]/[Shift][Tab] or [down]/up key to move around\n"
    "Wiggle width: %d\n"
    "Wiggle height: %d\n"
    "Delay in each slice of wiggle (ms): %d\n"
    "Wiggle infinitely? (Y/n): %{[YyNn]}\n"//regex notation
    "How many times to wiggle? : %d\n"
    "The text to wiggle: %s\n"
    "Wiggle!";
    std::regex insreg(str);
    
    
    for(std::sregex_iterator i = std::sregex_iterator(clistr.begin(), clistr.end(), insreg);
        i != std::sregex_iterator();
        ++i ){
            
        std::smatch match = *i;
        
        std::string str = match.str();
        std::cout << str << " position: " << match.position()<< std::endl;
    }
}