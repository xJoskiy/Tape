/*
Class created for simulating a tape via standard file.

Supports following operations: reading from current or given position,
moving tape pointer right/left
*/

#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

class Tape {
private:
    size_t size_;
    size_t cur_;
    size_t max_ram_size_;
    std::fstream file_;

    void Init();

public:
    Tape() = default;

    // Create a Tape object from a given file
    Tape(std::string input_file, std::ios::openmode mode);

    void move_right();
    void move_left();
    void move_to(size_t index);

    int get(size_t index);
    int get();

    void insert(size_t pos, int x) {};

    // Writes only at the end of file
    void write(int x) {
        std::string s = std::to_string(x) + ' ';
        file_ << s;
    }

    size_t get_size() const {
        return size_;
    }
};