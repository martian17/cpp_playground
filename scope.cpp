#include <stdio.h>
#include <vector>

class SomeClass{//simulate the behavior of std::string
public:
    int* arr;
    int len;
    SomeClass(int length, int content){
        fprintf(stderr,"SomeClass constructor %d, %d\n",length,content);
        arr = new int[length];
        fprintf(stderr,"SomeClass constructor allocated\n");
        for(int i = 0; i < length; i++){
            arr[i] = content+i;
        }
        fprintf(stderr,"SomeClass constructor initialized\n");
        len = length;
    };
    int getValue(int idx){
        fprintf(stderr,"getValue called, the array is: ");
        for(int i = 0; i < len; i++){
            fprintf(stderr,"%d ",arr[i]);
        }
        fprintf(stderr,"\n");
        return arr[idx];
    };
    ~SomeClass(){
        fprintf(stderr,"destructor called\n");
        delete[] arr;
    };
};

std::vector<SomeClass> someFunc(int length, int size){
    fprintf(stderr,"somefunc\n");
    std::vector<SomeClass> result;
    for(int i = 0; i < size; i++){
        fprintf(stderr,"getting someclass into result %d\n",i);
        SomeClass temp(length,i+2);
        fprintf(stderr,"%d\n",temp.getValue(1));
        result.push_back(temp);
        fprintf(stderr,"got someclass into result %d\n",i);
    }
    fprintf(stderr,"returning from someFunc\n");
    return result;
};


int main(){
    fprintf(stderr,"main begin\n");
    std::vector<SomeClass> result = someFunc(10,5);
    //printing the result
    for(int i = 0; i < result.size(); i++){
        fprintf(stderr,"value at index %d,1: %d\n",i,result[i].getValue(1));
    }
    fprintf(stderr,"main end\n");
}
