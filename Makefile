.PHONY: run
run: CMakeLists.txt build
	cd build && cmake .. && make -s
	./build/supowit input output

.PHONY: clean
clean:
	rm -r build/*

build:
	mkdir build
