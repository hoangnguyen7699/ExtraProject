OBJ = main.o store.o process.o screen.o 
APPNAME = a.out

#math library is used
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm   

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(APPNAME) $(OBJ)




