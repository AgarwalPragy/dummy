from booking import SeatAllotmentStrategy

class AllotMidSeatStrategy(SeatAllotmentStrategy):
    @staticmethod
    def allot(self, available_seat_numbers: list[str]) -> str:
        return available_seat_numbers[len(available_seat_numbers) // 2]
