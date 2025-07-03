const { SerialPort, ReadlineParser } = require('serialport');
const { exec } = require('child_process');

const COM_PORT = 'COM5'; //change to your COM PORT
const BAUD_RATE = 9600;

const port = new SerialPort({ path: COM_PORT, baudRate: BAUD_RATE });
const parser = new ReadlineParser();

port.pipe(parser);

parser.on("data", (line) => {
    exec('C:\\Users\\ghosh\\OneDrive\\Documents\\AutoHotkey\\tab_change.ahk'); //change to your autohotkey location
    console.log(line);
});
