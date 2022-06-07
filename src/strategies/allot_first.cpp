#include "allot_first.h"

    
[[nodiscard]] string AllotFirstSeatStrategy::allot(const vector<string> &available_seat_numbers) const override {
    return available_seat_numbers.front();
}
