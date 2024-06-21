import Foundation

class Person {
    var name: String
    var age: Int

    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }

    func increaseAge() {
        self.age += 1
    }
}

let rajat = Person(name: "Rajat Yadav", age: 22)
rajat.age
rajat.increaseAge()
rajat.age

// Reference

let rajat2 = rajat
rajat2.increaseAge()
rajat.age

// Memory equality check

if rajat2 === rajat {
    "Pointing to the same memory."
} else {
    "Not same memory location."
}

//Inheritance

class Vehicle {
    func goVroom() {
        "Vroom Vroom"
    }
}

class Car: Vehicle {

}

let newCar = Car()
newCar.goVroom()

// Private Members

class Person2 {
    private(set) var age: Int
    init(age: Int) {
        self.age = age
    }

    func increaseAge() {
        self.age += 1
    }
}

let dushyant = Person2(age: 10)
dushyant.increaseAge()
dushyant.age

//Convenience, Designated and Inheritance of Init

class Tesla {
    private(set) var model: String
    private(set) var year: Int
    private(set) var manufacturer = "Tesla"

    init() {
        self.model = "X"
        self.year = 2023
    }

    init(model: String, year: Int) {
        self.model = model
        self.year = year
    }

    convenience init(model: String) {
        self.init(model: model, year: 2023)
    }
}

class TeslaModelY: Tesla {
    override init() {
        super.init(model: "Y", year: 2023)
    }
}

let modelY = TeslaModelY()
modelY.model
modelY.year
modelY.manufacturer

func doSomething(with person: Person2) {
    person.increaseAge()
}

doSomething(with: dushyant)

dushyant.age

// Deinitializer

class MyClass {
    init() {
        "Initialized"
    }
    func doSomething() {
        "Did Something"
    }
    deinit {
        "DeInitialized"
    }
}

let myClosure = {
    let myClass = MyClass()
    myClass.doSomething()
}

myClosure()
