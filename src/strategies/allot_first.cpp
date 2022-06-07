#include "allot_first.h"


[[nodiscard]] string AllotFirstSeatStrategy::allot(const vector<string> &available_seat_numbers) const {
    return available_seat_numbers.front();
}
