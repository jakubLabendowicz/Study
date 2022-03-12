# -*- coding: utf-8 -*-
"""
deserialize json
"""
import json
class DeserializeJson:

 # konstruktor
 def __init__(self, filename):
  tempdata = open(filename, encoding="utf8")
  self.data = json.load(tempdata)
  self.wojewodztwa = []
  self.typy_JST = []

 def zbudujWojewodztwa(self):
  for dep in self.data:
   if not dep['Województwo'] in self.wojewodztwa:
    self.wojewodztwa.append(dep['Województwo'])

 def zbudujTypy(self):
  for dep in self.data:
   if not dep['typ_JST'] in self.typy_JST:
    self.typy_JST.append(dep['typ_JST'])

 # przykładowe statystyki
 def wyswietlUrzadDlaWojewodztwa(self, wojewodztwo, typ_JST):
  example_stat = 0
  for dep in self.data:
   if dep['typ_JST'] == typ_JST and dep['Województwo'] == wojewodztwo:
    example_stat += 1
  print('liczba urzędów ' + typ_JST +' w województwie ' + wojewodztwo + ': ' + ' ' + str(example_stat))

 def Z233(self):
  for woj in self.wojewodztwa:
   for typ in self.typy_JST:
    self.wyswietlUrzadDlaWojewodztwa(woj, typ)