cc_flags := "-std=c2x -Wall"
libs := "-Iinclude/ -Isrc/"
build_folder := "./build"
program_name := "dumb_example"
bin := build_folder / program_name

default: run

run: build
    {{ bin }}

build: init
    cc {{ cc_flags }} {{ libs }} -g -O0 src/*.c main.c -o {{ bin }}

release: init
    cc {{ cc_flags }} {{ libs }} -O3 src/*.c main.c -o {{ bin }}

@init:
    mkdir -p build/

clean:
    rm -rf build/

dev:
    watchexec -e c,h just run

open:
    gh repo view --web

debug: build
    sudo lldb -- {{ bin }}

@test:
    cc {{ cc_flags }} {{ libs }} src/*.c test/*.c -o build/tests && build/tests
