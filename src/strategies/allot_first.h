#pragma once

#include <vector>
#include "../booking/booking.h"

using namespace std;
using namespace booking;

namespace strategies {
    class AllotFirstSeatStrategy : public SeatAllotmentStrategy {
        [[nodiscard]] string allot(const vector <string> &available_seat_numbers) const override;
    };
}
