# Build Output Name
NAME = experiments

# Output Directories
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Output Files
EXE = $(BINDIR)/$(NAME)
OBJ = grawlix.o carvers.o experiments.o
OPATHS = $(addprefix $(OBJDIR)/,$(OBJ))

# Input Information
SRCDIR = grawlix

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -c -o $@
LDFLAGS = -Wall -Wextra
RELEASEFLAGS = -O2
DEBUGFLAGS = -g -DDEBUG

all: CFLAGS += $(RELEASEFLAGS)
all: configure
all: $(EXE)

debug: CFLAGS += $(DEBUGFLAGS)
debug: configure
debug: $(EXE)

configure:
	mkdir -p $(BINDIR) $(OBJDIR)

$(EXE): $(OPATHS)
	$(CC) $(LDFLAGS) $(OPATHS) -o $@

$(OBJDIR)/grawlix.o: $(SRCDIR)/grawlix.h
	$(CC) $(CFLAGS) $(SRCDIR)/grawlix.c

$(OBJDIR)/carvers.o: $(SRCDIR)/grawlix.h
	$(CC) $(CFLAGS) $(SRCDIR)/carvers.c

$(OBJDIR)/experiments.o: $(SRCDIR)/grawlix.h
	$(CC) $(CFLAGS) experiments.c

clean:
	mkdir -p $(OBJDIR) && rm -r $(OBJDIR)

rebuild: clean
rebuild: all

rebuild: clean
rebuild: debug

delete: erase
erase:
	mkdir -p $(BUILDDIR) && rm -r $(BUILDDIR)

