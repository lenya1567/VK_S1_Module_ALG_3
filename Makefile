target:
	g++ -std=c++11 ./main.cpp ./igraph.h ./list_graph.h ./list_graph.cpp ./matrix_graph.h ./matrix_graph.cpp \
		./arc_graph.h ./arc_graph.cpp ./set_graph.h ./set_graph.cpp && ./a.out