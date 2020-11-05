export interface Settings {
    AccessPassword: string;
    AutoDisableBluetooth: boolean;
    AutoEnableBluetooth: boolean;
    AutoReconnect: boolean;
    BaudRate: number;
    Bits: number;
    ComFile: string;
    DocumentsJournalPath: string;
    IPAddress: string;
    IPPort: number;
    InvertCashDrawerStatus: boolean;
    LibraryPath: string;
    MACAddress: string;
    Model: number;
    OfdChannel: number;
    Parity: number;
    Port: number;
    RemoteServerAddr: string;
    RemoteServerConnectionTimeout: number;
    ScriptsPath: string;
    StopBits: number;
    UsbDevicePath: string;
    UseDocumentsJournal: boolean;
    UserPassword: string;
}
export interface LastDocument {
    documentNumber: number;
    fiscalSign: string;
    date: {
        year: number;
        month: number;
        day: number;
        hour: number;
        minute: number;
        second: number;
    };
}
export interface DeviceInfo {
    configurationVersion: string;
    ecrFfdVersion: string;
    fnFfdVersion: string;
    firmwareVersion: string;
    model: number;
    modelName: string;
    receiptLineLength: number;
    receiptLineLengthPx: number;
    serial: string;
}
export declare class Fptr10 {
    create(): void;
    isOpened(): boolean;
    destroy(): void;
    getSettings(): Settings;
    setSettings(settings: Settings): boolean;
    open(): boolean;
    close(): boolean;
    processJson(json: unknown): any;
    processJsonAsync(json: unknown, cb: (error: any, result: any) => void): void;
    fnReport(type: number): any;
    findLastDocument(): LastDocument;
}
