#
# C++ console application example
# type run to execute compiledlinked
# type clean to clean sources
#
# touch screen in console mode to show keyboard
#

TARGET =compiledlinked.out

all: $(TARGET)

#CFLAGS = -O2 -Wall -std=c11 -faggressive-loop-optimizations\
#	-ftree-vectorize
CPPFLAGS = -O2 -Wall -std=c++11 -faggressive-loop-optimizations\
	-ftree-vectorize

OBJS = stringFunctionCalculation.o

$(TARGET): $(OBJS)
		$(CXX) -o $@ $^ $(LDFLAGS) -s

clean:
		rm $(OBJS) $(TARGET)

run: $(TARGET)
		run_ca $(TARGET)
