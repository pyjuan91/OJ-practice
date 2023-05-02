class Point:
    Count = 0

    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y
        Point.Count += 1

    def __repr__(self) -> str:
        return f"point x:{self.x}, y:{self.y}, pi:{self.Count}"

    def set_x(self, x: int) -> None:
        self.x = x

    def get_x(self) -> int:
        return self.x

    yo = property(lambda self: self.get_x(), lambda self, x: self.set_x(x))


point = Point(3, 2)
point.yo = 4
print(point.x)
