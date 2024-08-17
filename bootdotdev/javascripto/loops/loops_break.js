const movieExists = (movies, title) => {
  console.log(`Looking for: ${title}`)
  for (let i = 0; i < movies.length; i++) {
    if (movies[i] === title) {
      console.log(`Found: ${title}`)
      break
    }
  }
}

// don't touch below this line

movieExists([ 'Incredibles', 'Tangled', 'Frozen' ], 'Frozen')
console.log('---')
movieExists([ 'The Quick and the Dead', 'The Magnificent 7', 'Frozen' ], 'The Magnificent 7')
console.log('---')
movieExists([ 'Dead', 'Alive', 'Flight', 'Rocky' ], 'Flight')
console.log('---')
movieExists([ 'Dead', 'Alive', 'Flight', 'Rocky' ], 'None')
console.log('---')
