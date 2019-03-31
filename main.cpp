/**
 * @author scoronado
 * @since 2019-03-20
 * main.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "NameSurferDataBase.h"

using namespace std;

/**
 * Function Prototypes
 */
void searchName(string name, NameSurferDataBase &database);
void compYear(int year, int namesToComp ,NameSurferDataBase &database);
void fixName(string &name);


/**
 * Main function, contains the main menu
 */

int main(){
    string selection = "";
    string name = "";
    int year;
    
    //initialize db that imports text file
    NameSurferDataBase db("NamesData.txt"); 
    
    
    //Menu
    while (true){
        cout << endl <<"1:Enter a name to be searched." << endl;
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



/** searchName(string name, NameSurferDataBase &database)
 * Option 1 - Search name prints out relevant data about a given name
 * @param name - can be of any format caps or not
 * @param database - the NameSurferEntry object passed by reference just incase
 * @returns void
 */
void searchName(string name, NameSurferDataBase &database){
    
    fixName(name);
    
    NameSurferEntry nombre = database.findEntry(name); //get it to return something acceptable if not found
    

    
    vector<int> ranks = nombre.getRankVec();
    //NO! The year is not hardcoded here by any means
    
    nombre.empty();
    
    int yearIterator = 1900;
    
    if (nombre != NameSurferEntry()){
        cout << name << endl;
        
        for (int i = 0; i < ranks.size(); i++){
            cout << yearIterator;
            // for every tenth iteration, one asterisk will be outputted
            for (int j = 0 ; j <= ranks.at(i) - 10 && j % 10 == 0; j = j + 10){
                cout << "*";
            }
            //complete the outputted string and endline
            cout << "-" << ranks.at(i) << endl;
            
            //increment year by 10
            yearIterator = yearIterator + 10;
        }
    } else {
        cout << name << " Not Found" << endl;
    }
    
}
/**compYear(int year, int namesToComp, NameSurferDataBase &database)
 * Option 2 - compare names by year
 * @param year - int
 * @param namesToComp - how many names are we comparing
 * @param database - again passeed by reference
 */
void compYear(int year, int namesToComp, NameSurferDataBase &database){
    string names[namesToComp];
    //Get the names
    int displayCounter = 1;
    for (int i = 0; i < namesToComp; i++){
        cout << "Enter name " << displayCounter << ":";
        cin >> names[i];
        fixName(names[i]);
        displayCounter++;
    }
    int yearRound = 10*(year/10);
    cout << "You selected the decade " << yearRound << endl;   	
    for (int i = 0 ; i < namesToComp; i++){
        
        //stick it into the nameEntry variable
        NameSurferEntry nameEntry = database.findEntry(names[i]);
        
        vector <int> ranks = nameEntry.getRankVec();
        
        cout << names[i] << "\t ";
        
        for (int j = 0 ; j < ranks.at(i) - 10 && j % 10 == 0; j = j + 10){
            
            cout << "*";
        }
        cout << "-" << nameEntry.getRank(year) << endl;
        
    }
}
    
/** fixName(name)
 *  helper function to correct the input of a name
 *  @param name - passed by reference
 */

void fixName(string &name){
    
    transform(name.begin(), name.end(), name.begin(), ::tolower); //makes everything lowercase
    name.at(0) = toupper(name.at(0)); //make first char uppercase if not already
    
    
}
    
    


