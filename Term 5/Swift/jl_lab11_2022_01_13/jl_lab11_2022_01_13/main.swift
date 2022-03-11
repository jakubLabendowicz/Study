//
//  main.swift
//  jl_lab11_2022_01_13
//
//  Created by student on 13/01/2022.
//  Copyright © 2022 PL. All rights reserved.
//

import Foundation

class Prostakat {
    var edgeA: Double
    var edgeB: Double
    
    init(edgeA: Double, edgeB: Double) {
        self.edgeA = edgeA
        self.edgeB = edgeB
    }
    
    func pole() -> Double {
        return edgeA * edgeB
    }
    
    func obwod() -> Double {
        return 2*edgeA + 2*edgeB
    }
    
    func show() -> () {
        print("Pole: \(pole()) Obwód: \(obwod())")
    }
}

var prostakat = Prostakat(edgeA: 5.0,edgeB: 2.0)
prostakat.show()

class Prostopadloscan: Prostakat {
    var height: Double
    
    init(edgeA: Double, edgeB: Double, height: Double) {
        self.height = height
        super.init(edgeA: edgeA, edgeB: edgeB)
    }
    
    override func pole() -> Double {
        return 2 * edgeA * edgeB + 2 * edgeA * height + 2 * edgeB * height
    }
    
    override func obwod() -> Double {
        return 4*edgeA + 4*edgeB + 4*height
    }
    
    func objetosc() -> Double {
        return edgeA * edgeB * height
    }
    
    override func show() -> () {
        print("Pole: \(pole()) Obwód: \(obwod()) Objetosc: \(objetosc())")
    }
}

var prostopadloscan = Prostopadloscan(edgeA: 5.0, edgeB: 2.0, height: 3.0)
prostopadloscan.show()

class Osoba {
    var imie: String
    var nazwisko: String
    var rokUrodzenia: Int
    
    init(imie: String, nazwisko: String, rokUrodzenia: Int) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rokUrodzenia = rokUrodzenia
    }
    
    func wiek() -> Int {
        return 2022 - rokUrodzenia
    }
    
    func show() -> () {
        print("Imię: \(imie) Nazwisko: \(nazwisko) Rok urodzenia: \(rokUrodzenia)")
    }
}

class Student: Osoba {
    static func create() -> Student {
        let imie: String = readLine()!
        let nazwisko: String = readLine()!
        let rokUrodzenia: Int = Int(readLine()!)!
        let numerIndexu: Int = Int(readLine()!)!
        var kierunekStudiow: Set<String>
        var rokStudiow: Int = Int(readLine()!)!
        var przedmiot1: String = readLine()!
        var ocena1: Double = Double(readLine()!)!
        var przedmiot2: String = readLine()!
        var ocena2: Double = Double(readLine()!)!
        var przedmiot3: String = readLine()!
        var ocena3: Double = Double(readLine()!)!
        var przedmiot4: String = readLine()!
        var ocena4: Double = Double(readLine()!)!
        var przedmiot5: String = readLine()!
        var ocena5: Double = Double(readLine()!)!
        
        var student = Student(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia, numerIndexu: numerIndexu, kierunekStudiow: <#T##Set<String>#>, rokStudiow: rokStudiow, oceny: [przedmiot1: ocena1, przedmiot2: ocena2, przedmiot3: ocena3, przedmiot4: ocena4, przedmiot5: ocena5])
        return student
    }
    
    var numerIndexu: Int
    var kierunekStudiow: Set<String>
    var rokStudiow: Int
    var oceny: [String: Double]
    
    init(imie: String, nazwisko: String, rokUrodzenia: Int, numerIndexu: Int, kierunekStudiow: Set<String>, rokStudiow: Int, oceny: [String: Double]) {
        self.numerIndexu = numerIndexu
        self.kierunekStudiow = kierunekStudiow
        self.rokStudiow = rokStudiow
        self.oceny = oceny
        for ocena in oceny {
            if ocena.value < 2.0 || ocena.value > 5.0 {
                self.oceny.removeValue(forKey: ocena.key)
            }
        }
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia)
    }
    
    func srednia() -> Double {
        var suma = 0.0
        for ocena in oceny {
            suma += ocena.value
        }
        return suma/Double(oceny.count)
    }
    
    override func show() -> () {
        print("Imię: \(imie) Nazwisko: \(nazwisko) Rok urodzenia: \(rokUrodzenia) Numer indexu: \(numerIndexu) Kierunek studiów: \(kierunekStudiow) Rok studiów: \(rokStudiow) Oceny:")
        for ocena in oceny {
            print("\(ocena.key) - \(ocena.value)")
        }
    }
}
