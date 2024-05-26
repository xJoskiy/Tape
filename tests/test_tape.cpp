#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Tape.h"

std::string input_file = "test_data/input_tape.txt";

TEST(TestTape, TestGetSize) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get_size(), 14);

    size_t pos = tape.cur_pos();
    ASSERT_EQ(pos, 0);
}

TEST(TestTape, TestGet) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get(0), 0);
    ASSERT_EQ(tape.get(), 0);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(12), 12);
}

TEST(TestTape, TestMoveRight) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    while (tape.get() != 13) {
        tape.move_right();
    }

    size_t pos = tape.cur_pos();
    ASSERT_EQ(pos, 13);
}

TEST(TestTape, TestMoveLeft) {
    Tape tape(input_file, std::ios::in | std::ios::out);

    while (tape.get() != 13) {
        tape.move_right();
    }

    while (tape.get() != 0) {
        tape.move_left();
    }

    size_t pos = tape.cur_pos();
    ASSERT_EQ(pos, 0);
}

TEST(TestTape, TestMove) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    tape.move_to(13);

    int x = tape.get();
    size_t pos = tape.cur_pos();

    ASSERT_EQ(x, 13);
    ASSERT_EQ(pos, 13);
    ASSERT_THROW(tape.move_right(), std::out_of_range);
    ASSERT_THROW(tape.move_to(32), std::out_of_range);
}

