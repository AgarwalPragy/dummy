#pragma once

#include <vector>
#include "../booking/booking.h"

using namespace std;

class AllotFirstSeatStrategy : public SeatAllotmentStrategy {
public:
    [[nodiscard]] string allot(const vector <string> &available_seat_numbers) const override;
};
