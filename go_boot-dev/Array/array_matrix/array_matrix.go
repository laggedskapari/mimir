package main

func createMatrix(rows, cols int) [][]int {
  resultMatrix := make([][]int, rows)
  for i := 0; i < rows; i++ {
    resultMatrix[i] = make([]int, cols)
    for j := 0; j < cols; j++ {
      resultMatrix[i][j] = i * j
    }
  }
  return resultMatrix
}

func main() {
  createMatrix(3, 3)
}
