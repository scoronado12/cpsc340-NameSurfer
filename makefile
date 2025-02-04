a.out: main.cpp single_node.o linked_list.o NameSurferEntry.o NameSurferDataBase.o 
	g++ -g main.cpp single_node.o linked_list.o NameSurferDataBase.o NameSurferEntry.o
NameSurferEntry.o: NameSurferEntry.cpp
	g++ -c NameSurferEntry.cpp
NameSurferDataBase.o: NameSurferDataBase.cpp
	g++ -c NameSurferDataBase.cpp
linked_list.o: linked_list.cpp
	g++ -c linked_list.cpp
single_node.o: single_node.cpp
	g++ -c single_node.cpp
clean:
	rm -f *.o *gch vgcore.* a.out gtest
idungoofed: # some shorthand to make again
	make clean && make

gtest:
	g++ -g test.cpp single_node.o linked_list.o NameSurferDataBase.o NameSurferEntry.o -lgtest -o gtest
