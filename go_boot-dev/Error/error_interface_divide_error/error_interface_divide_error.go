package main

import "fmt"

type divideError struct {
  divident float64
}

func (d divideError) Error() string {
  return fmt.Sprintf("can not divide %v by zero", d.divident)
}

func divide(divident, divisor float64) (float64, error) {
  if divisor == 0 {
    return 0, divideError{divident: divident}
  }
  return divident / divisor, nil
}
