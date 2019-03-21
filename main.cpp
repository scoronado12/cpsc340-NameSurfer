#include <fstream>
#include <iostream>
#include <linked_list.h>

using namespace std;

int main(){
    
    ifstream inputfile;
    //open file
    inputfile.open("NamesData.txt");
    
    //check if open
    
    if(!inputfile.is_open()){
        cout << "Not Open" << endl;
        exit(1);
    } else {
        while (!inputfile.eof()){
            string line;
        }
    }
    
    
    
    return 0;
}
