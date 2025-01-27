all: list_test door_struct stack_test

stack_test: stack.o stack_test.o
	gcc -Wall -Werror -Wextra -std=c11 -o ../build/Quest_3 stack.c stack_test.o

stack.o: stack.c stack.h
	gcc -Wall -Werror -Wextra -std=c11 -c stack.c -o stack.o

stack_test.o: stack.c stack.h
	gcc -Wall -Werror -Wextra -std=c11 -c stack_test.c -o stack_test.o

list_test: list.o list_test.o
	gcc -Wall -Werror -Wextra -std=c11 -o ../build/Quest_2 list.o list_test.o

list.o: list.c list.h door_struct.h
	gcc -Wall -Werror -Wextra -std=c11 -c list.c -o list.o

list_test.o: list_test.c list.h door_struct.h
	gcc -Wall -Werror -Wextra -std=c11 -c list_test.c -o list_test.o

door_struct: dmanager_module.c
	gcc -Wall -Werror -Wextra -std=c11 dmanager_module.c -o ../build/Quest_1

clean:
	rm -f *.o ../build/Quest_2 ../build/Quest_1 ../build/Quest_3