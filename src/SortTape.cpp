#include "SortTape.h"

SortTape::SortTape(Tape& input, Tape& output, size_t max_ram_size) {
    size_t input_size = input.get_size();
    size_t tapes_to_create = std::ceil(static_cast<float>(input_size / max_ram_size_));
    std::vector<Tape> tmp;
    for (size_t i = 0; i < tapes_to_create; i++) {
        std::cout << input_size << ' ' << max_ram_size_ << std::endl;

        std::cout << i << std::endl;
        tmp.push_back({"../tmp/tmp" + std::to_string(i), std::ios::app | std::ios::in});
    }

    for (size_t i = 0; i < tapes_to_create; i++) {
        std::vector<size_t> ram;
        size_t elem_left = std::min(max_ram_size_, input_size - i * max_ram_size_);
        for (size_t j = 0; j < elem_left; j++) {
            int x = input.get();
            ram.push_back(x);
        }

        std::sort(ram.begin(), ram.end());
        for (auto num : ram) tmp[i].write(num);
    }
}