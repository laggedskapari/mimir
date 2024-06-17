import Foundation

// init use
struct Commodore {
    let name: String
    let manufacturer: String
    init(name: String) {
        self.name = name
        manufacturer = "Commodore"
    }
}

let c64 = Commodore(name: "C64")
c64.name
c64.manufacturer

// Computed Properties

struct Person {
    let firstName: String
    let lastName: String
    var fullName: String {
        "\(firstName) \(lastName)"
    }
}

let personOne = Person(firstName: "Rajat", lastName: "Yadav")
personOne.fullName

// Mutatuing Structures

struct Car {
    var currentSpeed: Int
    mutating func drive(speed: Int) {
        "Driving..."
        currentSpeed = speed
    }
}

let immutableCar = Car(currentSpeed: 20)

var mutableCar = Car(currentSpeed: 40)
mutableCar.drive(speed: 100)
mutableCar.currentSpeed

var copyMutableCar = mutableCar
copyMutableCar.currentSpeed

mutableCar.drive(speed: 200)
copyMutableCar.currentSpeed
mutableCar.currentSpeed

// Custom Copies of Struct

struct Bike {
    let manufacturer: String
    let currentSpeed: Int
    func copyWith(speed: Int) -> Bike {
        Bike(
            manufacturer: manufacturer,
            currentSpeed: speed
        )
    }
}

let bike1 = Bike(manufacturer: "HD", currentSpeed: 40)
let bike2 = bike1.copyWith(speed: 100)

bike1.currentSpeed
bike2.currentSpeed

