# Copyright (c) 2015 Sonic Detours. All Rights Reserved.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Variables

GTEST_DIR = gtest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -I../ -Wall -Wextra -pthread

TESTS = $(OBJ_DIR)nm102_test_runner

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
