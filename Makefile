all:
	g++ inputWizard.cpp inputWizard.h manager.h -o program
	
	./program
clean:
	rm program