#include "booking.h"

using namespace booking;

bool BookingSeat::is_delux() const {
    return type == SeatType::DELUX;
}

bool BookingSeat::is_standard() const {
    return type == SeatType::STANDARD;
}

BookingSeat Ticket::add(const Person &person, const vector<string> &available_seat_numbers,
                                          const SeatAllotmentStrategy &allotment_strategy) {
    string seat_number = allotment_strategy.allot(available_seat_numbers);
    BookingSeat seat = {
            .type=SeatType::DELUX,
            .seat_number=seat_number
    };
    seats[person] = seat;
    return seat;
}

void Ticket::update_seats(const unordered_map<Person, BookingSeat> &new_seats) {
    seats.clear();
    for (auto [k, v]: new_seats)
        seats[k] = v;
}

bool Person::operator==(const Person &other) const {
    return name == other.name && phone_number == other.phone_number;
}

template<>
class hash<Person> {
public:
    size_t operator()(const Person &p) const {
        return hash<string>(p.name);
    }
};
