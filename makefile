#.PHONY:double_list_app
double_list_app:libapp.a
	gcc -g -o double_list_app main.c -lapp -L.
libapp.a:double_list.o
	ar rcs libapp.a double_list.o
double_list.o:double_list.c double_list.h
	gcc -g -c -Wall double_list.c




#main:main.o double_list.o
#	gcc -o main -g *.o
#main.o:main.c double_list.h
#	gcc -g -c -Wall main.c
#double_list.o:double_list.c double_list.h
#	gcc -g -c -Wall double_list.c
.PHONY:clean
clean:
	rm *.o double_list_app
