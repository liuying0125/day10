SRCS:=$(wildcard *.c)
ELF:=$(SRCS:%.c=%)
CC:=gcc
all:$(ELF)

%:%.c
	$(CC) $< -o $@ -lpthread
.PHONY:clean
clean:
	rm -rf $(OBJS) $(ELF)
