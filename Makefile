all:
	@./scripts/build.sh

run:
	@./build/debug/bin/prolog

clean:
	@rm -rf build
