#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Tape.h"

std::string input_file = "test_data/input_tape.txt";

TEST(TestTape, TestGetSize) {
    Tape tape(input_file,  std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get_size(), 14); 
}

TEST(TestTape, TestGet) {
    Tape tape(input_file,  std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get(0), 0);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(12), 12);
}