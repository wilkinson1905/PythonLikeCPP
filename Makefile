gcc_options = -std=c++17 -Wall --pedantic-error

program : main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run : program
	./program

100 : 100-A-PoisonousCookies.cpp all.h range.hpp all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

run100 : 100
	./100 < input.txt

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : run clean