#include <algorithm>
#include <cmath>

#include "Tape.h"

class SortTape {
public:
    // Create size_ / max_ram_size_ temporary tapes, each contains at maximum max_ram_size elements
    // which are then sorted and combined together into one sorted output tape
    SortTape(Tape& input, Tape& output, size_t max_ram_size);

    SortTape() = default;
};