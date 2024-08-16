const isBigHit = true
const isNew = true
const hasAwards = false
const canHaveSequel = true
const isRatedX = false

// don't touch above this line

const isBlockBuster = isBigHit && isNew && (hasAwards || canHaveSequel) && !isRatedX

// don't touch below this line

console.log(`The movie is a blockbuster: ${isBlockBuster}`)
