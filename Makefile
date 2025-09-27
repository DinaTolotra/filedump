cc_w_flag = -Wall -Wextra -Werror
source_dir = ./source/
include_dir = ./include/
build_dir = ./build/

filedump: build build/libio.a
	@echo "Building ..."
	@cc $(cc_w_flag) -o $(build_dir)/filedump -g main.c -lio -L$(build_dir)

build/libio.a: build/libio/io_output.o build/libio/io_input.o build
	@mkdir -p $(build_dir)libio/
	@ar -rcs $(build_dir)libio.a $(build_dir)libio/io_*.o

build/libio/io_output.o: build
	@mkdir -p $(build_dir)libio/
	@cc $(cc_w_flag) -o $(build_dir)libio/io_output.o -c $(source_dir)io_output.c -I$(include_dir)

build/libio/io_input.o: build
	@mkdir -p $(build_dir)libio/
	@cc $(cc_w_flag) -o $(build_dir)libio/io_input.o -c $(source_dir)io_input.c -I$(include_dir)

build:
	@mkdir -p $(build_dir)

clean:
	@rm -r $(build_dir)
