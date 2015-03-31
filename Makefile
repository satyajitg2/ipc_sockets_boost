CC=g++
REMOVE=rm
CFLAGS=-c -std=gnu++11 -Wall
STDLAGS=-std=gnu++11 
LDFLAGS=-lboost_system -pthread
SOURCES=tcp_client.cpp IPC_directory.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ipc_server
EXE=tcp_client

all: $(SOURCES) $(EXECUTABLE) $(EXE)

clean: $(OBJECTS)
	$(REMOVE) $(OBJECTS)

$(EXECUTABLE): $(SOURCES) 
	$(CC) -o $@ IPC_directory.cpp $(STDLAGS) $(LDFLAGS) 

$(EXE): $(SOURCES) 
	$(CC) -o $@ tcp_client.cpp $(STDLAGS) $(LDFLAGS)  
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

