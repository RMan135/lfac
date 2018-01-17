INCLUDE_DIR=./src
PROGRAM_NAME=gin

build/index: lex.yy.c types.h process.c process.h tree.c tree.h ${PROGRAM_NAME}.tab.h ${PROGRAM_NAME}.tab.c
	gcc -ggdb -std=gnu99 process.c tree.c ${PROGRAM_NAME}.tab.c lex.yy.c -ll -ly -o build/index

lex.yy.c: ${PROGRAM_NAME}.l
	lex ${PROGRAM_NAME}.l


${PROGRAM_NAME}.tab.h: ${PROGRAM_NAME}.y
	bison ${PROGRAM_NAME}.y -d -v

${PROGRAM_NAME}.tab.c: ${PROGRAM_NAME}.y
	bison ${PROGRAM_NAME}.y -v

clean:
	rm -rf build
