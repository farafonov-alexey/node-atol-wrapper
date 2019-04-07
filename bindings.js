const process = require('process');
let mod;
if (process.env.DEBUG) {
    mod = require('./build/Debug/node_atol_wrapper');
} else {
    mod = require('./build/Release/node_atol_wrapper');
}
module.exports = mod;
