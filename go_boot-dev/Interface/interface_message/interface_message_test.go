package main

import (
	"fmt"
	"testing"
	"time"
)

func Test(t *testing.T) {
	type testCase struct {
		msg          message
		expectedText string
		expectedCost int
	}
	tests := []testCase{
		{birthdayMessage{time.Date(1994, 03, 21, 0, 0, 0, 0, time.UTC), "John Doe"},
			"Hi John Doe, it is your birthday on 1994-03-21T00:00:00Z",
			168,
		},
		{sendingReport{"First Report", 10},
			`Your "First Report" report is ready. You've sent 10 messages.`,
			183,
		},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{birthdayMessage{time.Date(1934, 05, 01, 0, 0, 0, 0, time.UTC), "Bill Deer"},
				"Hi Bill Deer, it is your birthday on 1934-05-01T00:00:00Z",
				171,
			},
			{sendingReport{"Second Report", 20},
				`Your "Second Report" report is ready. You've sent 20 messages.`,
				186,
			},
		}...)
	}

	for _, test := range tests {
		text, cost := sendMessage(test.msg)
		if text != test.expectedText || cost != test.expectedCost {
			t.Errorf(
				`Test Failed: %+v ->
	expected: (%v, %v)
	actual: (%v, %v)
`,
				test.msg,
				test.expectedText,
				test.expectedCost,
				text,
				cost,
			)
		} else {
			fmt.Printf(
				`Test Passed: %+v ->
	expected: (%v, %v)
	actual: (%v, %v)
`,
				test.msg,
				test.expectedText,
				test.expectedCost,
				text,
				cost,
			)
		}
	}
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
