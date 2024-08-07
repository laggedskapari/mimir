package main

import (
	"fmt"
	"time"
)

func sieveOfEratosthenes(max int) {
	primes := make([]bool, max+1)

  start := time.Now()

	for i := 1; i < max+1; i++ {
    primes[i] = true
	}

  // for i := 1; i < max + 1; i++ {
  //   if primes[i] {
  //     fmt.Println("1")
  //   }else {
  //     println("0")
  //   }
  // }

	for i := 2; i*i <= max; i++ {
		if primes[i] {
			for j := i * 2; j <= max; j = j+i {
				primes[j] = false
			}
		}
	}

	elapse := time.Since(start)
	count := 0
	for i := 2; i <= max; i++ {
		if primes[i] {
			fmt.Printf("%d ", i)
			count++
		}
	}
	fmt.Println("\nNum Primes:", count,
		"time: ", elapse.Microseconds())
}

func main() {
  sieveOfEratosthenes(100)
}
