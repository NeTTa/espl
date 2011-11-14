# Tool invocations
# Executable "complines" depends on the files complines.o and run.o.
complines: bin/complines.o
	@echo 'Building target: complines'
	@echo 'Invoking: C Linker'
	gcc -o complines bin/complines.o
	@echo 'Finished building target: complines'
	@echo ' '

# Depends on the source and header files
bin/complines.o: src/Run.c
	gcc -g -Wall -c -o bin/complines.o src/Run.c

#Clean the build directory
clean: 
	rm -rf bin/*