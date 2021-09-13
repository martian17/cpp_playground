#include <iostream>
#include <string>
#include <stdio.h>
#include <regex>


struct insertion{
    int x;
    int y;
    std::string match;
};


class CLI{
private:
    std::vector<insertion> insertions;
    std::string printable;
    int x;
    int y;
public:
    CLI(std::string clistr){
        printable = "";
        x = 0;
        y = 0;
        int last_position = 0;
        
        //initializing the insertions vector
        // normal insertion | regex insertion
        // base string: (%[sd])|(%\{(?![*+?])(?:[^\r\n\[\/\\]|\\.|\[(?:[^\r\n\]\\]|\\.)*\])+\})
        std::regex insertPattern("(%[sd])|(%\\{(?![*+?])(?:[^\\r\\n\\[\\/\\\\]|\\\\.|\\[(?:[^\\r\\n\\]\\\\]|\\\\.)*\\])+\\})");
        for(std::sregex_iterator i = std::sregex_iterator(clistr.begin(), clistr.end(), insertPattern);
            i != std::sregex_iterator();
            ++i ){
                
            std::smatch match = *i;
            
            std::string str = match.str();
            int a = match.position();
            int b = str.length();
            
            //building the printable string
            std::string section = clistr.substr(last_position,a-last_position);
            printable += section;
            //loop through the section to find new lines, and update line and x
            for(int i = 0; i < section.length(); i++){
                if(section[i] == '\n'){
                    x = 0;
                    y++;
                }else{
                    x++;
                }
            }
            insertion ins;
            ins.x = x;
            ins.y = y;
            ins.match = str;
            insertions.push_back(ins);//makes a copy inside insertions
            last_position = a+b;
            if(clistr[b] != '\n'){
                //add spaces to make up for the loss
                printable.resize(printable.length()+b,' ');
            }
        }
        std::string section = clistr.substr(last_position,clistr.length()-last_position);
        printable += section;
        for(int i = 0; i < section.length(); i++){
            if(section[i] == '\n'){
                x = 0;
                y++;
            }else{
                x++;
            }
        }
        std::cout << x << "," << y << std::endl;
        
        //check the contents of the insertions
        for(int i = 0; i < insertions.size(); i++){
            insertion ins = insertions[i];
            std::cout << ins.match << ", " << ins.x << ", " << ins.y << std::endl;
        }
    };
    
    std::vector<std::string> requestInput(){
        std::vector<std::string> result;
        result.reserve(insertions.size());
        for(int i = 0; i < insertions.size(); i++){
            result[i] = insertions[i].match;
        }
        return result;
    };
};


//std::string

int main(){
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
    CLI cli(clistr);
    std::vector<std::string> strs = cli.requestInput();
    /*for(int i = 0; i < strs.size(); i++){
        std::cout << strs[i] << std::endl;
    }*/
}