const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
fptr.create();
const settings = fptr.getSettings();
console.log('getSettings', settings);


//RS232 connection:
settings.Port = 0; //ComPort communication
settings.ComFile = '/dev/ttyACM0'; //ComPort name
settings.BaudRate = 115200;


//USB connection:
// settings.Port = 1;



console.log('setSettings', fptr.setSettings(settings));
console.log('isOpened', fptr.isOpened());
console.log('open', fptr.open());

console.log('isOpened', fptr.isOpened());
fptr.processJson({type: 'getDeviceStatus'}, (err, result) => {
    if (err) {
        throw err;
    }
    console.log('getDeviceStatus', result);
});

console.log('findLastDocument', fptr.findLastDocument());
// try {
//     console.log('fnReport', fptr.fnReport(1));
// } catch (e) {
//     console.log('error', e.message, 'code', e.code, 'descr', e.description);
// }
// fptr.processJson({
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
// }, (err, result) => {
//     if (err) {
//         throw err;
//     }
//     console.log('openShift', result);
// });


fptr.processJson({
    type: 'closeShift',
    operator: {
        name: 'Иванов',
        vatin: '123654789507'
    }
}, (err, result) => {
    if (err) {
        throw err;
    }
    console.log('closeShift', result);
});


console.log('close', fptr.close());
fptr.destroy();
