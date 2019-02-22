CXX = g++-8 -g -Wall -Wextra -std=c++17 -pedantic-errors


DEP_FLAGS = -MMD -MP

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

TARG = Przyklad

all: $(TARG)

$(TARG): $(OBJ)
	$(CXX) $^$(LFLAGS) -o $@

$(OBJ) : $(SRC)
	$(CXX) -c $(SRC) $(DEP_FLAGS)

.PHONY: clean

clean:
	rm $(OBJ) $(TARG) $(DEP)

class:
	read -p "Enter Class Name:" name; \
	touch $$name.cpp; \
	printf "#include \""$$name.h"\"\n" > $$name.cpp; \
	touch $$name.h; \
	printf "#ifndef "$$name"_h\n#define "$$name"_h\n\nclass "$$name"{\npublic:\n\nprivate:\n\n};\n\n\n\n#endif" > $$name.h

-include $(DEP)
