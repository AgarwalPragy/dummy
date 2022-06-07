#pragma once

#include "booking.h"

#include "__init__.h"

using namespace booking;

struct c_PySeatAllotmentStrategy;

class PySeatAllotmentStrategy : public SeatAllotmentStrategy {
public:
    c_PySeatAllotmentStrategy *_pyInstance;

    void setInstance(c_PySeatAllotmentStrategy *instance);

    string allot(const vector <string> &available_seat_numbers) const override;

};
