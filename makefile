all:
	g++ src/main.cpp src/allocator.cpp -Iinclude -o main

clean:
	rm -f main

run:
	./main
