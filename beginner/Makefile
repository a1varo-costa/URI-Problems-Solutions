CC := gcc
CFLAGS := -std=c99 -O2
LDFLAGS := -lm

OUTDIR := bin

%: %.c
	@ mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $(OUTDIR)/$@ $^ $(LDFLAGS)
