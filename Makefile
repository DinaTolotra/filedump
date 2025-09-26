build:
	@echo "Building ..."
	@cc -Wall -Wextra -Werror main.c -o build/filedump

dir:
	@mkdir -p build
