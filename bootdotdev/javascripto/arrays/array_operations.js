function getCleanRank(reviewWords) {
  let curseCount = 0;
  if (reviewWords.includes('dang')) {
    curseCount++;
  }

  if (reviewWords.includes('shoot')) {
    curseCount++;
  }

  if (reviewWords.includes('heck')) {
    curseCount++;
  }

  if (curseCount > 0) {
    return curseCount >= 2 ? 'filthy' : 'dirty'
  }

  return 'clean'
}

function test(reviewWords) {
  const cleanRank = getCleanRank(reviewWords)
  console.log(`'${reviewWords}' has rank: ${cleanRank}`)
}

test(['avril', 'lavigne', 'has', 'best', 'dang', 'tour'])
test(['what', 'a', 'bad', 'film'])
test(['oh', 'my', 'heck', 'I', 'hated', 'it'])
test(['ripoff'])
test(['That', 'was', 'a', 'pleasure'])
test(['shoot!', 'I', 'cant', 'say', 'I', 'liked', 'the', 'dang', 'thing'])
test(['shoot', 'dang', 'heck'])
