const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
fptr.create();
let settings = fptr.getSettings();
settings.Port = 0;  // ComPort communication
// settings.ComFile = '/dev/ttyACM0'; //ComPort name
settings.ComFile = 'COM5';  // ComPort name
settings.BaudRate = 115200;
settings.GrpcServerPort = 4041;
console.log('setSettings', fptr.setSettings(settings));
settings = fptr.getSettings();
console.log('getSettings', settings);
console.log('isOpened', fptr.isOpened());
console.log('open', fptr.open());

console.log('isOpened', fptr.isOpened());
// console.log('getData', fptr.processJson({type: 'getDeviceStatus'}));
// console.log('findLastDocument', fptr.findLastDocument());

setTimeout(() => {
    console.log('close', fptr.close());
}, 300000)



