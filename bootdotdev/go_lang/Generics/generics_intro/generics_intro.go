package main

func getLast[T any](s []T) T {
  var zeroValue T
  if len(s) <= 0 {
    return zeroValue
  }
  return s[len(s) - 1]
}
