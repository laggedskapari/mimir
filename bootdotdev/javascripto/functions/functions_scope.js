function isMovieValid(title) {
  function movieLength(title) {
    const len = title.length
    return len
  }

  // don't touch above this line

  const len = movieLength(title)
  return len > 2
}

// don't touch below this line

function test(title) {
  const valid = isMovieValid(title)
  console.log(`'${title}' is valid: ${valid}`)
}

test('The League of Extraordinary Gentlemen')
test('Hunt for Red October')
test('007')
test('')
test('12')
