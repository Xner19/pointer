task1: task1.c
	gcc -o task1 task1.c
task2: task2.c
	gcc -o task2 task2.c
task3: task3.c
	gcc -o task3 task3.c
task4: task4.c
	gcc -o task4 task4.c
clean: 
	rm task1 task2 task3 task4 
