/**
 * @author scoronado
 * @since 2019-03-20
 * main.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
#include "linked_list.h"
#include "NameSurferDataBase.h"

using namespace std;

// friend class NameSurferDataBase;

void searchName(string name);
void enterYear(int year);

int main(){
    int selection = 0;
    int year = 0;
    string name = "";
    NameSurferDataBase("NamesData.txt");
    
    
    
    //Menu
    bool menuRun = true;
    while (menuRun == true){
        cout << "1:Enter a name to be searched." << endl;
        cout << "2:Enter a year" << endl;
        cout << "3:Exit\n" << "Enter a choice:";
        
        
        cin >> selection;
        
        if (selection == 3){
            exit(0);
            
        } else if (selection == 2){
            
            cout << "Enter a year:";
            cin >> year;
            enterYear(year);
            
        } else if (selection == 1){
            cout << "Enter in a name:";
            cin >> name;
            searchName(name);
        }
        
        name = "";
        year = 0;
        selection = 0;
        
        
    }
    
    return 0;
}

//TODO find way to interract with NameSurferDataBase from main.cpp


/**
 * Option 1 - Search name
 */
void searchName(string name){
    findEntry(name);
    
}
/**
 * Option 2 - compare by year
 */
void enterYear(int year){
    
}

