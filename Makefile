CXX=g++
CXXFLAGS=-Wall -MMD
OBJECTS= main.o board.o block.o tile.o building.o gym.o player.o residence.o acBuilding.o vector.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=bb7k
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
