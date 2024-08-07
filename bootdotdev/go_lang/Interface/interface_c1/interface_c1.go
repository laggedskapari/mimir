package main

import "fmt"

type PlainText struct {
  message string
}

type Bold struct {
  message string
}

type Code struct {
  message string
}

type Formatter interface {
  Format() string
}

func (p PlainText) Format() string {
  return p.message
}

func (b Bold) Format() string {
  return fmt.Sprintf("**%s**", b.message)
}

func (c Code) Format() string {
  return fmt.Sprintf("`%s`", c.message)
}

func SendMessage(formatter Formatter) string {
	return formatter.Format() // Adjusted to call Format without an argument
}
