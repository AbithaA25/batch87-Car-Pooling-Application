C= gcc
OBJS= main.o transporter.o commuter.o show_reports.o validations.o 
HDRS= structure.h

myprog: $(OBJS)
	$(C) -o myprog $(OBJS)
main.o: main.c
	$(C) -c main.c
transporter.o: transporter.c
	$(C) -c transporter.c
commuter.o: commuter.c
	$(C) -c commuter.c
show_reports.o: show_reports.c
	$(C) -c show_reports.c
validations.o: validations.c
	$(C) -c validations.c

$(OBJS): $(HDRS)

clean: 
	rm *.o 


