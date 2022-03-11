//
//  main.swift
//  jl_2021_12_16_lab10
//
//  Created by student on 16/12/2021.
//  Copyright © 2021 PL. All rights reserved.
//

import Foundation


func max_licz(liczba_1:Int, liczba_2:Int, liczba_3:Int) -> Int {
    if liczba_1 > liczba_2 && liczba_1 > liczba_3 {
        print(liczba_1)
        return liczba_1
    } else if liczba_2 > liczba_3 {
        print(liczba_2)
        return liczba_2
    } else {
        print(liczba_3)
        return liczba_3
    }
}

func min_licz(liczba_1:Int, liczba_2:Int, liczba_3:Int) ->Int {
    if liczba_1 < liczba_2 && liczba_1 < liczba_3 {
        print(liczba_1)
        return liczba_1
    } else if liczba_2 < liczba_3 {
        print(liczba_2)
        return liczba_2
    } else {
        print(liczba_3)
        return liczba_3
    }
}

func min_max_licz(liczba_1:Int, liczba_2:Int, liczba_3:Int) -> (Int, Int) {
    var min:Int
    var max:Int
    
    if liczba_1 > liczba_2 && liczba_1 > liczba_3 {
        print(liczba_1)
        max = liczba_1
    } else if liczba_2 > liczba_3 {
        print(liczba_2)
        max = liczba_2
    } else {
        print(liczba_3)
        max = liczba_3
    }
    
    if liczba_1 < liczba_2 && liczba_1 < liczba_3 {
        print(liczba_1)
        min = liczba_1
    } else if liczba_2 < liczba_3 {
        print(liczba_2)
        min = liczba_2
    } else {
        print(liczba_3)
        min = liczba_3
    }
    
    return (min, max)
}

func zad1() -> () {
    print()
}
//zad1()


func dodawanie(liczba_1: Double, liczba_2: Double) -> Double {
    return liczba_1 + liczba_2
}
func odejmowanie(liczba_1: Double, liczba_2: Double) -> Double {
    return liczba_1 - liczba_2
}
func mnozenie(liczba_1: Double, liczba_2: Double) -> Double {
    return liczba_1 * liczba_2
}
func dzielenie(liczba_1: Double, liczba_2: Double) -> Double {
    return liczba_1 / liczba_2
}
func pierwiastkowanie(liczba_1: Double) -> Double {
    return sqrt(liczba_1)
}


func zad2() -> () {
    let menu = """
    1 - dodanie
    2 - odejmowanie
    3 - mnożenie
    4 - dzielenie
    5 - pierwiastkowanie
    """
    print(menu)
    let wybor = Int(readLine()!)!
    
    if wybor < 5 && wybor > 0 {
        let liczba_1 = Double(readLine()!)!
        let liczba_2 = Double(readLine()!)!
        switch wybor {
        case 1: print(dodawanie(liczba_1: liczba_1, liczba_2: liczba_2))
        case 2: print(odejmowanie(liczba_1: liczba_1, liczba_2: liczba_2))
        case 3: print(mnozenie(liczba_1: liczba_1, liczba_2: liczba_2))
        case 4: print(dzielenie(liczba_1: liczba_1, liczba_2: liczba_2))
        default:
            print()
        }
    } else {
        let liczba_1 = Double(readLine()!)!
        print(pierwiastkowanie(liczba_1: liczba_1))
    }
}
//zad2()


func getPoint() -> (Double, Double) {
    print("Podaj punkt")
    return (Double(readLine()!)!, Double(readLine()!)!)
}

func odleglosc(point_1: (Double, Double), point_2: (Double, Double)) -> Double {
    let ox = point_1.0 - point_2.0
    let oy = point_1.1 - point_2.1
    return sqrt(ox*ox + oy*oy)
}

func cwiartka(point_1: (Double, Double)) -> Int {
    if point_1.0 > 0 {
        if point_1.1 > 0 {
            return 1
        } else {
            return 4
        }
    } else {
        if point_1.1 > 0 {
            return 2
        } else {
            return 3
        }
    }
}

func gdzie(point_1: (Double, Double), w: Double) -> Int {
    if point_1.0 > -w && point_1.0 < w && point_1.1 > -w && point_1.1 < w {
        return 0
    }
    else if point_1.0 == -w && point_1.0 == w && point_1.1 == -w && point_1.1 == w {
        return 1
    }
    else {
        return 2
    }
}

func zad3() -> () {
    let point_1: (Double,Double) = getPoint()
    let point_2: (Double,Double) = getPoint()
    print(odleglosc(point_1: point_1, point_2: point_2))
    print(cwiartka(point_1: point_1))
    print(gdzie(point_1: point_1, w: 15.0))
}
//zad3()





class Osoba {
    var imie: String
    var nazwisko: String
    var rok: Int
    
    init(imie: String, nazwisko: String, rok: Int) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rok = rok
    }
    
    func policzWiek() -> Int {
        return 2021 - self.rok
    }
    
    func show() -> () {
        var show_var = """
        Imię: \(self.imie)
        Nazwisko: \(self.nazwisko)
        Rok: \(self.rok)
        Wiek: \(self.policzWiek())
        """
        print(show_var)
    }
}

func zad5() -> () {
    var osoba_1 = Osoba(imie: "Kuba", nazwisko: "Łabendowicz", rok: 2000)
    osoba_1.show()
}
zad5()
