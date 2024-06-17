import Foundation

let myName = "Rajat Yadav"
let yourName = "foo"

var name = [myName, yourName]

let firstName = "Rajat"
var lastName = firstName

lastName = "Yadav"
firstName

let firstArray = ["Qi", "Yo"]
var copy = firstArray

copy.append("Qi 2")
firstArray

let oldArray = NSMutableArray(
  array: [
    "Qi",
    "Qi 2"
  ]
)

func changeInternal(_ array: NSArray) {
  let copy = array as! NSMutableArray
  copy.add("Qi 4")
}

changeInternal(oldArray)
oldArray

var newArray = oldArray
newArray.add("Qi 3")
oldArray
