CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o controller.o game.o player.o textdisplay.o ./buildings/academic.o ./buildings/building.o ./buildings/coopfee.o ./buildings/dctims.o ./buildings/goosenesting.o ./buildings/gototims.o ./buildings/gym.o ./buildings/needleshall.o ./buildings/nonproperty.o ./buildings/osap.o ./buildings/property.o ./buildings/residence.o ./buildings/slc.o ./buildings/tuition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
