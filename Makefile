CXX=g++
TARGET=Bookkeeping
SRC =$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))
CXXFLAGS= -c  -Wall
$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

%.o : %/cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)
