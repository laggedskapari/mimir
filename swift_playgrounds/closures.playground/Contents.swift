import Foundation

let add: (Int, Int) -> Int = {
    (lhs: Int, rhs: Int) -> Int in
    lhs + rhs
}

add(10, 20)

// Trailing Syntax

func customAdd(_ lhs: Int, _ rhs: Int, using doubleIt: (Int, Int) -> Int) -> Int {
    doubleIt(lhs, rhs)
}

customAdd(10, 20) { (lhs: Int, rhs: Int) -> Int in
    (lhs + rhs) * 2
}

// Ascending and Descending Sort
 var newArray = [10, 20, 30, 10, 15, 19]
newArray.sorted { (lhs: Int, rhs: Int) -> Bool in
 lhs < rhs
}

//Shorthand
newArray.sorted(by: >)

func customAdd2(_ lhs: Int, _ rhs: Int, using doubleIt: (Int, Int) -> Int) -> Int  {
  doubleIt(lhs, rhs)
}

customAdd2(80, 20) { (lhs: Int, rhs: Int) -> Int in
  (lhs + rhs) * 2
}

func add20To(_ value: Int) -> Int {
  value + 20
}

func doAddition(on value: Int, using addToFunc: (Int) -> Int) -> Int {
  addToFunc(value)
}

doAddition(on: 30, using: add20To(_:))
