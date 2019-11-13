#Creates simple.exe from the stated object files. The object files are created below.
simple.exe: main.o f1.o f2.o f3.o f4.o 
	gcc -o simple.exe main.o f1.o f2.o f3.o f4.o #Always use tabs not spaces

#This does all of the below
#%.o: %.c 
	#gcc -c $<

#Create object files
main.o: main.c
	@echo 'gcc -c $<'
	gcc -c $< #$< just means main.c here

f1.o: f1.c
	@echo 'gcc -c $<'
	gcc -c $<

f2.o: f2.c
	@echo 'gcc -c $<'
	gcc -c $<

f3.o: f3.c
	@echo 'gcc -c $<'
	gcc -c $<

f4.o: f4.c
	@echo 'gcc -c $<'
	gcc -c $<

clean: 
	rm *.o *.exe #Remove all object files and exe files
