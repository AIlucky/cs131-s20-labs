# CSCI 1310 Lab 3 Makefile

# Standard C compiler
CC := gcc

# Regular compilation flags
CFLAGS := -O0 -g -std=c99 -Wall -Werror -Wno-deprecated-declarations # Flags for C compilation

# Compilation flags that ensure that the stack is static and with no security measures.
# Modern compilers and operating systems work hard to prevent buffer overflow attacks from
# succeeding, and we're disabling their safeguards here!
# -fno-stack-protector: remove special memory on the stack that is checked for corruption
#                       before function returns
# -no-pie: no position-independent code; avoid OS randomizing the location of the hack() function
# -no-pic: no position-independent code; see above
# -z execstack: allow executing data on the stack (whoooo, sooo EVIL)
# -z norelro: stops the compiler from reordering memory sections to avoid overflows on global
#             variables
# Not all of these are needed for the lab, but the list illustrates just how much effort has
# gone into defeating these attacks!
STACKFLAGS := -Wno-implicit -fno-stack-protector -no-pie -fno-pic -z execstack -z norelro

# rules that are listed as .PHONY do not produce an output file
.PHONY: all do_hack clean

all: buffer exploit

# Compile the hackable buffer program
buffer: buffer.c
	$(CC) $(CFLAGS) $(STACKFLAGS) -o $@ $^
	@ objdump -d $@ > buffer_asm.txt

# Compile the exploit printing program
exploit: exploit.c
	$(CC) $(CFLAGS) -o $@ $^

# Dump contents of exploit to file
exploit_text1: exploit
	@ ./exploit > exploit1.txt

exploit_text2: exploit
	@ ./exploit > exploit2.txt

# Pipe output of exploit printing program into buffer program
do_hack: buffer
	@ echo "Testing Buffer ... "
	./exploit | ./buffer


clean:
	@ rm -rf buffer exploit exploit1.txt  exploit2.txt buffer_asm.txt
