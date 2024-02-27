CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c++17
LDFLAGS :=

GTEST_FLAGS = -lgtest_main -lgtest
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS = --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

GTEST_INSTALLED := $(shell dpkg -l | grep libgtest-dev > /dev/null; echo $$?)

GTEST_DIR := ./external/googletest
GTEST_LIB := $(GTEST_DIR)/build/lib/libgtest.a
GTEST_INCLUDE := -I$(GTEST_DIR)/googletest/include

TPP_DIR := functions
INCLUDE_DIR := include
TEST_DIR := tests

TEST_SRC=$(wildcard ./tests/test*.cc)
TEST_OBJ=$(patsubst ./tests/test_%.cc, %.o, $(TEST_SRC))

OS := $(shell uname -s)

ifeq ($(OS),Linux)
	LDFLAGS += -lstdc++ -pthread -lrt -lm
else ifeq ($(OS),Darwin)
	LDFLAGS += -lstdc++ -lm
endif

all: check_gtest

check_gtest:
	@if [ "$(GTEST_INSTALLED)" = "0" ]; then \
		make test; \
	else \
		make gtest_build; \
		make google_test; \
	fi

gtest_build:
	cd external/googletest && \
	rm -rf build && \
	mkdir build && cd build && \
	cmake .. && make

google_test: clean $(GTEST_LIB)
	$(CC) $(CFLAGS) $(TEST_SRC) $(GTEST_INCLUDE) -o s21_containers_tests $(GTEST_LIB) $(LDFLAGS)
	./s21_containers_tests

test: clean
	$(CC) $(CFLAGS) $(TEST_SRC) $(GTEST_FLAGS) -o s21_containers_tests $(LDFLAGS)
	./s21_containers_tests

valgrind:
	valgrind $(VALGRIND_FLAGS) -s ./s21_containers_tests

leak:
	leaks -atExit -- ./s21_containers_tests

clang_format:
	clang-format -i $(INCLUDE_DIR)/*.h $(TPP_DIR)/*.tpp $(TEST_DIR)/*.cc

gcov_test: clean
	$(CC) $(GCOV_FLAGS) $(CFLAGS) $(TEST_SRC) $(GTEST_FLAGS) $(LDFLAGS) -o s21_containers_tests
	./s21_containers_tests
	lcov -t "gcov_report" -o test.info -c -d . --no-external --ignore-errors mismatch
	genhtml -o report test.info
	rm -f *.gcno *.gcda *.info test *.gcov
	open ./report/index.html
#	lcov -t "gcov_report" -o test.info --no-external -c -d .
#	genhtml -o report/ test.info
#	rm -f *.gcno *.gcda *.info test *.gcov

clean:
	@rm -f $(OBJS) *.a *.o s21_containers_tests
	@rm -rf *.gcda *.gcno *.info report
