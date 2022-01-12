all: build


.PHONY: build run clean
	
build:
	@./scripts/build.sh

run:
	@./build/debug/bin/prolog

clean:
	@rm -rf build
	@rm -f demo.db3
