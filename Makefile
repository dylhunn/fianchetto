CFLAGS = -O0 -Weverything -Wno-padded -Wno-unused-parameter -Wno-unused-variable -Wno-sign-conversion -ggdb
all: fianchetto.o util.o ttable.o movegen.o
	clang $(CFLAGS) $^ -o fianchetto
clean:
	rm fianchetto
	rm *.o
	rm *.gch
	rm -rf fianchetto.dSYM
%.o: %.c
	clang -c $(CFLAGS) $< -o $@
fianchetto.o: fianchetto.c
ttable.o: ttable.h ttable.c
movegen.o: movegen.h movegen.c
util.o: util.h util.c