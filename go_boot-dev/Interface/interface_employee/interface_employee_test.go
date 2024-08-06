package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	type testCase struct {
		emp      employee
		expected int
	}
	tests := []testCase{
		{fullTime{name: "Bob", salary: 7300}, 7300},
		{contractor{name: "Jill", hourlyPay: 872, hoursPerYear: 982}, 856304},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{fullTime{name: "Alice", salary: 10000}, 10000},
			{contractor{name: "John", hourlyPay: 1000, hoursPerYear: 1000}, 1000000},
		}...)
	}

	for _, test := range tests {
		salary := test.emp.getSalary()
		if salary != test.expected {
			t.Errorf(`Test Failed: %+v ->
	expected: %v
	actual: %v
`,
				test.emp, test.expected, salary)
		} else {
			fmt.Printf(`Test Passed: %+v ->
	expected: %v
	actual: %v
`,
				test.emp, test.expected, salary)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
