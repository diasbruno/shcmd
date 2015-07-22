BINS = test

SRC  = $(wildcard src/*.c) test.c
OBJS = $(SRC:.c=.o)

CFLAGS  = -std=c99 -Isrc -Wall -Wno-unused-function -U__STRICT_ANSI__

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

$(BINS): $(SRC) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@./test

clean:
	$(RM) $(OBJS) $(BINS)

.PHONY: test
