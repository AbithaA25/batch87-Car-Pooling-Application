C= gcc
OBJS= main.o transporter.o commuter.o show_reports.o validations.o 


myprog: $(OBJS)
	$(C) -o ../bin/myprog ../obj/main.o ../obj/transporter.o ../obj/commuter.o ../obj/show_reports.o ../obj/validations.o
main.o: ../src/main.c
	$(C) -c ../src/main.c -o ../obj/main.o
transporter.o: ../src/transporter.c
	$(C) -c ../src/transporter.c -o ../obj/transporter.o
commuter.o: ../src/commuter.c
	$(C) -c ../src/commuter.c -o ../obj/commuter.o
show_reports.o: ../src/show_reports.c
	$(C) -c ../src/show_reports.c -o ../obj/show_reports.o
validations.o: ../src/validations.c
	$(C) -c ../src/validations.c -o ../obj/validations.o


clean: 
	rm *.o 



