class Car:
    def __init__(self, a, b, c, d, e, f, g):
        self.marka = a
        self.model = b
        self.rok = int(c)
        self.pojemnosc = float(d)
        self.moc = int(e)
        self.przebieg = int(f)
        self.skrzynia = "Automatyczna" if int(g) == 0 else "Manualna"

    def show(self):
        print(f'''- Marka: {self.marka}
  Model: {self.model}
  Rocznik: {self.rok} r.
  Pojemność: {self.pojemnosc} l
  Moc: {self.moc} konii mechanicznych
  Przebieg: {self.przebieg} km
  Rodzaj skrzynii biegów: {self.skrzynia}
''')