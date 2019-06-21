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

fptr.processJsonAsync({
    type: 'reportX',
    operator: {
        name: 'Иванов',
        vatin: '123654789507'
    }
}, (err, result) => {
    if (err) {
        throw err;
    } else {
        console.log('reportX', result);
        fptr.processJsonAsync({type: 'getDeviceStatus'}, (err, result) => {
            if(err){
                throw err;
            } else {
                console.log('getDeviceStatus', result);
                console.log('close', fptr.close());
            }
        })
    }
});

