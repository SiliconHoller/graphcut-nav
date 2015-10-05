COMPILER = arm-none-eabi-gcc -std=c99
COPTS = -O0 -g3 -Wall -save-temps
CCFLAGS = -c -fmessage-length=0

all: edge edgequeue graphmgt vstack

vstack: vstack.h vstack.c
	$(COMPILER) $(COPTS) $(CCFLAGS) -o vstack.o vstack.c	

edgequeue: edge.o edgequeue.c edgequeue.h
	$(COMPILER) $(COPTS) $(CCFLAGS) -o edgequeue.o edgequeue.c

edge: edge.h edge.c
	$(COMPILER) $(COPTS) $(CCFLAGS) -o edge.o edge.c

graphmgt: ugraph.h graphmgt.c graphmgt.h edge.o
	$(COMPILER) $(COPTS) $(CCFLAGS) -o graphmgt.o graphmgt.c

dstructs: edgequeue.o vstack.o 

	

clean:
	rm -f *.o *~ *.s
