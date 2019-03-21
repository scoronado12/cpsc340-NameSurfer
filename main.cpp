#include <fstream>
#include <iostream>
#include <linked_list.h>

using namespace std;

int main(){
    
    ifstream inputfile;
    //open file
    inputfile.open("NamesData.txt");
    
    //check if open
    
    string line; // need not to declare the line at every for loop
    if(!inputfile.is_open()){
        cout << "Not Open" << endl;
        exit(1);
    } else {
        while (!inputfile.eof()){
        }
    }
    
    
    
    return 0;
}
