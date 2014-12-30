include default.mk

ALL = prog

prog : main.o 
	$(CXX_LINK) -o prog  main.o Rectangle.o Boite.o

extra_all :
extra_clean :

Boite.o : Boite.h
Rectangle.o : Rectangle.h
main.o : main.cpp Rectangle.o Boite.o