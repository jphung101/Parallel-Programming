CC = g++
ompPath = $(shell brew --prefix libomp)
CFLAGS = -Xpreprocessor -fopenmp 
LDFLAGS = -lomp -L$(ompPath)/lib

all: main.cpp 
	$(CC) $(CFLAGS) main.cpp -o omp $(LDFLAGS)
clean:
	rm -rf omp