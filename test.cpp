#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "NameSurferDataBase.h"
#include "gtest/gtest.h"

using namespace std;

TEST(neno_mimir_test, getRank){


	NameSurferDataBase db("NamesData.txt");
	NameSurferEntry temp;
	
	temp = db.findEntry("Jennifer");

	ASSERT_EQ(temp.getRank(1940),210);


}
TEST(neno_mimir_test, findEntry){

	NameSurferDataBase db("NamesData.txt");

	NameSurferEntry temp;

	temp = db.findEntry("Jennifer");

	ASSERT_FALSE(temp.empty());


}

TEST(neno_mimir_test, Not_Found_Entry){
	
	NameSurferDataBase db("NamesData.txt");

	NameSurferEntry temp;
	temp = db.findEntry("None");

	ASSERT_TRUE(temp.empty());
}

TEST(neno_mimir_test, getRank_ASHLEY){
	NameSurferDataBase database("NamesData.txt");
	
	NameSurferEntry temp;
	
	temp = database.findEntry("Ashley");
	
	ASSERT_EQ(temp.getRank(1990),1);

}
TEST(neno_mimir_test, get_rank_Bobbye){
	NameSurferDataBase database("NamesData.txt");
	
	NameSurferEntry temp;
	
	temp = database.findEntry("Bobbye");
	
	ASSERT_EQ(temp.getRank(1930),687);

}

int main (int argc, char** argv){

	::testing ::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//g++ test.cpp -lgtest
