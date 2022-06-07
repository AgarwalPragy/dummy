#include "py_booking.h"

#include "book.h"


void PySeatAllotmentStrategy::setInstance(c_PySeatAllotmentStrategy *instance){
    this->_pyInstance = instance;
}

string PySeatAllotmentStrategy::allot(const vector <string> &available_seat_numbers) const {
    // PySeatAllotmentStrategy_allot(_pyInstance, available_seat_numbers);
}
