CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDLIBS = -lboost_program_options

SRCDIR = src
BUILDDIR = build
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
DEPS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.d,$(SRCS))

TARGET = $(BINDIR)/talkative-turtle

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEPS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILDDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)
	rmdir $(BUILDDIR) 2>/dev/null || true
	rmdir $(BINDIR) 2>/dev/null || true