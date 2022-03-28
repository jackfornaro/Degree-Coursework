## Lab08 Makefile

CFLAGS = -Wall -Werror -g 
CC     = gcc $(CFLAGS)
SHELL  = /bin/bash
CWD    = $(shell pwd | sed 's/.*\///g')

PROGRAMS = \
	order3_c \
	order3_asm \


all: $(PROGRAMS)

help :
	@echo 'Typical usage is:'
	@echo '  > make                          # build all programs'
	@echo '  > make clean                    # remove all compiled items'
	@echo '  > make zip                      # create a zip file for submission'
	@echo '  > make test                     # run all automated tests'
	@echo '  > make clean-tests              # remove all test results'
	@echo 'NOTE: there is onlye ONE automated test but it tests several things about the program'

############################################################
# 'make zip' to create zip file for submission
AN=lab08
zip : clean clean-tests
	rm -f $(AN)-code.zip
	cd .. && zip "$(CWD)/$(AN)-code.zip" -r "$(CWD)"
	@echo Zip created in $(AN)-code.zip
	@if (( $$(stat -c '%s' $(AN)-code.zip) > 10*(2**20) )); then echo "WARNING: $(AN)-code.zip seems REALLY big, check there are no abnormally large test files"; du -h $(AN)-code.zip; fi
	@if (( $$(unzip -t $(AN)-code.zip | wc -l) > 256 )); then echo "WARNING: $(AN)-code.zip has 256 or more files in it which may cause submission problems"; fi

order3_c : order3_c.c
	$(CC) -o $@ $^

order3_asm : order3_asm.s
	$(CC) -o $@ $^

test-setup :
	@chmod u+rx testy

test : test-setup order3_asm
	./testy test_order3_asm.org $(testnum)

clean:
	rm -f *.o $(PROGRAMS)

clean-tests:
	rm -rf test-results/

