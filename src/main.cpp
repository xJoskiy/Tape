#include "Tape.h"
#include "SortTape.h"

int main(int argc, char *argv[]) {
    std::string input_file = argv[1], output_file = argv[2];
    size_t max_ram_size = 5;
    // std::fstream f("../config.txt");
    system("rm tmp/*");
    Tape input_tape(input_file);
    Tape output_tape(output_file);
    
    SortTape(input_tape, output_tape, max_ram_size);

    return 0;
}