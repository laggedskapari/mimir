package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		numMessages int
		expected    float64
	}
	tests := []testCase{
		{10, 10.45},
		{20, 21.9},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{0, 0.0},
			{1, 1.0},
			{5, 5.10},
			{30, 34.35},
		}...)
	}

	for _, test := range tests {
		if output := bulkSend(
			test.numMessages,
		); fmt.Sprintf("%.2f", output) != fmt.Sprintf("%.2f", test.expected) {
			t.Errorf(
				"Test Failed: (%v) => expected: %.2f, actual: %.2f",
				test.numMessages,
				test.expected,
				output,
			)
		} else {
			fmt.Printf("Test Passed: (%v) => expected: %.2f, actual: %.2f\n",
				test.numMessages,
				test.expected,
				output,
			)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
