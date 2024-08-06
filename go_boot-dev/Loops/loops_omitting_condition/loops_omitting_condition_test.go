package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		thresh   int
		expected int
	}
	tests := []testCase{
		{103, 1},
		{205, 2},
		{1000, 9},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{100, 1},
			{3000, 26},
			{4000, 34},
			{5000, 41},
			{0, 0},
		}...)
	}

	for _, test := range tests {
		if output := maxMessages(test.thresh); output != test.expected {
			t.Errorf("Test Failed: (%v) => expected: %v, got: %v\n", test.thresh, test.expected, output)
		} else {
			fmt.Printf("Test Passed: (%v) => expected: %v, got: %v\n", test.thresh, test.expected, output)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
