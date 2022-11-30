CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla -I /include
EXEC = Chess
SRC = $(shell find src/ -name "*.cc")
HEADERS = $(shell find src/ -name "*.h")
OBJECTS = $(SRC:%.cc=%.o)
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}


