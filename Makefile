SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
ELF:=main
CC:=gcc
$(ELF):$(OBJS)
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf $(OBJS) $(ELF)
