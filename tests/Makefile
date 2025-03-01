# Makefile for Picol tests

CC = gcc
CFLAGS = -Wall -Wextra
BUILD_DIR = ../build
TEST_BUILD_DIR = $(BUILD_DIR)/tests

# Ensure build directories exist
$(shell mkdir -p $(BUILD_DIR) $(TEST_BUILD_DIR))

all: $(TEST_BUILD_DIR)/test_runner $(TEST_BUILD_DIR)/test_basic_standalone \
     $(TEST_BUILD_DIR)/test_edge_standalone $(TEST_BUILD_DIR)/test_performance_standalone \
     $(BUILD_DIR)/picol

$(TEST_BUILD_DIR)/test_runner: test_runner.c test_basic.c test_edge.c test_performance.c picol_test.h
	$(CC) $(CFLAGS) -o $@ test_runner.c -lm

$(TEST_BUILD_DIR)/test_basic_standalone: test_basic.c picol_test.h
	$(CC) $(CFLAGS) -o $@ -DTEST_STANDALONE test_basic.c -lm

$(TEST_BUILD_DIR)/test_edge_standalone: test_edge.c picol_test.h
	$(CC) $(CFLAGS) -o $@ -DTEST_STANDALONE test_edge.c -lm

$(TEST_BUILD_DIR)/test_performance_standalone: test_performance.c picol_test.h
	$(CC) $(CFLAGS) -o $@ -DTEST_STANDALONE test_performance.c -lm

$(BUILD_DIR)/picol: ../picol.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

clean_tests:
	rm -f $(TEST_BUILD_DIR)/*

run_all: all
	$(TEST_BUILD_DIR)/test_runner

run_basic: $(TEST_BUILD_DIR)/test_basic_standalone
	$(TEST_BUILD_DIR)/test_basic_standalone

run_edge: $(TEST_BUILD_DIR)/test_edge_standalone
	$(TEST_BUILD_DIR)/test_edge_standalone

run_performance: $(TEST_BUILD_DIR)/test_performance_standalone
	$(TEST_BUILD_DIR)/test_performance_standalone

# Development helper targets
debug: CFLAGS += -g -O0
debug: all

release: CFLAGS += -O3
release: all

# For checking memory leaks using valgrind
valgrind_test: all
	valgrind --leak-check=full --show-leak-kinds=all $(TEST_BUILD_DIR)/test_runner

.PHONY: all clean clean_tests run_all run_basic run_edge run_performance debug release valgrind_test
