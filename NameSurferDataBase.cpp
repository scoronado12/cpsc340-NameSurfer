/**
 * @author scoronado
 * @since 2019-03-23
 * NameSurferDataBase.cpp
 */

#ifndef NAMESURFER_DATABASE_CPP
#define NAMESURFER_DATABASE_CPP
#include <fstream>
#include <iostream>
#include <string>
#include "linked_list.h"
#include "NameSurferEntry.h"
#include "NameSurferDataBase.h"

using namespace std;


NameSurferDataBase::NameSurferDataBase(string filename){
    
    ifstream inputfile;
    //open file
    inputfile.open(filename);
    
    //check if open
    
    string line; // need not to declare the line at every for loop
    if(!inputfile.is_open()){
        cout << "Not Open" << endl;
        exit(1);
    } else {
        while (!inputfile.eof()){
            getline(inputfile, line);
            if (inputfile.eof()){
                inputfile.close();
                break;
            } else {
                NameSurferEntry entry  = NameSurferEntry(line);
                database.InsertInOrder(entry);
            }
            
        }
        
        //Debug statements - commented out for less verboseness
        //cout << "Print All" << endl;
        //database.PrintAll();
        
        inputfile.close();
    }

    
}
 //TODO findEntry
 
 /**
  * findEntry() - returns a NameSurferEntry from the linked_list database
  */
 
NameSurferEntry NameSurferDataBase::findEntry(string name){
    NameSurferEntry temp = NameSurferEntry(name);
//     database.Search(temp);
    //TODO add if block that is able to detect whether or not the search was successful
    return temp;
}



#endif

