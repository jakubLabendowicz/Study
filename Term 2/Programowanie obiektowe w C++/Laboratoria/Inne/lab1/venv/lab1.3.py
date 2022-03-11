gracz1 = int(input('(gracz 1) 0-papier, 1-nożyce, 2-kamień'))
gracz2 = int(input('(gracz 2) 0-papier, 1-nożyce, 2-kamień'))

#suma 0 lub 4 ----------
if gracz1 + gracz2 == 0 or gracz1 + gracz2 == 4:
    print('remis')

#suma 1 ----------
if gracz1 + gracz2 == 1:
    if gracz1 == 1:
        print('wygrał gracz1')
    elif gracz2 == 1:
        print('Wygrał gracz2')

#suma 2 ----------
if gracz1 + gracz2 == 2:
    if gracz1 == 1:
        print('remis')
    elif gracz1 == 0:
        print('wygrał gracz1')
    elif gracz2 == 0:
        print('wygrał gracz2')

#suma 3 ----------
if gracz1 + gracz2 == 3:
    if gracz1 == 2:
        print('wygrał gracz1')
    elif gracz2 == 2:
        print('wygrał gracz2')