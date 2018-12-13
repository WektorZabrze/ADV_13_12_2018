CXX=g++-8
CXX+=-std=c++17
MAIN=$(shell basename $(CURDIR))
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
NAMES=$(SRC:.cpp=)

all: $(MAIN)

$(MAIN): $(OBJ)
		$(CXX) $? -o $@

$(OBJ): $(SRC)
		$(CXX) -c $*.cpp -o $@

$(NAMES): $(SRC)
		$(CXX) $@.cpp -o $@


.PHONY: clean

clean:
	rm -f $(MAIN) $(OBJ) $(NAMES)

run: $(MAIN)
	./$(MAIN)

backup:
	if [ -d "./backup" ]; then rm -r backup; fi
	mkdir backup
	cp $(SRC) backup
	cp *.h backup