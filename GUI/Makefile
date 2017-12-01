#
# Makefile
#
# Oussema Hidri
# d.oussema.d@gmail.com
#

all: bounce label

bounce: bounce.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o bounce bounce.c -lcs -lm
label: label.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o label label.c -lcs -lm
