/**
 * @author scoronado
 * @since 2019-03-20
 * main.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"
#include "NameSurferDataBase.h"

using namespace std;


void searchName(string name, NameSurferDataBase &database);
void enterYear(int year, NameSurferDataBase &database);

int main(){
    string selection = "";
    int year = 0;
    string name = "";
    
    
    NameSurferDataBase db("NamesData.txt"); 
    
    
    //Menu
    while (true){
        cout << "1:Enter a name to be searched." << endl;
        cout << "2:Enter a year" << endl;
        cout << "3:Exit\n" << "Enter a choice:";
        
        
        cin >> selection;
        // selection is a string to mitigate the while loop from igoring cin as a blocking call
        
        
        if (selection == "3"){
            exit(0);
            
        } else if (selection == "2"){
            
            cout << "Enter a year:";
            cin >> year;
            enterYear(year, db);
            
        } else if (selection == "1"){
            cout << "Enter in a name:";
            cin >> name;
            searchName(name, db);
        } else {
            cout << "Please enter a choice " << endl;
        }
        
        name = "";
        year = 0;
        selection = "";
        
        
    }
    
    return 0;
}



/**
 * Option 1 - Search name prints out relevant data about a given name
 */
void searchName(string name, NameSurferDataBase &database){
    
    transform(name.begin(), name.end(), name.begin(), ::tolower); //makes everything lowercase
    name.at(0) = toupper(name.at(0)); //make first char uppercase if not already
    
    cout << database.findEntry(name) << endl;
    NameSurferEntry nombre = database.findEntry(name);
    
    vector<int> ranks = nombre.getRankVec();
    int year = 1900;
    
    for (int i = 0; i < ranks.size(); i++){
        cout << year;
        // for every tenth iteration, one asterisk will be outputted
        for (int j = 0 ; j < ranks.at(i) - 10 && j % 10 == 0; j = j + 10){
            cout << "*";
        }
        //complete the outputted string and endline
        cout << "-" << ranks.at(i) << endl;
        
        //increment year by 10
        year = year + 10;
    }
    
    
}
/**
 * Option 2 - compare by year
 * TODO finish by Monday
 */
void enterYear(int year, NameSurferDataBase &database){
    
}

