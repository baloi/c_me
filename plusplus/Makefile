CXX = g++-4.9
# You may need to change -std=c++11 to std=c++0x if your compiler is a bit
# older
CXXFLAGS = -Wall -c -std=c++11 # -l /Library/Frameworks/SDL2.framework/Headers

EXE = shuffle

all: $(EXE)

$(EXE): shuffle.o
	$(CXX) $< -o $@

shuffle.o: shuffle.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
