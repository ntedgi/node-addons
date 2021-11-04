# node-addons

boiler plattin github addons
basic example
* return value from V8
* GC handling

fn_string_handle.cc
`
const bindings = require('bindings')
const addon = bindings('myaddon')
addons.print(":-)")
logging this line in C++
`

fn_with_return_fucntion
`
const bindings = require('bindings')
const addon = bindings('myaddon')
const len = addons.print("str")
return len of utf8 from C++
`

v8_timeout_with_cb.cc
`
const bindings = require('bindings')
const addon = bindings('myaddon')
addon.delay(5000, () => {
    console.log('hello world')
})
block js at C++ side 
`

v8_timeout_js_non_blocking.cc
`
const bindings = require('bindings')
const addon = bindings('myaddon')
addon.delay(5000, () => {
    console.log('hello world')
})
non blockin js new thread runing at C++ side 
`
