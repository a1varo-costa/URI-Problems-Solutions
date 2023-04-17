CC := gcc
CXX := g++
CFLAGS := -std=c99 -O2
CXXFLAGS := -std=c++17 -O2
LDFLAGS := -lm

OUTDIR := ../build/paradigms

%:
	$(MAKE) $(OUTDIR)/$@

$(OUTDIR)/%: %.c
	@ mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OUTDIR)/%: %.cpp
	@ mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)