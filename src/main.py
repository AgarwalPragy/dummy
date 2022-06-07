import sys
sys.path.append("build/lib.macosx-10.9-x86_64-3.9")

from datetime import datetime

from strategies import AllotFirstSeatStrategy, AllotLastSeatStrategy
from py_strategies.allot_mid import AllotMidSeatStrategy

if __name__ == '__main__':
    seats_available = list(map(str, range(10)))

    harry = Person(name='Harry Potter', phone_number='1')
    hermione = Person(name='Hermione Granger', phone_number='2')
    ron = Person(name='Ron Weasley', phone_number='3')
    print(harry, hermione, ron)

    ticket = Ticket(movie='Chamber of Secrets', booking_made_on=datetime.now(), total_amount=100.0)

    seat1 = ticket.add(harry, seats_available, AllotFirstSeatStrategy())
    seats_available.remove(seat1)
    seat2 = ticket.add(hermione, seats_available, AllotLastSeatStrategy())
    seats_available.remove(seat2)
    seat3 = ticket.add(ron, seats_available, AllotMidSeatStrategy())
    seats_available.remove(seat3)

    print(seat1, seat2, seat3)
    print(ticket)
