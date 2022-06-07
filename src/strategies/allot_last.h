#ifndef TRIAL_ALLOT_FIRST_H
#define TRIAL_ALLOT_FIRST_H

#include <vector>
#include "../booking/booking.h"

using namespace std;
using namespace booking;

namespace strategies {
    class AllotLastSeatStrategy : SeatAllotmentStrategy {
        [[nodiscard]] string allot(const vector<string> &available_seat_numbers) const override {
            return available_seat_numbers.back();
        }
    };
}


#endif //TRIAL_ALLOT_FIRST_H
