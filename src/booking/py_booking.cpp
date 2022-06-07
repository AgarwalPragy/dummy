#include "py_booking.h"

#include "__init__.h"


void PySeatAllotmentStrategy::setInstance(c_PySeatAllotmentStrategy *instance){
    this->_pyInstance = instance;
}

PySeatAllotmentStrategy::string allot(const vector <string> &available_seat_numbers) const override {
    PySeatAllotmentStrategy_allot(_pyInstance);
}