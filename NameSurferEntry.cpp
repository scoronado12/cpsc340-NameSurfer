
/**
 * @author scoronado
 * @since 2019-03-20
 * NameSurferEntry.h
 */

#ifndef NAME_SURFER_ENTRY_CPP
#define NAME_SURFER_ENTRY_CPP
#include <string>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>
#include "NameSurferEntry.h"


using namespace std;

NameSurferEntry::NameSurferEntry(){
    name = "Default";
    //vector should be all zeros here
}

NameSurferEntry::NameSurferEntry(string line){
    //play with string
    string lineVals[13];
    
    stringstream LineIn(line);
    int i = 0;
    while (LineIn.good() && i <= 13){
        LineIn >> lineVals[i];
        i++;
    }
    LineIn.clear();
    this-> name = lineVals[0]; //NOTICE This declares the string in the object
    int j = 0;
    for (int i = 1; i <= 13; i++){
        //TODO Add to rank vector
        rank.at(j) = stoi(lineVals[i]); //NOTICE this places the ranks in order
        j++;
    }
    
    
}

void NameSurferEntry::setName(string name){
    this -> name = name;
}

string NameSurferEntry::getName(){
    return name;
}

int NameSurferEntry::getRank(int year){
    //TODO get year from vector
    
    if (year >= 1900 && year <= 1909){
        return rank.at(0);
    } else if (year >= 1910 && year <= 1919){
        return rank.at(1);
    } else if (year >= 1920 && year <= 1929){
        return rank.at(2);
    } else if (year >= 1930 && year <= 1939){
        return rank.at(3);
    } else if (year >= 1940 && year <= 1949){
        return rank.at(4);
    } else if (year >= 1950 && year <= 1959){
        return rank.at(5);
    } else if (year >= 1960 && year <= 1969){
        return rank.at(6);
    } else if (year >= 1970 && year <= 1979){
        return rank.at(7);
    } else if (year >= 1980 && year <= 1989){
        return rank.at(8);
    } else if (year >= 1990 && year <= 1999){
        return rank.at(9);
    } else if (year >= 2000 && year <= 2009){
        return rank.at(10);
    } else if (year >= 2010 && year <= 2019){
        return rank.at(11);
    } else {
        cout << "NOT FOUND" << endl;
        return 0;
    }
    
    
//     return rank;
}

//Overloading Operators to compare two different NameSurferEntries
bool operator >= (NameSurferEntry left, NameSurferEntry right){
    
    
    
}




#endif
