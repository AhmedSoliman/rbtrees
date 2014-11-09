CXX = g++
AR = ar
CFLAGS = -O3 -ggdb -Wall
LD = -lgtest
INCLUDES = -Iincludes
LIBINC = -I/usr/local/include
SRC = $(wildcard src/*.cpp)
TESTS = $(wildcard test/*.cpp)
TESTS_OBJS = $(patsubst %.cpp,%.o,$(TESTS))
OBJS = $(patsubst %.cpp,%.o,$(SRC))
testRunner = runner
library = librbtree.a

all: $(library) Makefile $(testRunner)


$(library): $(OBJS)
	@echo $(library) [AR]
	@$(AR) rcs $(library) $(OBJS)
src/%.o: src/%.cpp
	@echo $< [CC]
	@$(CXX) $(CFLAGS) -o $(patsubst %.cpp,%.o,$<) -c $(INCLUDES) $<
$(testRunner): $(TESTS_OBJS) $(library)
	@echo $< [CC]
	@$(CXX) $(CFLAGS) $(INCLUDES) $(LIBINC) $(LD) -o $(testRunner)  $(TESTS_OBJS) $(library)
test/%.o: test/%.cpp 
	@echo $< [CC]
	@$(CXX) $(CFLAGS) $(INCLUDES) $(LIBINC) -o $(patsubst %.cpp,%.o,$<) -c $<
clean:
	@echo [Clean]
	@rm -rf runner *.o test/*.o src/*.o *.a
.PHONY: clean
