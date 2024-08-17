const author = {
  name: 'Simon Garfunkle',
  numReviews: 8,
  submitReview() {
    this.numReviews++;
  }
}

// don't touch below this line

console.log(`${author.name} has submitted ${author.numReviews} reviews`)

console.log(`${author.name} is submitting a review...`)
author.submitReview()
console.log(`${author.name} has submitted ${author.numReviews} reviews`)

console.log(`${author.name} is submitting a review...`)
author.submitReview()
console.log(`${author.name} has submitted ${author.numReviews} reviews`)

console.log(`${author.name} is submitting a review...`)
author.submitReview()
console.log(`${author.name} has submitted ${author.numReviews} reviews`)

console.log(`${author.name} is submitting a review...`)
author.submitReview()
console.log(`${author.name} has submitted ${author.numReviews} reviews`)
