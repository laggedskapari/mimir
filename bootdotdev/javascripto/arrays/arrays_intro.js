const movies = []
movies.push('the dark knight')

logArray(movies)

movies.push('the notebook')

logArray(movies)

console.log(movies[0])
// don't touch below this line

function logArray(arr) {
  console.log('logging array...')
  for (const a of arr) {
    console.log(` - ${a}`)
  }
  console.log('---')
}

