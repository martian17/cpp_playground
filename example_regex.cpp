#include <iostream>
#include <string>
#include <regex>
#include <vector>

//simple function that returns matches
std::vector<std::string> return_matches(std::string str){
    std::regex reg("[0-9]+");
    std::vector<std::string> result;
    
    for(std::sregex_iterator i = std::sregex_iterator(str.begin(), str.end(), reg);
        i != std::sregex_iterator();
        ++i ){
        std::smatch match = *i;
        result.push_back(match.str());
    }
    
    return result;
}

int main(){
    std::string input = "hello 123 afsdha 554 asda 12 721";
    std::vector<std::string> result = return_matches(input);
    
    //printing the result
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << std::endl;
    }
}