import os
from car import *
clear = lambda: os.system("cls")
funkcja = True
cars = []
with open("katalog.txt", "r+") as f:
    for line in f:
        cars.append(Car(*line.split()))

while funkcja:
    ilosc = len(cars)
    print("MENU")
    print("1. Wyświetl katalog wszystkich samochodów.")
    print("2. Wyświetl dane jednego samochodu.")
    print("3. Wyświetl listę samochodów posortowaną według: ")
    print("4. Wyświetl listę z samochodami spełniającymi wytyczne: ")
    print("5. Dodaj nowy samochód do katalogu.")
    print("6. Usuń samochód z katalogu")
    print("0. Zakończ program.")
    wybor = int(input("Wybieram pozycję: "))
    clear()
    if wybor == 1:
        for car in cars:
            car.show()
    if wybor == 2:
        tmp = int(input("Chcesz zobaczyć dane samochodu o numerze (1-{}): ".format(ilosc)))
        if tmp > ilosc:
            print("Wpisano zbyt duży numer")
        else:
            print(f'''- Marka: {cars[tmp-1].marka}
  Model: {cars[tmp-1].model}
  Rocznik: {cars[tmp-1].rok} r.
  Pojemność: {cars[tmp-1].pojemnosc} l
  Moc: {cars[tmp-1].moc} konii mechanicznych
  Przebieg: {cars[tmp-1].przebieg} km
  Rodzaj skrzynii biegów: {cars[tmp-1].skrzynia}''')
    if wybor == 3:
        print("1. Sortowanie po przebiegu.")
        print("2. Sortowanie po pojemności silnika.")
        print("3. Sortowanie po ilości konii mechanicznych.")
        print("4. Sortowanie po roku produkcji")
        tmp2 = int(input("Wybieram opcję: "))
        if tmp2 == 1:
            sorted_arr = sorted(cars, key=lambda x: x.przebieg)
            for car in sorted_arr:
                car.show()
        if tmp2 == 2:
            sorted_arr = sorted(cars, key=lambda x: x.pojemnosc)
            for car in sorted_arr:
                car.show()
        if tmp2 == 3:
            sorted_arr = sorted(cars, key=lambda x: x.moc)
            for car in sorted_arr:
                car.show()
        if tmp2 == 4:
            sorted_arr = sorted(cars, key=lambda x: x.rok)
            for car in sorted_arr:
                car.show()
    if wybor == 4:
        print("1. Przebieg poniżej określonej wartości.")
        print("2. Pojemność silnika poniżej określonej wartości.")
        print("3. Pojemność silnika powyżej określonej wartości.")
        print("4. Moc powyżej określonej wartości.")
        print("5. Rok produkcji poniżej określonej wartości.")
        print("6. Rok produkcji powyżej określonej wartości.")
        print("7. Automatyczna.")
        print("8. Manualna.")
        print("9. Marka: ")
        print("10. Model: ")
        print("0. Powrót do MENU.")
        tmp3 = int(input("Wybieram numer: "))
        if tmp3 == 1:
            x = int(input("Maksymalny przebieg: "))
            for car in cars:
                if car.przebieg <= x:
                    car.show()
        if tmp3 == 2:
            x = int(input("Maksymalna pojemność: "))
            for car in cars:
                if car.pojemnosc <= x:
                    car.show()
        if tmp3 == 3:
            x = int(input("Minimalna pojemność: "))
            for car in cars:
                if car.pojemnosc >= x:
                    car.show()
        if tmp3 == 4:
            x = int(input("Minimalna moc silnika: "))
            for car in cars:
                if car.moc >= x:
                    car.show()
        if tmp3 == 5:
            x = int(input("Maksymalny rok wyprodukowania: "))
            for car in cars:
                if car.rok <= x:
                    car.show()
        if tmp3 == 6:
            x = int(input("Minimalny rok wyprodukowania: "))
            for car in cars:
                if car.rok >= x:
                    car.show()
        if tmp3 == 7:
            for car in cars:
                if car.skrzynia == "Automatyczna":
                    car.show()
        if tmp3 == 8:
            for car in cars:
                if car.skrzynia == "Manualna":
                    car.show()
        if tmp3 == 9:
            x = input("Marka: ").title()
            for car in cars:
                if car.marka == x:
                    car.show()
        if tmp3 == 10:
            x = input("Model: ").title()
            for car in cars:
                if car.model == x:
                    car.show()
        if tmp3 == 0:
            break
    if wybor == 5:
        a1 = input("Marka: ")
        b1 = input("Model: ")
        c1 = int(input("Rok: "))
        d1 = float(input("Pojemność: "))
        e1 = int(input("Moc: "))
        f1 = int(input("Przebieg: "))
        g1 = int(input("Skrzynia biegów (1 - automatyczna, 0 - manualna): "))
        cars.append(Car(a1, b1, c1, d1, e1, f1, g1))
        with open("katalog.txt", "a") as f:
            f.write(f"{a1} {b1} {c1} {d1} {e1} {f1} {g1}\n")
    if wybor == 6:
        x = int(input("Samochód o jakim numerze chcesz usunąć? (1-{}): ".format(ilosc)))
        cars.pop(x-1)
        with open("katalog.txt", "r") as f:
            lines = f.readlines()
        with open("katalog.txt", "w") as f:
            for pos, line in enumerate(lines):
                if pos != x-1:
                    f.write(line)
    if wybor == 0:
        funkcja = False
