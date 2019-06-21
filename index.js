const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
fptr.create();
const settings = fptr.getSettings();
console.log('getSettings', settings);
settings.Port = 0; //ComPort communication
settings.ComFile = '/dev/ttyACM0'; //ComPort name
settings.BaudRate = 115200;
console.log('setSettings', fptr.setSettings(settings));
console.log('isOpened', fptr.isOpened());
console.log('open', fptr.open());

console.log('isOpened', fptr.isOpened());
console.log('getData', fptr.processJson({type: 'getDeviceStatus'}));
console.log('findLastDocument', fptr.findLastDocument());
// try {
//     console.log('fnReport', fptr.fnReport(1));
// } catch (e) {
//     console.log('error', e.message, 'code', e.code, 'descr', e.description);
// }
// console.log('openShift', fptr.processJson({
//     type: 'openShift',
//
//     operator: {
//        name: 'Иванов',
//        vatin: '123654789507'
//     },
//
//     postItems: [
//         {
//             type: 'text',
//             text: 'ОТКРЫТА НОВАЯ СМЕНА',
//             alignment: 'center',
//             doubleWidth: true
//         }
//     ]
// }));
// console.log('closeShift', fptr.processJson({
//     type: 'closeShift',
//     operator: {
//         name: 'Иванов',
//         vatin: '123654789507'
//     }
// }));
console.log('close', fptr.close());
fptr.destroy();
