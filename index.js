const w = require('./bindings');
const fptr = new w.Fptr10();
console.log(fptr);
fptr.create();
const settings = fptr.getSettings();
console.log('getSettings', settings);
settings.Port = 0; //ComPort communication
settings.ComFile = 'COM5'; //ComPort name
settings.BaudRate = 115200;
console.log('setSettings', fptr.setSettings(settings));
console.log('open', fptr.open());

console.log('getData', fptr.processJson({type: 'getDeviceStatus'}));
console.log('fnReport', fptr.fnReport('1'));
// console.log('printNonFiscal', fptr.processJson(
//     {
//         type: 'nonFiscal',
//         items:
//             [{
//                 type: 'text',
//                 text: 'ИНН:                          7702690982',
//                 alignment: 'center'
//             },
//                 {
//                     type: 'text',
//                     text: 'Общество с ограниченной ответственностью',
//                     alignment: 'center'
//                 },
//                 {
//                     type: 'text',
//                     text: ' НАУЧНО-ПРОИЗВОДСТВЕННАЯ КОМПАНИЯ ИНКОТЕ',
//                     alignment: 'center'
//                 },
//                 {type: 'text', text: 'КС', alignment: 'center'},
//                 {
//                     type: 'text',
//                     text: '          ООО "НПК "ИНКОТЕКС"          ',
//                     alignment: 'center'
//                 },
//                 {
//                     type: 'text',
//                     text: 'Кассир:       ЮнитТест ЮнитТест ЮнитТест',
//                     alignment: 'center'
//                 },
//                 {
//                     type: 'text',
//                     text: 'Дата:                09.08.2018 15:45:15',
//                     alignment: 'center'
//                 }
//                 ]
//     }
// ));
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
