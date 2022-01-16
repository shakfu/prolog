all: build


.PHONY: build run clean
	
build:
	@./scripts/build.sh

run: build
	@./build/debug/bin/prolog -d

format:
	@find ./src/ -iname *.h -o -iname *.cpp | xargs clang-format -i
	@find ./tests/ -iname *.h -o -iname *.cpp | xargs clang-format -i

clean:
	@rm -rf build
	@rm -f demo.db3
