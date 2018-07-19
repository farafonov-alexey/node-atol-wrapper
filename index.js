const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
// fptr.test();
// console.log(fptr);
fptr.create();
console.log(fptr.getSettings());
fptr.destroy();
