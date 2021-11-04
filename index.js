const bindings = require('bindings')
const addon = bindings('myaddon')
addon.delay(5000, () => {
    console.log('hello world')
})