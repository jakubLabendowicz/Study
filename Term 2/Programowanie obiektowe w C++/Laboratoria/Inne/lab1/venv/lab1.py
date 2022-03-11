from random import *

losowa = randint(1, 10)
graTrwa = True

while graTrwa:
    podana = int(input('Zgadnij liczbe od 1 do 10: '))

    if podana == losowa:
        print('Wygrales!')
        graTrwa = False
    elif podana < losowa:
        print('Podana liczba jest za mala')
    else:
        print('Podana liczba jest za duża')