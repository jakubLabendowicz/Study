# -*- coding: utf-8 -*-
"""
deserialize json
"""
import json
class DeserializeJson:

 # konstruktor
 def __init__(self, filename):
  print("let's deserialize something")
  tempdata = open(filename, encoding="utf8")
  self.data = json.load(tempdata)
  self.wojewodztwa = []
  self.typy_JST = []

 def zbudujWojewodztwa(self):
  for dep in self.data:
   add = true
   for woj in self.wojewodztwa:
    if dep['Województwo'] == woj:
     add = false
   self.wojewodztwa.append(dep['Województwo'])

 def zbudujTypy(self):
  for dep in self.data:
   add = true
   for typ in self.typy_JST:
    if dep['typ_JST'] == typ:
     add = false
   self.typy_JST.append(dep['typ_JST'])

 # przykładowe statystyki
 def somestats(self, wojewodztwo, typ_JST):
  example_stat = 0
  for dep in self.data:
   if dep['typ_JST'] == typ_JST and dep['Województwo'] == wojewodztwo:
    example_stat += 1
   print('liczba urzędów ' + typ_JST +' w województwie ' + wojewodztwo + ': ' + ' ' + str(example_stat))

 def Z233(self):
  for woj in self.wojewodztwa:
   for typ in self.typy_JST:
    self.somestats(woj, typ)