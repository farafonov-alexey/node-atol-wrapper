const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
// fptr.test();
// console.log(fptr);
fptr.create();
const settings = fptr.getSettings();
console.log('getSettings', settings );
settings.Port = 0; //ComPort communication
settings.ComFile = 'COM5'; //ComPort name
settings.BaudRate = 115200;
console.log('setSettings', fptr.setSettings(settings));
console.log('open', fptr.open());

console.log('getData', fptr.processJson({ type: 'getDeviceStatus' }));

console.log('close', fptr.close());
fptr.destroy();
