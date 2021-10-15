# COMPILER
CC = clang++

# FLAGS
CPPFLAGS = -std=c++17 -fsanitize=address -fsanitize=undefined -pipe -O2 -Wall -Werror

# COMPILED FILE NAME
CMPFILENAME = auto-iter-code-check-0



# EXECUTABLE FILE NAME
EXENAME = output

all: input

input: $(CMPFILENAME)
	./$(EXENAME)

$(CMPFILENAME): $(CMPFILENAME).o
	$(CC) $(CPPFLAGS) $(CMPFILENAME).o -o $(EXENAME)

# PATTERN: file.o: file.cpp  file.h other_header.h
$(CMPFILENAME).o: $(CMPFILENAME).cpp
	$(CC) -c $(CPPFLAGS) $(CMPFILENAME).cpp

clear:
	rm -rf *o && rm -rf $(EXENAME)
