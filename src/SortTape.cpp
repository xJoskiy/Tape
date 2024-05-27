#include "SortTape.h"

SortTape::SortTape(Tape& input, Tape& output, size_t max_ram_size) {
    size_t input_size = input.size();
    size_t total_tapes = std::ceil(static_cast<float>(input_size) / max_ram_size);
    std::vector<Tape> tmp;
    for (size_t i = 0; i < total_tapes; i++) {
        tmp.push_back({"tmp/temp_tape" + std::to_string(i), std::ios::app | std::ios::in});
    }

    // choose next elements from input tape, sort and then write to a temp tape
    for (size_t i = 0; i < total_tapes; i++) {
        std::vector<size_t> ram;
        size_t elem_left = std::min(max_ram_size, input_size - i * max_ram_size);
        for (size_t j = 0; j < elem_left; j++) {
            int x = input.get();
            input.move_right();
            ram.push_back(x);
        }

        std::sort(ram.begin(), ram.end());
        for (auto num : ram) tmp[i].write(num);
    }

    for (Tape& temp : tmp) {
        temp.move_to(0);
    }

    // choose the least num from all temp tapes and write to the output tape
    while (tmp.size()) {
        std::pair<size_t, int> min = {0, tmp[0].get()};
        for (size_t i = 0; i < tmp.size(); i++) {
            int val = tmp[i].get();
            if (min.second > val) {
                min = {i, tmp[i].get()};
            }
        }

        if (tmp[min.first].cur() == tmp[min.first].size() - 1)  // if the value is on the end of tape
            tmp.erase(tmp.begin() + min.first);
        else
            tmp[min.first].move_right();

        output.write(min.second);
    }
}