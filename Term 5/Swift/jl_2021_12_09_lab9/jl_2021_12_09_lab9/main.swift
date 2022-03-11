//
//  main.swift
//  jl_2021_12_09_lab9
//
//  Created by student on 09/12/2021.
//  Copyright © 2021 PL. All rights reserved.
//

import Foundation

//struct LiczbaZespolona {
//    var a: Double
//    var b: Double
//
//    init(a:Double, b:Double) {
//        self.a = a
//        self.b = b
//    }
//
//    func show() -> () {
//        print(String(self.a) + " + (" + String(self.b) + ")i")
//    }
//}
//
//print("Podaj pierwszą liczbę zespoloną")
//let a1 = Double(readLine()!)!
//let b1 = Double(readLine()!)!
//let liczba1 = LiczbaZespolona(a: a1, b: b1)
//liczba1.show()
//
//print("Podaj drugą liczbę zespoloną")
//let a2 = Double(readLine()!)!
//let b2 = Double(readLine()!)!
//let liczba2 = LiczbaZespolona(a: a2, b: b2)
//liczba2.show()
//
//print("Co chcesz zrobić?")
//let wybor = Int(readLine()!)!
//
//switch wybor {
//case 1:
//    let dodawanie = LiczbaZespolona(a: liczba1.a + liczba2.a, b: liczba1.b + liczba2.b)
//    dodawanie.show()
//case 2:
//    let odejmowanie = LiczbaZespolona(a: liczba1.a - liczba2.a, b: liczba1.b - liczba2.b)
//    odejmowanie.show()
//case 3:
//    let mnozenie = LiczbaZespolona(a: liczba1.a*liczba2.a + -1*liczba1.b*liczba2.b, b: liczba1.a*liczba2.b+liczba1.b*liczba2.a)
//    mnozenie.show()
//default:
//    print("")
//}



//Zad2
//struct RzutOszczepem {
//    let id: Int
//    let proba1: Int
//    let proba2: Int
//    let proba3: Int
//
//    init(id:Int, proba1:Int, proba2:Int, proba3:Int) {
//        self.id = id
//        self.proba1 = proba1
//        self.proba2 = proba2
//        self.proba3 = proba3
//    }
//
//    func srednia() -> Double {
//        var suma = Double(self.proba1 + self.proba2 + self.proba3)
//        return suma/3.0
//    }
//
//    func show() -> () {
//        print("ID: \(self.id)")
//        print("Proba1: \(self.proba1)")
//        print("Proba2: \(self.proba2)")
//        print("Proba3: \(self.proba3)")
//        print("Średnia: \(self.srednia())")
//    }
//}
//
//print("Zawodnik 0")
//var z0p1 = Int(readLine()!)!
//var z0p2 = Int(readLine()!)!
//var z0p3 = Int(readLine()!)!
//var z0 = RzutOszczepem(id: 0, proba1: z0p1, proba2: z0p2, proba3: z0p3)
//
//print("Zawodnik 1")
//var z1p1 = Int(readLine()!)!
//var z1p2 = Int(readLine()!)!
//var z1p3 = Int(readLine()!)!
//var z1 = RzutOszczepem(id: 1, proba1: z1p1, proba2: z1p2, proba3: z1p3)
//
//print("Zawodnik 2")
//var z2p1 = Int(readLine()!)!
//var z2p2 = Int(readLine()!)!
//var z2p3 = Int(readLine()!)!
//var z2 = RzutOszczepem(id: 2, proba1: z2p1, proba2: z2p2, proba3: z2p3)
//
//print("Zawodnik 3")
//var z3p1 = Int(readLine()!)!
//var z3p2 = Int(readLine()!)!
//var z3p3 = Int(readLine()!)!
//var z3 = RzutOszczepem(id: 3, proba1: z3p1, proba2: z3p2, proba3: z3p3)
//
//print("Wygrał:")
//var maxs = max(z0.srednia(), z1.srednia(), z2.srednia(), z3.srednia())
//switch maxs {
//case z0.srednia():
//    z0.show()
//case z1.srednia():
//    z1.show()
//case z2.srednia():
//    z2.show()
//case z3.srednia():
//    z3.show()
//default:
//    print("")
//}




//Zad3
//var samochody = Set<String>()
//
//samochody.insert("Audi")
//samochody.insert("Mazda")
//samochody.insert("Peugeot")
//samochody.insert("BMW")
//samochody.insert("Tesla")
//samochody.insert("Citroen")
//
//print(samochody)
//
//print("Podaj model")
//
//var model: String = readLine()!
//
//if (samochody.remove(model) != nil) {
//    samochody.remove(model)
//}
//print(samochody)






var student: [String: Int] = [:]

for i in 0..<5 {
    print("Student \(i)")
    var nazwisko = readLine()!
    var index = Int(readLine()!)!
    student[nazwisko] = index
}

print(student)
