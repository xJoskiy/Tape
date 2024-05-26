#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Tape.h"

TEST(TestTape, TestGetSize) {
    std::string input_file = "input_tape.txt";
    Tape tape(input_file,  std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get_size(), 14);
}

TEST(TestTape, TestGet) {
    std::string input_file = "input_tape.txt";
    Tape tape(input_file,  std::ios::in | std::ios::out);

    ASSERT_EQ(tape.get(0), 0);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(12), 12);
}