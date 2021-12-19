CC := gcc
CFLAGS := -std=c99 -O2
LDFLAGS := -lm

OUTDIR := ../build/data-structures

%:
	$(MAKE) $(OUTDIR)/$@

$(OUTDIR)/%: %.c
	@ mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
