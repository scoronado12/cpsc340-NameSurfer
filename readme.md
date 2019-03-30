# NameSurfer

Overview of the NameSurfer project

Against all bureaucratic stereotypes, the Social Security Administration provides a neat web site showing the distribution of names chosen for children over the last 100 years in the United States (http://www.ssa.gov/OACT/babynames/). The Social Security Administration provides data that shows the 1000 most popular boy and girl names for children at 10 year intervals. The data can be boiled down to a single text file that looks something like this:

NamesData.txt                                                

. . .

 

Sam 58 69 99 131 168 236 278 380 467 408 466 997

Samantha 0 0 0 0 0 0 272 107 26 5 7 63

Samara 0 0 0 0 0 0 0 0 0 0 886 0

Samir 0 0 0 0 0 0 0 0 920 0 798 0

Sammie 537 545 351 325 333 396 565 772 930 0 0 0

Sammy 0 887 544 299 202 262 321 395 575 639 755 0

Samson 0 0 0 0 0 0 0 0 0 0 915 0

Samuel 31 41 46 60 61 71 83 61 52 35 28 32

….

 

Each line of the file begins with the name, followed by the rank of that name in each of the 11 decades since 1900, counting the current one: 1900, 1910, 1920, and so on up to 2010. A rank of 1 indicates the most popular name that year, while a rank of 997 indicates a name that is not very popular. A 0 entry means the name did not appear in the top 1000 names for that year and therefore indicates a name that is even less popular. The elements on each line are separated from each other by a single space. The lines happen to be in alphabetical order, but nothing in the assignment depends on that fact.  I may use a different file that is not in order.

 

As you can see from the small excerpt from the file, the name Sam was #58 in the first decade of the 1900s and has since dropped to the bottom of the Top 1000 list. Samantha popped on the scene in the 1960s (possibly because the show Bewitched, which had a main character named Samantha, ran on television during those years) and was extremely popular ten years ago, but is now just very popular. Samir didn't even appear on the Top 1000 list until the 1980's. The database counts children born in the United States, so trends in particular names tend to reflect the evolution of ethnic communities over the years.  The star represent 1/10 of the total ranking so 58 prints out 5 stars, 69 prints out 6 stars

 

 

1:Enter a name to be searched.

2:Enter a year

3:Exit

Enter a choice:1

Enter in a name: sAm

Sam

1900*****-58

1910******-69

1920*********-99

1930*************-131

1940****************-168

1950***********************-236

1960***************************-278

1970**************************************-380

1980**********************************************-467

1990****************************************-408

2000**********************************************-466

2010***************************************************************************************************-997

 

 

1:Enter a name to be searched.

2:Enter a year

3:Exit

Enter a choice: 

 

The goal of this assignment is to create a program that graphs these names over time. In the sample out for a single name above, the user has just chose Sam as the name to display. Whenever the user enters a name, the NameSurfer program creates a new bar graph showing how that name has fared over the decades. (Note that the program is not case sensitive to the names that the user types into the “Name”. So, the user could enter “Samantha”, “SAMANTHA”, “samantha” or even “sAmAnThA” and the program would display the graph for the name "Samantha".)

To give you more experience working with classes that interact with one another, the NameSurfer

application as a whole is broken down into several class files, as follows:

    NameSurfer—This is the main program class that ties together the It is responsible for creating the other objects and for responding to the buttons at the bottom of the window, but only to the point of redirecting those events to the objects represented by the other classes.
    NameSurferEntry—This class ties together all the information for a particular Given a NameSurferEntry object, you can find out what name it corresponds to and what its popularity rank was in each decade.
    NameSurferDataBase—This class keeps track of all the information stored in the data files, but is completely separate from the user It is responsible for reading in the data and for locating the data associated with a particular implement the NameSurferEntry class

The NameSurferEntry class encapsulates the information pertaining to one name in the database. That information consists of two parts:

    The name itself, such as "Sam" or "Samantha"
    A vector of 12 values indicating the rank of that name in each of the decades from 1900 to 2010,

The class definition begins with a constructor that creates an entry from the line of data that appears in the NamesData.txtfile. For example, the entry for Sam looks like this:

 

 

Sam 58 69 99 131 168 236 278 380 467 408 466 997

 

 

 

class NameSurferEntry {

    friend ostream & operator<<(ostream &out, NameSurferEntry temp);

public:

    bool operator< (NameSurferEntry left);

    bool operator> (NameSurferEntry left);

    bool operator<= (NameSurferEntry left);

    bool operator>= (NameSurferEntry left);

    bool operator!= (NameSurferEntry left);

    bool operator== (NameSurferEntry left);

    NameSurferEntry();

    NameSurferEntry(string line);

    void setName(string name);

    string getName();

    int getRank(int year);

    bool empty();

   

private:

    vector<int>    rank;

    string        name;

   

};

Your program will start  by opening and reading the file into the linked list.  Then it will produce the following menu:

 

 

1:Enter a name to be searched.

2:Enter a year

3:Exit

Enter a choice:2

Enter a year:1970

Enter how many Names you want to compare:3

Enter name 1:Jennifer

Enter name 2:Peter

Enter name 3:Sam

You selected the decade 1970

Jennifer       -1

Peter          *****-55

Sam            **************************************-380

 

1:Enter a name to be searched.

2:Enter a year

3:Exit

Enter a choice: 

 

Implement the NameSurferDataBase class

The next step in the process is to implement the NameSurferDataBase class, which contains two public entries:

    A constructor that takes the name of a data file and uses that to read in the entire set of data from the file into internal data structures that allow the class to keep track of all the records as a
    A findEntry method that takes a name, looks it up in the stored database (note that your program should not be case sensitive regarding the name), and returns the NameSurferEntry for that name, or null if that name does not

 

 

class NameSurferDataBase {

public:

    NameSurferDataBase(string filename);

    NameSurferEntry findEntry(string name);

private:

    linked_list<NameSurferEntry> database;

}; 

 
 
IF YOUR LINKED LIST CLASS HAS ANY CODE THAT REFERS DIRECTLY TO THE NAMESURFER ENTRY OR NAMESURFERDATABASE YOU WILL GET A ZERO

 

Your Linked List Search method is the only method that must be changed.  You must pass value back by reference as discussed in class.

You output must match my output.  It will do an output test case.

 

REQUIRED FILES: Don’t use all files you will get a zero

    h
    cpp
    h
    cpp
    h
    cpp
    h
    cpp
    cpp
    Makefile

 

Must provide documentation in each file.
