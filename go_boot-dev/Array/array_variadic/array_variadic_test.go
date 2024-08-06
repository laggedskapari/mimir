package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		nums     []int
		expected int
	}

	var tests = []testCase{
		{[]int{1, 2, 3}, 6},
		{[]int{1, 2, 3, 4, 5}, 15},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 55},
			{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 120},
			{[]int{}, 0},
			{[]int{5}, 5},
		}...)
	}

	for _, test := range tests {
		if output := sum(test.nums...); output != test.expected {
			t.Errorf(`Test Failed:
%v
=>
expected:
%v
actual:
%v
===========================
`,
				sliceWithBullets(test.nums),
				test.expected,
				output,
			)
		} else {
			fmt.Printf(`Test Passed:
%v
=>
expected:
%v
actual:
%v
===========================
			`,
				sliceWithBullets(test.nums),
				test.expected,
				output,
			)
		}
	}
}

func sliceWithBullets[T any](slice []T) string {
	if slice == nil {
		return "  <nil>"
	}
	if len(slice) == 0 {
		return "  []"
	}
	output := ""
	for i, item := range slice {
		form := "  - %#v\n"
		if i == (len(slice) - 1) {
			form = "  - %#v"
		}
		output += fmt.Sprintf(form, item)
	}
	return output
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
