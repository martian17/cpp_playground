#include <stdio.h>
#include <vector>

class SomeClass{//simulate the behavior of std::string
public:
    int* arr;
    int len;
    SomeClass(int len, int val){
        this->len = len;
        arr = new int[len];
        for(int i = 0; i < len; i++){
            arr[i] = val;
        }
    };
    int getValue(int idx){
        return arr[idx];
    };
    ~SomeClass(){
        fprintf(stderr,"destructor called (id: %d)\n",arr[0]);
    };
};

std::vector<SomeClass> someFunc(int size, int inner_size){
    std::vector<SomeClass> result;
    for(int i = 0; i < size; i++){
        SomeClass temp = new SomeClass(inner_size,i);
        result.push_back(temp);
        fprintf(stderr,"element %d created\n",i);
    }
    return result;
};


int main(){
    fprintf(stderr,"main begin\n");
    std::vector<SomeClass> result = someFunc(5,10);
    //printing the result
    for(int i = 0; i < result.size(); i++){
        fprintf(stderr,"value at index %d,1: %d\n",i,result[i].getValue(1));
    }
    fprintf(stderr,"main end\n");
}
