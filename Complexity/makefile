include default.mk

ALL = prog

prog : main.o 
	$(CXX_LINK) -o prog  main.o Rectangle.o Boite.o Matrix.o Vector.o

extra_all :
extra_clean :

Matrix.o : Matrix.h Matrix.cpp
Vector.o : Vector.h Vector.cpp
Boite.o : Boite.h
Rectangle.o : Rectangle.h
main.o : main.cpp Rectangle.o Boite.o Matrix.o Vector.o