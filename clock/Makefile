CXX = g++-4.9
SDL = -framework SDL2
# You may need to change -std=c++11 to std=c++0x if your compiler is a bit
# older
CXXFLAGS = -Wall -c -std=c++11 # -l /Library/Frameworks/SDL2.framework/Headers

LDFLAGS = $(SDL)
#LDFLAGS = $(SDL) -F /Library/Frameworks
EXE = clock

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
