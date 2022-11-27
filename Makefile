CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -I /include
EXEC = Chess
OBJECTS = main.o game.o 
DEPENDS = ${OBJECTS:.o=.d}

VPATH=src:include

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

