## Lab07 Makefile

CFLAGS = -Wall -Werror -g 
CC     = gcc $(CFLAGS)
SHELL  = /bin/bash
CWD    = $(shell pwd | sed 's/.*\///g')

all: coins_main

help :
	@echo 'Typical usage is:'
	@echo '  > make                          # build all programs'
	@echo '  > make clean                    # remove all compiled items'
	@echo '  > make zip                      # create a zip file for submission'
	@echo '  > make test                     # run all automated tests'
	@echo '  > make clean-tests              # remove all test results'
	@echo 'NOTE: there is onlye ONE automated test but it tests several things about the program'
	@echo '  > make coins_hybrid             # build the combined C/assembly program'
	@echo '  > make test-hybrid              # run tests on the hybrid executable'

############################################################
# 'make zip' to create zip file for submission
AN=lab07
zip : clean clean-tests
	rm -f $(AN)-code.zip
	cd .. && zip "$(CWD)/$(AN)-code.zip" -r "$(CWD)"
	@echo Zip created in $(AN)-code.zip
	@if (( $$(stat -c '%s' $(AN)-code.zip) > 10*(2**20) )); then echo "WARNING: $(AN)-code.zip seems REALLY big, check there are no abnormally large test files"; du -h $(AN)-code.zip; fi
	@if (( $$(unzip -t $(AN)-code.zip | wc -l) > 256 )); then echo "WARNING: $(AN)-code.zip has 256 or more files in it which may cause submission problems"; fi

coins_main : coins_main.c coins_funcs_asm.s
	$(CC) -o $@ $^

coins_hybrid : coins_main.c coins_funcs_asm.s coins_funcs.c
	$(CC) -o $@ $^

test-setup :
	@chmod u+rx testy

test : test-setup coins_main
	./testy test_coins_main.org $(testnum)

test-hybrid : test-setup coins_hybrid
	./testy test_coins_hybrid.org $(testnum)
	@echo
	@echo "WARNING: These are the hybrid tests used for incremental development."
	@echo "         Make sure to run 'make test' to run the full tests before submitting."

clean:
	rm -f *.o coins_main coins_hybrid

clean-tests:
	rm -rf test-results/

