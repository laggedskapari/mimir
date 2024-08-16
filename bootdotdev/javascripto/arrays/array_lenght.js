const getMostRecentUser = (usernames) => {
  return usernames.length ? usernames[usernames.length - 1] : null
}

// don't touch below this line

console.log(`Most recent user: ${getMostRecentUser(
  []
)}`)

console.log(`Most recent user: ${getMostRecentUser(
  [
    'johndoe123',
    'billyrae456'
  ]
)}`)

console.log(`Most recent user: ${getMostRecentUser(
  [
    'wagslane',
    'jimmyjohn',
    'bopeep',
    'strightkilla',
    'reddyman'
  ]
)}`)
