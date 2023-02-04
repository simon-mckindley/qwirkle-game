.default: all

all: clean compile run

clean:
	rm -rf qwirkle *.o *.dSYM

compile:
	g++ -Werror -std=c++14 -g *.cpp -o qwirkle

debug:
	g++ -Wall -Werror -std=c++14 -g *.cpp -o qwirkle

deps:
	cmake -S . -B build

run:
	./qwirkle

test:
	cmake --build build && ctest --test-dir build --output-on-failure

