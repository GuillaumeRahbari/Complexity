include default.mk

ALL = prog

prog : main.o 
	$(CXX_LINK) -o prog  main.o 

extra_all :
extra_clean :

Rectangle.o : Rectangle.h
main.o : main.cpp Rectangle.o