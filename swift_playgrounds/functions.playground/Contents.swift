import Foundation

func noArgAndNoReturnValueFunc() {
  "I don't know what I'm doing"
}

// Funtion with argument
func addNumbers(value1: Int, value2: Int) -> Int {
  value1 + value2
}

var result = addNumbers(value1: 20, value2: 40)

// External Parameters
func minusNumbers(_ lhs: Int, _ rhs: Int) -> Int {
  lhs - rhs
}

result = minusNumbers(10, 5)

// Discardable Result
@discardableResult
func myCustomAdd(_ lhs: Int, _ rhs: Int) -> Int {
  lhs + rhs
}

myCustomAdd(30, 30)

// Internal Functions

func doSomethingComplicated(with value: Int) -> Int {
  func mainLogic(value: Int) -> Int {
    value + 3
  }
  return mainLogic(value: value + 2)
}

result = doSomethingComplicated(with: 30)

// Default Params value
func getFullName(firstName: String = "Rajat", lastName: String = "Yadav") -> String {
  "\(firstName) \(lastName)"
}

getFullName(firstName: "Dushyant", lastName: "Yadav")

