package main

func monthlyBillIncrease(costPerSend, numLastMonth, numThisMonth int) int {
  var lastMonthBill int
  var thisMonthBill int 

  lastMonthBill = getBillForMonth(lastMonthBill, costPerSend, numLastMonth)
  thisMonthBill = getBillForMonth(thisMonthBill, costPerSend, numThisMonth)

  return thisMonthBill - lastMonthBill
}

func getBillForMonth(bill, costPerSend, messageSent int) int {
  return costPerSend * messageSent
}
