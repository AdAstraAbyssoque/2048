all: build/cli_2048 build/gui_2048

.PHONY: create_dir clean

create_dir:
	mkdir -p build

build/cli_2048: create_dir core-2048/core_2048.hpp cli-2048/2048_cli.cpp
	g++ cli-2048/2048_cli.cpp -o build/cli_2048 

build/gui_2048: create_dir core-2048/core_2048.hpp gui-2048/main.cpp gui-2048/mainwindow.cpp
	cd gui-2048 && qmake gui_2048.pro && make

clean:
	rm -rf build
	cd gui-2048 && make clean
	cd gui-2048 && rm -f Makefile
