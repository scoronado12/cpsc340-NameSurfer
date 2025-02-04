
/**
 * @author scoronado
 * @since 2019-03-20
 * NameSurferEntry.cpp
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

/**
 * NameSurferEntry() - default constructor
 * Initializes a name called "Default"
 * Vector will be empty
 */

NameSurferEntry::NameSurferEntry(){
    this -> name = "Default";
    
    //vector is empty
}

/**
 * NameSurferEntry
 * @param line - from a text file
 * Text lines pumped in here become one of many NSE objects.
 */

NameSurferEntry::NameSurferEntry(string line){
    //play with string
    string lineVals[13];
    
    stringstream LineIn(line);
    
    for (int i = 0; LineIn.good() && i <= 14; i++){
        LineIn >> lineVals[i];
        //commented out for less verboseness
         //cout << lineVals[i] << endl;
    }
    //clear LineIn so there's no wierdness going on later down the line
    LineIn.clear();
    
    try{
        this-> name = lineVals[0]; //This declares the name in the object
        for (int i = 1; i <= 12; i++){
            rank.push_back(stoi(lineVals[i])); // insert array into vector
        }
    } catch (const exception& e){
        //nothing happens
    }
    
}


/**
 * setName()
 * @param name - a string
 * Changes the name of a given object instance 
 */

void NameSurferEntry::setName(string name){
    this -> name = name;
}

/**
 * getName())
 * @returns name - the name of a refernced object instance
 */

string NameSurferEntry::getName(){
    return this -> name;
}

/**
 * getRank
 * @param year - into
 * for the year passed, the corresponding value in the vector will be returned
 * @returns a number inside the rank vector
 */


int NameSurferEntry::getRank(int year){
    
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
    } else if (year >= 2010 && year <= 2010){
        return rank.at(11);
    } else {
        return 0;
    }
    
}

/**
 * getRankVec - helper function
 * @return rank - helps make the vector accessible outside the class
 */

vector<int> NameSurferEntry::getRankVec(){
    return this -> rank;
}

/** empty
 * @return true if the rank vector is empty
 */

bool NameSurferEntry::empty(){
    
    return this -> rank.empty();
    
}



//Overloading Operators to compare two different NameSurferEntries

bool operator < (NameSurferEntry left, NameSurferEntry right){
    return left.getName() < right.getName();
}

bool operator > (NameSurferEntry left, NameSurferEntry right){
    return left.getName() > right.getName();
}

bool operator <= (NameSurferEntry left, NameSurferEntry right){
    return left.getName() <= right.getName();
}

bool operator >= (NameSurferEntry left, NameSurferEntry right){
    return left.getName() >= right.getName();
}

bool operator != (NameSurferEntry left, NameSurferEntry right){
    return left.getName() != right.getName();
}

bool operator == (NameSurferEntry left, NameSurferEntry right){
    return left.getName() == right.getName();
}

/**
 * Overloading ostream out to be able to print contents of a single node
 */
ostream & operator << (ostream &out, NameSurferEntry temp){
    
    out << "Name: "<< temp.getName() << endl;
    out << "Values: ";
    
    
    for (int i = 1910; i <= 2010; i = i + 10){
        out << i << ":" << temp.getRank(i) << endl;
        
    }
    
    return out;
}




#endif
