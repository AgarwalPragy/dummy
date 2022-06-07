#ifndef TRIAL_BOOKING_H
#define TRIAL_BOOKING_H

#include <string>
#include <unordered_map>

using namespace std;

namespace booking {
    typedef string Movie;
    typedef string datetime;

    struct Person {
        string name;
        string phone_number;
        bool operator==(const Person &other) const;
    };

    enum class SeatType {
        DELUX,
        STANDARD,
    };

    struct BookingSeat {
        SeatType type;
        string seat_number;

        [[nodiscard]] bool is_delux() const;

        [[nodiscard]] bool is_standard() const;
    };

    class SeatAllotmentStrategy {
    public:
        [[nodiscard]] virtual string allot(const vector<string> &available_seat_numbers) const = 0;
    };

    struct Ticket {
    private:
        Movie movie;
        datetime booking_made_on;
        unordered_map<Person, BookingSeat> seats;
        double total_amount;
    public:
        BookingSeat add(const Person &person,
                        const vector<string> &available_seat_numbers,
                        const SeatAllotmentStrategy &allotment_strategy);

        void update_seats(const unordered_map<Person, BookingSeat> &new_seats);
    };
}

#endif //TRIAL_BOOKING_H