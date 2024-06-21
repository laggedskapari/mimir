// package main
//
// import (
// 	"fmt"
// 	"testing"
// )
//
// func Test(t *testing.T) {
// 	type testCase struct {
// 		age                   int
// 		exYearsUntilAdult     int
// 		exYearsUntilDrinking  int
// 		exYearsUntilCarRental int
// 	}
// 	tests := []testCase{
// 		{4, 14, 17, 21},
// 		{18, 0, 3, 7},
// 		{22, 0, 0, 3},
// 	}
// 	if withSubmit {
// 		tests = append(tests, []testCase{
// 			{25, 0, 0, 0},
// 			{35, 0, 0, 0},
// 		}...)
// 	}
//
// 	for _, test := range tests {
// 		if yearsUntilAdult, yearsUntilDrinking, yearsUntilCarRental := yearsUntilEvents(
// 			test.age,
// 		); yearsUntilAdult != test.exYearsUntilAdult ||
// 			yearsUntilDrinking != test.exYearsUntilDrinking ||
// 			yearsUntilCarRental != test.exYearsUntilCarRental {
// 			t.Errorf(
// 				"Test Failed: (%v) -> expected: (%v, %v, %v) actual: (%v, %v, %v)",
// 				test.age,
// 				test.exYearsUntilAdult,
// 				test.exYearsUntilDrinking,
// 				test.exYearsUntilCarRental,
// 				yearsUntilAdult,
// 				yearsUntilDrinking,
// 				yearsUntilCarRental,
// 			)
// 		} else {
// 			fmt.Printf("Test Passed: (%v) -> expected: (%v, %v, %v) actual: (%v, %v, %v)\n",
// 				test.age,
// 				test.exYearsUntilAdult,
// 				test.exYearsUntilDrinking,
// 				test.exYearsUntilCarRental,
// 				yearsUntilAdult,
// 				yearsUntilDrinking,
// 				yearsUntilCarRental,
// 			)
// 		}
// 	}
// }
//
// // withSubmit is set at compile time depending
// // on which button is used to run the tests
// var withSubmit = true
