TARGETS = echo-client echo-server
OBJS = csapp.o

all: $(TARGETS)

echo-client: echo-client.o $(OBJS)
	gcc -o echo-client echo-client.o $(OBJS) -lpthread

echo-server: echo-server.o $(OBJS)
	gcc -o echo-server echo-server.o $(OBJS) -lpthread

%.o: %.c
	gcc -c $<

clean:
	rm -f *.o
	rm -f $(TARGETS)