# Variables

GTEST_DIR = gtest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = nm102_test_runner

OBJ_DIR = obj/

# Phoney targets

all: $(TESTS)

clean:
	rm -f $(TESTS) gtest.a gtest_main.a *.o
	rm -f $(OBJ_DIR)*

mostlyclean:
	rm -f $(patsubst %.cc,$(OBJ_DIR)%.o,$(wildcard *.cc)) $(OBJ_DIR)nm102_test_runner

test:  mostlyclean $(OBJ_DIR)nm102_test_runner
	./$(OBJ_DIR)nm102_test_runner

# File targets

$(OBJ_DIR)gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc
	mv gtest-all.o $(OBJ_DIR)

$(OBJ_DIR)gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc
	mv gtest_main.o $(OBJ_DIR)

gtest.a: $(OBJ_DIR)gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)gtest_main.a: $(OBJ_DIR)gtest-all.o $(OBJ_DIR)gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

-include $(SRCS:%.c=$(DEPDIR)/%.P)

$(OBJ_DIR)nm102_test_runner: $(patsubst %.cc, $(OBJ_DIR)%.o,$(wildcard *.cc)) $(OBJ_DIR)gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
