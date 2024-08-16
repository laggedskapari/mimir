function getIsPowerUser(numReviews) {
  return numReviews > 10 
}

// don't touch below this line

function test(numReviews) {
  const isPowerUser = getIsPowerUser(numReviews)
  console.log(`Number of reviews: ${numReviews}, is power user: ${isPowerUser}`)
}

test(100)
test(50)
test(10)
test(5)
test(2)
