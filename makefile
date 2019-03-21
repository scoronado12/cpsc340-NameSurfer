a.out: main.cpp single_node.o linked_list.o nameSurfer.o
	g++ main.cpp single_node.o linked_list.o nameSurfer.o
nameSurfer.o: nameSurfer.cpp
	g++ -c nameSurfer.cpp
linked_list.o: linked_list.cpp
	g++ -c linked_list.cpp
single_node.o: single_node.cpp
	g++ -c single_node.cpp
clean:
	rm -f *.o *gch a.out
