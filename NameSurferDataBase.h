/**
 * @author scoronado
 * @since 2019-03-23
 * NameSurferDataBase.h
 */

#ifndef NAMESURFER_DATABASE_H
#define NAMESURFER_DATABASE_H

#include <string>
#include "linked_list.h"
#include "NameSurferDataBase.h"
#include "NameSurferEntry.h"

using namespace std;

class NameSurferDataBase {

public:
    /** NameSurferDataBase()
     * Declares the definition of the NameSurferDataBase object containing an object and linked_list
     * @param filename - string containing the name of a file or path of a directory
     */
    NameSurferDataBase(string filename);
    
    
    /**
    * findEntry() - returns a NameSurferEntry from the linked_list database
    * @param name - the string of a person. This will only work well if input is 
    * corrected before passing here
    * @return temp - a NameSurferEntry value that will be returned by reference 
    * if search finds the entry
    */
    NameSurferEntry findEntry(string name);

private:
    
    
    /** NameSurferEntry linked_list
     *  where all of the entries will be held 
     */
    linked_list<NameSurferEntry> database;

}; 

#endif
