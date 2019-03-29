/**
 * @author scoronado
 * @since 2019-03-20
 * main.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "NameSurferDataBase.h"

using namespace std;

/**
 * Function Prototypes
 */
void searchName(string name, NameSurferDataBase &database);
void compYear(int year, int namesToComp ,NameSurferDataBase &database);
void fixName(string &name);
int main(){
    string selection = "";
    string name = "";
    int year;
    
    //initialize db that imports text file
    NameSurferDataBase db("NamesData.txt"); 
    
    
    //Menu
    while (true){
        cout << "1:Enter a name to be searched." << endl;
        cout << "2:Enter a year" << endl;
        cout << "3:Exit" << endl << "Enter a choice:";
        
        
        cin >> selection;
        // selection is a string to mitigate the while loop from igoring cin as a blocking call
        
        
        if (selection == "3"){
            break;
            
        } else if (selection == "2"){
            int namesToComp;
            cout << "Enter a year:";
            cin >> year;
            
            cout << "Enter how many Names you want to compare:";
            cin >> namesToComp;
            compYear(year, namesToComp ,db);
            
        } else if (selection == "1"){
            cout << "Enter in a name:";
            cin >> name;
            searchName(name, db);
        } else {
            cout << "Please enter a choice " << endl;
            exit(1);
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
    
    fixName(name);
    
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
 * Option 2 - compare names by year
 * TODO finish by Monday
 */
void compYear(int year, int namesToComp, NameSurferDataBase &database){
    //TODO round number down to the last tenth so 1969 becomes 1960 or 2016 becomes 2010
    string names[namesToComp];
    //Get the names
    int displayCounter = 1;
    for (int i = 0; i < namesToComp; i++){
        
        cout << "Enter name " << displayCounter << ":";
        cin >> names[i];
        fixName(names[i]);
        displayCounter++;
    }
    
    for (string s : names){
        cout << s << "\t";
        cout << endl;
    }
}
    
/** fixName(name)
 *  helper function to correct the input of a name
 */

void fixName(string &name){
    
    transform(name.begin(), name.end(), name.begin(), ::tolower); //makes everything lowercase
    name.at(0) = toupper(name.at(0)); //make first char uppercase if not already
    
    
}
    
    


