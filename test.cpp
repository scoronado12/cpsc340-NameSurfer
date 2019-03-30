#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "NameSurferDataBase.h"
#include "gtest/gtest.h"

using namespace std;

TEST(NSE, GET_RANK){


	NameSurferDataBase db("NamesData.txt");
	NameSurferEntry temp;
	
	temp = db.findEntry("Jennifer");

	ASSERT_EQ(temp.getRank(1940),210);


}

int main (int argc, char** argv){

	::testing ::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//g++ test.cpp -lgtest
