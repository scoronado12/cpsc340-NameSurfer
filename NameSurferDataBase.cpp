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

/** NameSurferDataBase()
 * Declares the definition of the NameSurferDataBase object containing an object and linked_list
 * @param filename - string containing the name of a file or path of a directory
 */


NameSurferDataBase::NameSurferDataBase(string filename){
    ifstream inputfile;
    //open file
    inputfile.open(filename);
    //check if open
    string line; // need not to declare the line at every for loop
    if(!inputfile.is_open()){
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
 /**
  * findEntry() - returns a NameSurferEntry from the linked_list database
  * @param name - the string of a person. This will only work well if input is 
  * corrected before passing here
  * @return temp - a NameSurferEntry value that will be returned by reference 
  * if search finds the entry
  */
NameSurferEntry NameSurferDataBase::findEntry(string name){
     NameSurferEntry temp = NameSurferEntry(name + " 0 0 0 0 0 0 0 0 0 0 0 0");
     //when true the database.Search() call will pass the temp variable by reference
    if(database.Search(temp)){
        return temp;
    } else {
        //if it didn't work
        return NameSurferEntry();
    }

}



#endif

