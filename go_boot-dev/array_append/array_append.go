package main

type cost struct {
	day   int
	value float64
}

func getCostsByDay(costs []cost) []float64 {
	largestDate := 0

	for i := 0; i < len(costs); i++ {
		if costs[i].day >= largestDate {
			largestDate = costs[i].day + 1
		}
	}

	dayTotalArray := make([]float64, largestDate)
	resultArray := make([]float64, 0)

	for i := 0; i < largestDate; i++ {
		dayTotal := 0.0
		for j := 0; j < len(costs); j++ {
			if costs[j].day == i {
				dayTotal += costs[j].value
			}
		}
		dayTotalArray[i] = dayTotal
	}
	return append(resultArray, dayTotalArray...)
}

// func main() {
// 	costs := []cost{
// 		{0, 1.0},
// 		{1, 2.0},
// 		{1, 3.1},
// 		{5, 2.5},
// 		{2, 3.6},
// 		{1, 2.7},
// 		{1, 3.3},
// 	}
//
// 	getCostsByDay(costs)
// }
