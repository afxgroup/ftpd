TARGET  := ftpd
CC	:= ppc-amigaos-gcc
CFILES  := $(wildcard source/*.c)
OFILES  := $(patsubst source/%,build.os4/%,$(CFILES:.c=.o))

CFLAGS  := -mcrt=clib2 -std=c99 -gstabs -w -Iinclude -DSTATUS_STRING="\"ftpd v1.0\""
LDFLAGS := -mcrt=clib2 -athread=native

.PHONY: all clean

all: build.os4 $(TARGET)

build.os4:
	@mkdir build.os4/

$(TARGET): $(OFILES)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OFILES): build.os4/%.o : source/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(RM) -r build.os4/ $(TARGET)
