package main

import (
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		tier     string
		expected string
	}
	tests := []testCase{
		{"basic", "You get 1,000 texts per month for $30 per month."},
		{"premium", "You get 50,000 texts per month for $60 per month."},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{"enterprise", "You get unlimited texts per month for $100 per month."},
		}...)
	}

	for _, test := range tests {
		if output := getProductMessage(
			test.tier,
		); output != test.expected {
			t.Errorf(
				"Test Failed: (%v) -> expected: %v actual: %v",
				test.tier,
				test.expected,
				output,
			)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
