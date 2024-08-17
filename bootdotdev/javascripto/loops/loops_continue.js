const printCleanReviews = (reviews, badWord) => {
  for (let i = 0; i < reviews.length; i++) {
    if (reviews[i].includes(badWord)) {
      continue;
    }
    console.log(reviews[i])
  }
}

// don't touch below this line

printCleanReviews([ 'The movie sucks', 'I love it', 'What garbage', 'so sucky' ], 'suck')
console.log('---')
printCleanReviews([ 'The movie sucks', 'I love it', 'What darn crap', 'darn, so sucky' ], 'darn')
console.log('---')
