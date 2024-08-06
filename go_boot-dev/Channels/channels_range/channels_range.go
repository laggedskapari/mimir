package main

func concurrentFib(n int) [] int {
  result := []int{}
  fibChan := make(chan int)
  go fibonacci(n, fibChan)

  for res := range fibChan {
    result = append(result, res)
  }
  return result
}

func fibonacci(n int, ch chan int) {
  x, y := 0, 1
  for i := 0; i < n; i++ {
    ch <- x
    x, y = y, x+y
  }
  close(ch)
}
