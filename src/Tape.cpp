#include "Tape.h"

void Tape::Init() {
    size_ = 0, cur_ = 0;

    int x;
    while (file_ >> x) {
        size_++;
    }

    file_.clear();
    file_.seekg(0, std::ios::beg);
}

Tape::Tape(std::string input_file, std::ios::openmode mode /* = std::ios::in | std::ios::out */) {
    file_ = std::fstream(input_file);
    if (!file_.is_open()) throw std::runtime_error("Cannot open file: " + input_file);
    Init();
}

void Tape::move_right() {
    if (cur_ == size_ - 1) return;
    int x;
    file_ >> x;
    cur_++;
}

void Tape::move_left() {
    if (!cur_) return;
    std::streampos off = 1;
    do {
        file_.seekg(file_.tellg() - off, std::ios::beg);
        file_.seekp(file_.tellp() - off);
    } while (std::isdigit(file_.peek()));

    cur_--;
}

void Tape::move_to(size_t index) {
    if (index > size_ - 1) throw std::out_of_range("");

    if (cur_ > index)
        while (cur_ - index) move_left();
    else
        while (index - cur_) move_right();
}

int Tape::get(size_t index) {
    move_to(index);
    int x;
    size_t old_pos = file_.tellg();
    file_ >> x;

    file_.clear();
    file_.seekg(old_pos);

    return x;
}

int Tape::get() {
    return get(cur_);
}