package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		costMultiplier   float64
		maxCostInPennies int
		expected         int
	}
	tests := []testCase{
		{1.1, 5, 17},
		{1.3, 10, 9},
		{1.35, 25, 11},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{1.2, 15, 15},
			{1.3, 20, 12},
		}...)
	}

	for _, test := range tests {
		if output := getMaxMessagesToSend(test.costMultiplier, test.maxCostInPennies); output != test.expected {
			t.Errorf("Test Failed: (%v, %v) -> expected: %v actual: %v", test.costMultiplier, test.maxCostInPennies, test.expected, output)
		} else {
			fmt.Printf("Test Passed: (%v, %v) -> expected: %v actual: %v\n", test.costMultiplier, test.maxCostInPennies, test.expected, output)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
