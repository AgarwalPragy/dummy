#include "allot_last.h"


[[nodiscard]] string AllotLastSeatStrategy::allot(const vector<string> &available_seat_numbers) const {
    return available_seat_numbers.front();
}
