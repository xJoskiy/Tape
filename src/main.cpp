#include "Tape.h"

int main(int argc, char *argv[]) {
    std::string input_file = argv[1], output_file = argv[2];
    size_t max_ram_size = 5;
    // std::fstream f("../config.txt");
    Tape tape(input_file, std::ios::in | std::ios::out);
    // tape.sort_and_write(output_file);
    // tape.insert(2, 2);

    return 0;
}