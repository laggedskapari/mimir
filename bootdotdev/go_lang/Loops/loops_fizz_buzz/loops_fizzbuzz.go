package main

func fizzbuzz() {
  for i := 1; i <= 100; i++ {
    if i % 3 == 0 && i % 5 == 0 {
      println("fizzbuzz")
    } else if (i % 3 == 0) {
      println("fizz")
    } else if (i % 5 == 0) {
      println("buzz")
    }
  }
}

func main() {
  fizzbuzz()
}
