
/**
 * @author scoronado
 * @since 2019-03-20
 * NameSurferEntry.h
 */

#ifndef NAME_SURFER_ENTRY_H
#define NAME_SURFER_ENTRY_H
#include <string>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class NameSurferEntry {
    
    
    /**
    * Overloading ostream out to be able to print contents of a single node
    */
    friend ostream & operator<<(ostream &out, NameSurferEntry temp);

public:
    
    //Overloading Operators to compare two different NameSurferEntries    
    friend bool operator< (NameSurferEntry left, NameSurferEntry right);
    friend bool operator> (NameSurferEntry left, NameSurferEntry right);
    friend bool operator<= (NameSurferEntry left, NameSurferEntry right);
    friend bool operator>= (NameSurferEntry left, NameSurferEntry right);
    friend bool operator!= (NameSurferEntry left, NameSurferEntry right);
    friend bool operator== (NameSurferEntry left, NameSurferEntry right);
    /**
    * NameSurferEntry() - default constructor
    * Initializes a name called "Default"
    * Vector will be empty
    */
    NameSurferEntry();
    
    /**
    * NameSurferEntry
    * @param line - from a text file
    * Text lines pumped in here become one of many NSE objects.
    */
    NameSurferEntry(string line);
    /**
     * setName
     * @param name - a string
     * Changes the name of a given object instance 
     */
    void setName(string name);
    
    /**
    * getName
    * @returns name - the name of a refernced object instance
    */
    string getName();
    
    /**getRank
     * @param year - int
     * @return rank of the given param
     */
    
    int getRank(int year);
    
    /**
    * getRankVec - helper function
    * @return rank - helps make the vector accessible outside the class
    */
    
    vector<int> getRankVec();
    
    /** empty
     *  @return
     */
    
    bool empty();

private:
    //vector containing the rank of the given year
    vector<int> rank;
    //names in database
    string name;

};

#endif
