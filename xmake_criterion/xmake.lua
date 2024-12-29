set_rundir(os.projectdir())

add_rules("mode.debug", "mode.release")

set_languages("clatest")

target("xmake_criterion")
set_kind("binary")
add_files("src/*.c")

target("tests")
set_default(false)
set_kind("binary")
add_files("src/*.c")
remove_files("src/main.c")
add_includedirs("src")
add_files("test/*.c")
add_links("criterion") -- -lcriterion
add_linkdirs("/opt/homebrew/lib")
add_includedirs("/opt/homebrew/include")
