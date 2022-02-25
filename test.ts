import { ConsoleErrorListener } from 'antlr4/src/antlr4/error/ErrorListener';
import { DynamicLibrary, ForeignFunction} from 'ffi-napi';
import * as fs from 'fs';
const demo = DynamicLibrary('libngspice.dylib');
const command = demo.get('ngSpice_Command');
const ngSpice_Circ = demo.get('ngSpice_Circ');
// const function2 = ForeignFunction(ngSpice_Circ, 'string', ['string']);
// const result = function2('params ss=12')
// console.log(11, result);
fs.writeFileSync('buffer.txt', JSON.stringify(ngSpice_Circ))