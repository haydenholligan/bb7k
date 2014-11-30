CXX=g++
CXXFLAGS=-Wall -MMD
OBJECTS=main.o lone.o unary.o binary.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q2
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
clean:
	rm ${OBJECTS} {$DEPENDS} {EXEC}
