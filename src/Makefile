CFLAGS?=-O2 -g -Wall -W 
LDLIBS+=-liio -lpthread -lm -lad9361
PROGNAME=radar-app

all: radar-app

%.o: %.c
	$(CC) $(CFLAGS) -c $<

radar-app: radar-app.o header_test.o
	$(CC) -g -o radar-app radar-app.o header_test.o $(LDFLAGS) $(LDLIBS)

clean:
	rm -f *.o 
