package main

type employee interface {
  getName() string
  getSalary() int
}

type contractor struct {
  name string
  hourlyPay int
  hoursPerYear int 
}

type fullTime struct {
  name string 
  salary int
}

func (c contractor) getName() string {
  return c.getName()
}

func (c contractor) getSalary() int {
  return c.hourlyPay * c.hoursPerYear
}

func (f fullTime) getName() string {
  return f.getName()
}

func (f fullTime) getSalary() int {
  return f.salary
}
