.PHONY: help all clean

all: deanery student group # Build all targets

help: # Show help for each of the Makefile recipes.
	@printf "\n"
	@grep -E '^[a-z].*:.*'  Makefile | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done
	@printf "\n"

deanery: test_deanery.cpp # Build test_deanery file
	g++ -std=c++20 -Iinclude ../src/Deanary.cpp ../src/Group.cpp ../src/Student.cpp test_deanery.cpp -O3 -o test_deanery

student: test_student.cpp # Build test_student file
	g++ -std=c++20 -Iinclude ../src/Deanary.cpp ../src/Group.cpp ../src/Student.cpp test_student.cpp -O3 -o test_student

group: test_group.cpp # Build test_group file
	g++ -std=c++20 -Iinclude ../src/Deanary.cpp ../src/Group.cpp ../src/Student.cpp test_group.cpp -O3 -o test_group

clean: # Delete all builded files
	rm -f deanery student group 