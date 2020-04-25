BINARY=smsm.so
SDIR=src
ODIR=obj

SRCS=$(wildcard $(SDIR)/*.cpp)
SRCS+=$(wildcard $(SDIR)/Utils/*.cpp)
SRCS+=$(wildcard $(SDIR)/Modules/*.cpp)
SRCS+=$(wildcard $(SDIR)/Hud/*.cpp)

OBJS=$(patsubst $(SDIR)%.cpp, $(ODIR)%.o, $(SRCS))

WARNINGS=-Wno-unused-function -Wno-unused-variable -Wno-parentheses -Wno-unknown-pragmas
CXXFLAGS=-std=c++17 -m32 -Wall $(WARNINGS) -I$(SDIR)
LDFLAGS=-m32 -fPIC -static-libstdc++ -shared

sar: pre $(BINARY)

$(BINARY): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJS): $(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS)  $< -o $@

pre:
	mkdir -p $(ODIR)/Modules
	mkdir -p $(ODIR)/Utils
	mkdir -p $(ODIR)/Hud

clean:
	rm -rf $(OBJS) $(BINARY)
