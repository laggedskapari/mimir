import Foundation

// Enumerations
enum Animals {
  case Cat, Dog, Rabbit, HedgeHog
}

let cat = Animals.Cat

if cat == Animals.Cat {
    "This is a cat."
} else if cat == Animals.Dog {
    "This is a dog."
} else {
    "I don't know what is it."
}

// Switch Case
switch cat {
case .Cat:
    "This is a cat."
    break
case .Dog:
    "This is a dog."
    break
case .Rabbit:
    "This is Rabit."
    break
case .HedgeHog:
  "This is a HedgeHog."
  break
}

// Enumerations with associative value

enum Shortcut {
  case fileOrFolder(path: URL, name: String)
  case wwURL(path: URL)
  case song (artist: String, songName: String)
}

let apple = Shortcut.wwURL(path: URL(filePath: "https://apple.com")!)

switch apple {
case let .fileOrFolder(path, name):
  path
  name
  break
case let .wwURL(path):
  path
  break
case let .song(artist, songName):
  artist
  songName
  break
}

if case let .wwURL(path) = apple {
  path
}

let tellmewhy = Shortcut.song(artist: "The Kid Laroi", songName: "Tell me why.")

if case let .song(_, songName) = tellmewhy {
  songName
}

// Associated Value and Enums Computed Value

enum Vehicle {
  case Car(Manufacturer: String, Model: String)
  case Bike(Manufacturer: String, Year: Int)
  var Manufacturer: String {
    switch self {
    case let .Car(Manufacturer, _), let .Bike(Manufacturer, _):
      return Manufacturer
    }
  }
}

let bike = Vehicle.Bike(Manufacturer: "HD", Year: 1987)
let car = Vehicle.Car(Manufacturer: "Tesla", Model: "X")

bike.Manufacturer
car.Manufacturer

// Raw Values

enum FamilyMembers: String {
    case Father = "Dad"
    case Mother = "Mom"
    case Brother = "Bro"
    case Sister = "Sis"
}

FamilyMembers.Father.rawValue
FamilyMembers.Mother.rawValue
FamilyMembers.Sister.rawValue
FamilyMembers.Brother.rawValue

//Enumeration Iterable

enum FavoriteEmoji: String, CaseIterable {
    case blush = "BLEMOJI"
    case rocket = "ROCKET"
    case fire = "FIRE"
}

FavoriteEmoji.allCases
FavoriteEmoji.allCases.map(\.rawValue)

if let blush = FavoriteEmoji(rawValue: "BLEMOJI") {
    "Found the blush emoji."
} else {
    "This emoji doesn't exists."
}

if let snow = FavoriteEmoji(rawValue: "SNOW") {
    "Really, Snow exists ?"
} else {
    "No, Snow doesn't exists."
}

// Mutating Members 
enum Height {
    case Short, Medium, Long
    mutating func makeLong() {
        self = Height.Long
    }
}

var myHeight = Height.Short
myHeight.makeLong()
myHeight

// Reference Itself

indirect enum IntOperation {
    case add(Int, Int)
    case subtract(Int, Int)
    case freeHand(IntOperation)

    func calculateResult(of operation: IntOperation? = nil) -> Int {
        switch operation ?? self {
        case let .add(lhs, rhs):
            return lhs + rhs
        case let .subtract(lhs, rhs):
            return lhs - rhs
        case let .freeHand(operation):
            return calculateResult(of: operation)
        }
    }
}

let freeHand = IntOperation.freeHand(.add(10, 30))
freeHand.calculateResult()





