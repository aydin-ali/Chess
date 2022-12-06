CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = bishop.o board.o computer.o computerL1.o computerL2.o game.o graphicDisplay.o human.o king.o knight.o main.o move.o pawn.o piece.o playerType.o position.o queen.o rook.o subject.o textDisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}



