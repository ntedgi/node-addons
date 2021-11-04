var bindings = require('bindings')
var addon = bindings('myaddon')

const str = process.argv[2]
const res = addon.length(str)
console.log(res)