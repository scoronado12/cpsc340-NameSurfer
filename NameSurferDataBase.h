#ifndef NAMESURFER_DATABASE_H
#define NAMESURFER_DATABASE_H
#include "linked_list.h"
#include "NameSurferEntry.h"

class NameSurferDataBase {

public:

    NameSurferDataBase(string filename);

    NameSurferEntry findEntry(string name);

private:

    linked_list<NameSurferEntry> database;

}; 

#endif
