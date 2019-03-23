
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

    friend ostream & operator<<(ostream &out, NameSurferEntry temp);

public:
    bool operator< (NameSurferEntry left, NameSurferEntry right);
    bool operator> (NameSurferEntry left, NameSurferEntry right);
    bool operator<= (NameSurferEntry left, NameSurferEntry right);
    bool operator>= (NameSurferEntry left, NameSurferEntry right);
    bool operator!= (NameSurferEntry left, NameSurferEntry right);
    bool operator== (NameSurferEntry left, NameSurferEntry right);
    
    NameSurferEntry();
    NameSurferEntry(string line);
    void setName(string name);
    string getName();
    int getRank(int year);
    bool empty();

private:
    vector<int> rank;
    string name;

};

#endif
