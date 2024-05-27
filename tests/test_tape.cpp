#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Tape.h"

std::string input_file = "test_data/input_tape.txt";

TEST(TestTape, TestGetSize) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    ASSERT_EQ(tape.size(), 14);

    size_t pos = tape.cur();
    ASSERT_EQ(pos, 0);
}

TEST(TestTape, TestGet) {
    Tape tape(input_file, std::ios::in | std::ios::out);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(), 0);
}

TEST(TestTape, TestMoveRight) {
    Tape tape(input_file);

    while(tape.get() != 13) {
        tape.move_right();
    }

    size_t pos = tape.cur();
    ASSERT_EQ(pos, 13);
    ASSERT_EQ(tape.get(5), 5);
    ASSERT_EQ(tape.get(5), 5);
}

TEST(TestTape, TestMoveLeft) {
    Tape tape(input_file);

    for (size_t i = 0; i < 20; i++) {
        tape.move_right();
    }

    for (size_t i = 0; i < 20; i++) {
        tape.move_left();
    }

    size_t pos = tape.cur();
    size_t val = tape.get();
    ASSERT_EQ(pos, 0);
    ASSERT_EQ(val, 0);
}

TEST(TestTape, TestMove) {
    Tape tape(input_file);
    for (size_t i = 0; i < 20; i++) {
        tape.move_right();
    }

    tape.move_to(0);
    size_t pos = tape.cur();
    size_t val = tape.get();

    ASSERT_EQ(pos, 0);
    ASSERT_EQ(val, 0);
    ASSERT_THROW(tape.move_to(20), std::out_of_range);
}

TEST(TestTape, TestEmptyTape) {
    Tape input_tape(input_file);
    Tape tape("tmp/temp1", std::ios::app | std::ios::in);
    for (size_t i = 0; i < input_tape.size(); i++) {
        int val = input_tape.get();
        input_tape.move_right();
        tape.write(val);
    }

    for (size_t i = 0; i < input_tape.size(); i++)
        ASSERT_EQ(i, tape.get(i));

    // tape.move_to(13);
    // ASSERT_EQ(13, tape.get());
}
