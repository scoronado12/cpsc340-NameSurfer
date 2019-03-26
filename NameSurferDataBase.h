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
    NameSurferDataBase(string filename);

    NameSurferEntry findEntry(string name);

private:

    linked_list<NameSurferEntry> database;

}; 

#endif
