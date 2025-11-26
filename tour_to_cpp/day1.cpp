#include<iostream>
using namespace std;

class String {
    private:
        char* data;
        int len;
    
    public:
        String(const char* s){
            len = 0;
            while(s[len] != '\0') len++;

            data = new char[len];
            for(int i = 0; i < len; i++){
                data[i] = s[i];
            }
        }

        // operator[] declaration
        char& operator[](int index);

        // destructor to free memory
        ~String() {
            delete[] data;
        }
};

// operator[] definition (outside class)

char& String::operator[](int index){
    return data[index];
}


int main(){
    
}