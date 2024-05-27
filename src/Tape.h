#pragma once

#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

/*
Class created for simulating a tape via standard file.

Supports following operations: reading from current or given position,
moving tape pointer right/left, writing in the end of tape
*/

class Tape {
private:
    size_t size_;
    size_t cur_;
    std::fstream file_;

    void Init();

public:
    Tape() = default;

    // Create a Tape object from a given file
    Tape(std::string input_file, std::ios::openmode mode = std::ios::in | std::ios::out);

    void move_right();
    void move_left();
    void move_to(size_t index);

    int get(size_t index);
    int get();

    // Writes only at the end of file
    void write(int x);

    // Returns current tape pointer position
    size_t cur() {
        return cur_;
    }

    size_t size() const {
        return size_;
    }
};
