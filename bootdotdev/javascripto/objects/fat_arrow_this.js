const server = {
  port: 8080,
  name: 'MovieStarz',
  getLogs() {
    return `Starting ${this.name} server on ${this.port}`
  }
}

// don't touch below this line

const logs = server.getLogs()
console.log(logs)
