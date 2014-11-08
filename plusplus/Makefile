CXX = g++-4.9
SDL = -framework SDL2
# You may need to change -std=c++11 to std=c++0x if your compiler is a bit
# older
CXXFLAGS = -Wall -c -std=c++11 # -l /Library/Frameworks/SDL2.framework/Headers

LDFLAGS = $(SDL)
#LDFLAGS = $(SDL) -F /Library/Frameworks
EXE = template_test

all: $(EXE)

$(EXE): template_test.o
	$(CXX) $(LDFLAGS) $< -o $@

template_test.o: template_test.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
