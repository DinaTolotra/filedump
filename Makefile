filedump:
	@echo "Building ..."
	@cc -Wall -Wextra -Werror -g main.c -o build/filedump

dir:
	@mkdir -p build

clean:
	@rm -r build
