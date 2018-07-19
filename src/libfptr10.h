#ifndef ATOL_DTOX_FPTR_H
#define ATOL_DTOX_FPTR_H

#if defined(_WIN32) || defined(_WIN32_WCE)
#  if defined(DTOX_LIBRARY)
#    define DTOX_SHARED_EXPORT __declspec(dllexport)
#  else
#    define DTOX_SHARED_EXPORT __declspec(dllimport)
#  endif
#  define DTOX_SHARED_CCA __cdecl
#elif defined(__linux__) || defined(ANDROID)
#  if __GNUC__ >= 4
#    define DTOX_SHARED_EXPORT __attribute__((visibility("default")))
#  else
#    define DTOX_SHARED_EXPORT
#  endif
#  define DTOX_SHARED_CCA
#elif defined(__APPLE__)
#  define DTOX_SHARED_EXPORT __attribute__((visibility("default")))
#  define DTOX_SHARED_CCA
#else
#  define DTOX_SHARED_EXPORT
#  define DTOX_SHARED_CCA __attribute__ ((cdecl))
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

typedef void *libfptr_handle;


#ifdef __cplusplus
extern "C"
{
#endif

enum libfptr_error
{
    LIBFPTR_OK = 0,
    LIBFPTR_ERROR_CONNECTION_DISABLED,
    LIBFPTR_ERROR_NO_CONNECTION,
    LIBFPTR_ERROR_PORT_BUSY,
    LIBFPTR_ERROR_PORT_NOT_AVAILABLE,
    LIBFPTR_ERROR_INCORRECT_DATA,
    LIBFPTR_ERROR_INTERNAL,
    LIBFPTR_ERROR_UNSUPPORTED_CAST,
    LIBFPTR_ERROR_NO_REQUIRED_PARAM,
    LIBFPTR_ERROR_INVALID_SETTINGS,
    LIBFPTR_ERROR_NOT_CONFIGURED,
    LIBFPTR_ERROR_NOT_SUPPORTED,
    LIBFPTR_ERROR_INVALID_MODE,
    LIBFPTR_ERROR_INVALID_PARAM,
    LIBFPTR_ERROR_NOT_LOADED,
    LIBFPTR_ERROR_UNKNOWN,

    LIBFPTR_ERROR_INVALID_SUM,
    LIBFPTR_ERROR_INVALID_QUANTITY,
    LIBFPTR_ERROR_CASH_COUNTER_OVERFLOW,
    LIBFPTR_ERROR_LAST_OPERATION_STORNO_DENIED,
    LIBFPTR_ERROR_STORNO_BY_CODE_DENIED,
    LIBFPTR_ERROR_LAST_OPERATION_NOT_REPEATABLE,
    LIBFPTR_ERROR_DISCOUNT_NOT_REPEATABLE,
    LIBFPTR_ERROR_DISCOUNT_DENIED,
    LIBFPTR_ERROR_INVALID_COMMODITY_CODE,
    LIBFPTR_ERROR_INVALID_COMMODITY_BARCODE,
    LIBFPTR_ERROR_INVALID_COMMAND_FORMAT,
    LIBFPTR_ERROR_INVALID_COMMAND_LENGTH,
    LIBFPTR_ERROR_BLOCKED_IN_DATE_INPUT_MODE,
    LIBFPTR_ERROR_NEED_DATE_ACCEPT,
    LIBFPTR_ERROR_NO_MORE_DATA,
    LIBFPTR_ERROR_NO_ACCEPT_OR_CANCEL,
    LIBFPTR_ERROR_BLOCKED_BY_REPORT_INTERRUPTION,
    LIBFPTR_ERROR_DISABLE_CASH_CONTROL_DENIED,
    LIBFPTR_ERROR_MODE_BLOCKED,
    LIBFPTR_ERROR_CHECK_DATE_TIME,
    LIBFPTR_ERROR_DATE_TIME_LESS_THAN_FS,
    LIBFPTR_ERROR_CLOSE_ARCHIVE_DENIED,
    LIBFPTR_ERROR_COMMODITY_NOT_FOUND,
    LIBFPTR_ERROR_WEIGHT_BARCODE_WITH_INVALID_QUANTITY,
    LIBFPTR_ERROR_RECEIPT_BUFFER_OVERFLOW,
    LIBFPTR_ERROR_QUANTITY_TOO_FEW,
    LIBFPTR_ERROR_STORNO_TOO_MUCH,
    LIBFPTR_ERROR_BLOCKED_COMMODITY_NOT_FOUND,
    LIBFPTR_ERROR_NO_PAPER,
    LIBFPTR_ERROR_COVER_OPENED,
    LIBFPTR_ERROR_PRINTER_FAULT,
    LIBFPTR_ERROR_MECHANICAL_FAULT,
    LIBFPTR_ERROR_INVALID_RECEIPT_TYPE,
    LIBFPTR_ERROR_INVALID_UNIT_TYPE,
    LIBFPTR_ERROR_NO_MEMORY,
    LIBFPTR_ERROR_PICTURE_NOT_FOUND,
    LIBFPTR_ERROR_NONCACH_PAYMENTS_TOO_MUCH,
    LIBFPTR_ERROR_RETURN_DENIED,
    LIBFPTR_ERROR_PAYMENTS_OVERFLOW,
    LIBFPTR_ERROR_BUSY,
    LIBFPTR_ERROR_GSM,
    LIBFPTR_ERROR_INVALID_DISCOUNT,
    LIBFPTR_ERROR_OPERATION_AFTER_DISCOUNT_DENIED,
    LIBFPTR_ERROR_INVALID_DEPARTMENT,
    LIBFPTR_ERROR_INVALID_PAYMENT_TYPE,
    LIBFPTR_ERROR_MULTIPLICATION_OVERFLOW,
    LIBFPTR_ERROR_DENIED_BY_SETTINGS,
    LIBFPTR_ERROR_TOTAL_OVERFLOW,
    LIBFPTR_ERROR_DENIED_IN_ANNULATION_RECEIPT,
    LIBFPTR_ERROR_JOURNAL_OVERFLOW,
    LIBFPTR_ERROR_NOT_FULLY_PAID,
    LIBFPTR_ERROR_DENIED_IN_RETURN_RECEIPT,
    LIBFPTR_ERROR_SHIFT_EXPIRED,
    LIBFPTR_ERROR_DENIED_IN_SELL_RECEIPT,
    LIBFPTR_ERROR_FISCAL_MEMORY_OVERFLOW,
    LIBFPTR_ERROR_INVALID_PASSWORD,
    LIBFPTR_ERROR_JOURNAL_BUSY,
    LIBFPTR_ERROR_DENIED_IN_CLOSED_SHIFT,
    LIBFPTR_ERROR_INVALID_TABLE_NUMBER,
    LIBFPTR_ERROR_INVALID_ROW_NUMBER,
    LIBFPTR_ERROR_INVALID_FIELD_NUMBER,
    LIBFPTR_ERROR_INVALID_DATE_TIME,
    LIBFPTR_ERROR_INVALID_STORNO_SUM,
    LIBFPTR_ERROR_CHANGE_CALCULATION,
    LIBFPTR_ERROR_NO_CASH,
    LIBFPTR_ERROR_DENIED_IN_CLOSED_RECEIPT,
    LIBFPTR_ERROR_DENIED_IN_OPENED_RECEIPT,
    LIBFPTR_ERROR_DENIED_IN_OPENED_SHIFT,
    LIBFPTR_ERROR_SERIAL_NUMBER_ALREADY_ENTERED,
    LIBFPTR_ERROR_TOO_MUCH_REREGISTRATIONS,
    LIBFPTR_ERROR_INVALID_SHIFT_NUMBER,
    LIBFPTR_ERROR_INVALID_SERIAL_NUMBER,
    LIBFPTR_ERROR_INVALID_RNM_VATIN,
    LIBFPTR_ERROR_FISCAL_PRINTER_NOT_ACTIVATED,
    LIBFPTR_ERROR_SERIAL_NUMBER_NOT_ENTERED,
    LIBFPTR_ERROR_NO_MORE_REPORTS,
    LIBFPTR_ERROR_MODE_NOT_ACTIVATED,
    LIBFPTR_ERROR_RECORD_NOT_FOUND_IN_JOURNAL,
    LIBFPTR_ERROR_INVALID_LICENSE,
    LIBFPTR_ERROR_NEED_FULL_RESET,
    LIBFPTR_ERROR_DENIED_BY_LICENSE,
    LIBFPTR_ERROR_DISCOUNT_CANCELLATION_DENIED,
    LIBFPTR_ERROR_CLOSE_RECEIPT_DENIED,
    LIBFPTR_ERROR_INVALID_ROUTE_NUMBER,
    LIBFPTR_ERROR_INVALID_START_ZONE_NUMBER,
    LIBFPTR_ERROR_INVALID_END_ZONE_NUMBER,
    LIBFPTR_ERROR_INVALID_RATE_TYPE,
    LIBFPTR_ERROR_INVALID_RATE,
    LIBFPTR_ERROR_FISCAL_MODULE_EXCHANGE,
    LIBFPTR_ERROR_NEED_TECHNICAL_SUPPORT,
    LIBFPTR_ERROR_SHIFT_NUMBERS_DID_NOT_MATCH,
    LIBFPTR_ERROR_DEVICE_NOT_FOUND,
    LIBFPTR_ERROR_EXTERNAL_DEVICE_CONNECTION,
    LIBFPTR_ERROR_DISPENSER_INVALID_STATE,
    LIBFPTR_ERROR_INVALID_POSITIONS_COUNT,
    LIBFPTR_ERROR_DISPENSER_INVALID_NUMBER,
    LIBFPTR_ERROR_INVALID_DIVIDER,
    LIBFPTR_ERROR_FN_ACTIVATION_DENIED,
    LIBFPTR_ERROR_PRINTER_OVERHEAT,
    LIBFPTR_ERROR_FN_EXCHANGE,
    LIBFPTR_ERROR_FN_INVALID_FORMAT,
    LIBFPTR_ERROR_FN_INVALID_STATE,
    LIBFPTR_ERROR_FN_FAULT,
    LIBFPTR_ERROR_FN_CRYPTO_FAULT,
    LIBFPTR_ERROR_FN_EXPIRED,
    LIBFPTR_ERROR_FN_OVERFLOW,
    LIBFPTR_ERROR_FN_INVALID_DATE_TIME,
    LIBFPTR_ERROR_FN_NO_MORE_DATA,
    LIBFPTR_ERROR_FN_TOTAL_OVERFLOW,
    LIBFPTR_ERROR_BUFFER_OVERFLOW,
    LIBFPTR_ERROR_PRINT_SECOND_COPY_DENIED,
    LIBFPTR_ERROR_NEED_RESET_JOURNAL,
    LIBFPTR_ERROR_TAX_SUM_TOO_MUCH,
    LIBFPTR_ERROR_TAX_ON_LAST_OPERATION_DENIED,
    LIBFPTR_ERROR_INVALID_FN_NUMBER,
    LIBFPTR_ERROR_TAX_CANCEL_DENIED,
    LIBFPTR_ERROR_LOW_BATTERY,
    LIBFPTR_ERROR_FN_INVALID_COMMAND,
    LIBFPTR_ERROR_FN_COMMAND_OVERFLOW,
    LIBFPTR_ERROR_FN_NO_TRANSPORT_CONNECTION,
    LIBFPTR_ERROR_FN_CRYPTO_HAS_EXPIRED,
    LIBFPTR_ERROR_FN_RESOURCE_HAS_EXPIRED,
    LIBFPTR_ERROR_INVALID_MESSAGE_FROM_OFD,
    LIBFPTR_ERROR_FN_HAS_NOT_SEND_DOCUMENTS,
    LIBFPTR_ERROR_FN_TIMEOUT,
    LIBFPTR_ERROR_FN_SHIFT_EXPIRED,
    LIBFPTR_ERROR_FN_INVALID_TIME_DIFFERENCE,
    LIBFPTR_ERROR_INVALID_TAXATION_TYPE,
    LIBFPTR_ERROR_INVALID_TAX_TYPE,
    LIBFPTR_ERROR_INVALID_COMMODITY_PAYMENT_TYPE,
    LIBFPTR_ERROR_INVALID_COMMODITY_CODE_TYPE,
    LIBFPTR_ERROR_EXCISABLE_COMMODITY_DENIED,
    LIBFPTR_ERROR_FISCAL_PROPERTY_WRITE,
    LIBFPTR_ERROR_INVALID_COUNTER_TYPE,
    LIBFPTR_ERROR_CUTTER_FAULT,
    LIBFPTR_ERROR_REPORT_INTERRUPTED,
    LIBFPTR_ERROR_INVALID_LEFT_MARGIN,
    LIBFPTR_ERROR_INVALID_ALIGNMENT,
    LIBFPTR_ERROR_INVALID_TAX_MODE,
    LIBFPTR_ERROR_FILE_NOT_FOUND,
    LIBFPTR_ERROR_PICTURE_TOO_BIG,
    LIBFPTR_ERROR_INVALID_BARCODE_PARAMS,
    LIBFPTR_ERROR_FISCAL_PROPERTY_DENIED,
    LIBFPTR_ERROR_FN_INTERFACE,
    LIBFPTR_ERROR_DATA_DUPLICATE,
    LIBFPTR_ERROR_NO_REQUIRED_FISCAL_PROPERTY,
    LIBFPTR_ERROR_FN_READ_DOCUMENT,
    LIBFPTR_ERROR_FLOAT_OVERFLOW,
    LIBFPTR_ERROR_INVALID_SETTING_VALUE,
    LIBFPTR_ERROR_HARD_FAULT,
    LIBFPTR_ERROR_FN_NOT_FOUND,
    LIBFPTR_ERROR_INVALID_AGENT_FISCAL_PROPERTY,
    LIBFPTR_ERROR_INVALID_FISCAL_PROPERTY_VALUE_1002_1056,
    LIBFPTR_ERROR_INVALID_FISCAL_PROPERTY_VALUE_1002_1017,
    LIBFPTR_ERROR_SCRIPT,
    LIBFPTR_ERROR_INVALID_USER_MEMORY_INDEX,
    LIBFPTR_ERROR_NO_ACTIVE_OPERATOR,
    LIBFPTR_ERROR_REGISTRATION_REPORT_INTERRUPTED,
    LIBFPTR_ERROR_CLOSE_FN_REPORT_INTERRUPTED,
    LIBFPTR_ERROR_OPEN_SHIFT_REPORT_INTERRUPTED,
    LIBFPTR_ERROR_OFD_EXCHANGE_REPORT_INTERRUPTED,
    LIBFPTR_ERROR_CLOSE_RECEIPT_INTERRUPTED,
    LIBFPTR_ERROR_FN_QUERY_INTERRUPTED,
    LIBFPTR_ERROR_RTC_FAULT,
    LIBFPTR_ERROR_MEMORY_FAULT,
    LIBFPTR_ERROR_CHIP_FAULT,
    LIBFPTR_ERROR_TEMPLATES_CORRUPTED,
    LIBFPTR_ERROR_INVALID_MAC_ADDRESS,
    LIBFPTR_ERROR_INVALID_SCRIPT_NUMBER,
    LIBFPTR_ERROR_SCRIPTS_FAULT,
    LIBFPTR_ERROR_INVALID_SCRIPTS_VERSION,
    LIBFPTR_ERROR_INVALID_CLICHE_FORMAT,
    LIBFPTR_ERROR_WAIT_FOR_REBOOT,
    LIBFPTR_ERROR_NO_LICENSE,
    LIBFPTR_ERROR_INVALID_FFD_VERSION,
    LIBFPTR_ERROR_CHANGE_SETTING_DENIED,
    LIBFPTR_ERROR_INVALID_NOMENCLATURE_TYPE,
    LIBFPTR_ERROR_INVALID_GTIN,
    LIBFPTR_ERROR_NEGATIVE_MATH_RESULT,
    LIBFPTR_ERROR_FISCAL_PROPERTIES_COMBINATION,
    LIBFPTR_ERROR_OPERATOR_LOGIN,
    LIBFPTR_ERROR_INVALID_INTERNET_CHANNEL,
    LIBFPTR_ERROR_DATETIME_NOT_SYNCRONIZED,
    LIBFPTR_ERROR_JOURNAL,
    LIBFPTR_ERROR_DENIED_IN_OPENED_DOC,
    LIBFPTR_ERROR_DENIED_IN_CLOSED_DOC,

    LIBFPTR_ERROR_BASE_WEB = 500,
    LIBFPTR_ERROR_RECEIPT_PARSE_ERROR,
    LIBFPTR_ERROR_INTERRUPTED_BY_PREVIOUS_ERRORS,
};

enum libfptr_param
{
    LIBFPTR_PARAM_FIRST = 65536,
    LIBFPTR_PARAM_TEXT = LIBFPTR_PARAM_FIRST,
    LIBFPTR_PARAM_TEXT_WRAP,
    LIBFPTR_PARAM_ALIGNMENT,

    LIBFPTR_PARAM_FONT,
    LIBFPTR_PARAM_FONT_DOUBLE_WIDTH,
    LIBFPTR_PARAM_FONT_DOUBLE_HEIGHT,
    LIBFPTR_PARAM_LINESPACING,
    LIBFPTR_PARAM_BRIGHTNESS,

    LIBFPTR_PARAM_MODEL,
    LIBFPTR_PARAM_RECEIPT_TYPE,
    LIBFPTR_PARAM_REPORT_TYPE,
    LIBFPTR_PARAM_MODE,
    LIBFPTR_PARAM_EXTERNAL_DEVICE_TYPE,
    LIBFPTR_PARAM_EXTERNAL_DEVICE_DATA,
    LIBFPTR_PARAM_FREQUENCY,
    LIBFPTR_PARAM_DURATION,
    LIBFPTR_PARAM_CUT_TYPE,
    LIBFPTR_PARAM_DRAWER_ON_TIMEOUT,
    LIBFPTR_PARAM_DRAWER_OFF_TIMEOUT,
    LIBFPTR_PARAM_DRAWER_ON_QUANTITY,
    LIBFPTR_PARAM_TIMEOUT_ENQ,
    LIBFPTR_PARAM_COMMAND_BUFFER,
    LIBFPTR_PARAM_ANSWER_BUFFER,
    LIBFPTR_PARAM_SERIAL_NUMBER,
    LIBFPTR_PARAM_MANUFACTURER_CODE,
    LIBFPTR_PARAM_NO_NEED_ANSWER,
    LIBFPTR_PARAM_INFO_DISCOUNT_SUM,
    LIBFPTR_PARAM_USE_ONLY_TAX_TYPE,
    LIBFPTR_PARAM_PAYMENT_TYPE,
    LIBFPTR_PARAM_PAYMENT_SUM,
    LIBFPTR_PARAM_REMAINDER,
    LIBFPTR_PARAM_CHANGE,
    LIBFPTR_PARAM_DEPARTMENT,
    LIBFPTR_PARAM_TAX_TYPE,
    LIBFPTR_PARAM_TAX_SUM,
    LIBFPTR_PARAM_TAX_MODE,
    LIBFPTR_PARAM_RECEIPT_ELECTRONICALLY,
    LIBFPTR_PARAM_USER_PASSWORD,
    LIBFPTR_PARAM_SCALE,
    LIBFPTR_PARAM_LEFT_MARGIN,
    LIBFPTR_PARAM_BARCODE,
    LIBFPTR_PARAM_BARCODE_TYPE,
    LIBFPTR_PARAM_BARCODE_PRINT_TEXT,
    LIBFPTR_PARAM_BARCODE_VERSION,
    LIBFPTR_PARAM_BARCODE_CORRECTION,
    LIBFPTR_PARAM_BARCODE_COLUMNS,
    LIBFPTR_PARAM_BARCODE_INVERT,
    LIBFPTR_PARAM_HEIGHT,
    LIBFPTR_PARAM_WIDTH,
    LIBFPTR_PARAM_FILENAME,
    LIBFPTR_PARAM_PICTURE_NUMBER,
    LIBFPTR_PARAM_DATA_TYPE,
    LIBFPTR_PARAM_OPERATOR_ID,
    LIBFPTR_PARAM_LOGICAL_NUMBER,
    LIBFPTR_PARAM_DATE_TIME,
    LIBFPTR_PARAM_FISCAL,
    LIBFPTR_PARAM_SHIFT_STATE,
    LIBFPTR_PARAM_CASHDRAWER_OPENED,
    LIBFPTR_PARAM_RECEIPT_PAPER_PRESENT,
    LIBFPTR_PARAM_COVER_OPENED,
    LIBFPTR_PARAM_SUBMODE,
    LIBFPTR_PARAM_RECEIPT_NUMBER,
    LIBFPTR_PARAM_DOCUMENT_NUMBER,
    LIBFPTR_PARAM_SHIFT_NUMBER,
    LIBFPTR_PARAM_RECEIPT_SUM,
    LIBFPTR_PARAM_RECEIPT_LINE_LENGTH,
    LIBFPTR_PARAM_RECEIPT_LINE_LENGTH_PIX,
    LIBFPTR_PARAM_MODEL_NAME,
    LIBFPTR_PARAM_UNIT_VERSION,
    LIBFPTR_PARAM_PRINTER_CONNECTION_LOST,
    LIBFPTR_PARAM_PRINTER_ERROR,
    LIBFPTR_PARAM_CUT_ERROR,
    LIBFPTR_PARAM_PRINTER_OVERHEAT,
    LIBFPTR_PARAM_UNIT_TYPE,
    LIBFPTR_PARAM_LICENSE_NUMBER,
    LIBFPTR_PARAM_LICENSE_ENTERED,
    LIBFPTR_PARAM_LICENSE,
    LIBFPTR_PARAM_SUM,
    LIBFPTR_PARAM_COUNT,
    LIBFPTR_PARAM_COUNTER_TYPE,
    LIBFPTR_PARAM_STEP_COUNTER_TYPE,
    LIBFPTR_PARAM_ERROR_TAG_NUMBER,
    LIBFPTR_PARAM_TABLE,
    LIBFPTR_PARAM_ROW,
    LIBFPTR_PARAM_FIELD,
    LIBFPTR_PARAM_FIELD_VALUE,
    LIBFPTR_PARAM_FN_DATA_TYPE,
    LIBFPTR_PARAM_TAG_NUMBER,
    LIBFPTR_PARAM_TAG_VALUE,
    LIBFPTR_PARAM_DOCUMENTS_COUNT,
    LIBFPTR_PARAM_FISCAL_SIGN,
    LIBFPTR_PARAM_DEVICE_FFD_VERSION,
    LIBFPTR_PARAM_FN_FFD_VERSION,
    LIBFPTR_PARAM_FFD_VERSION,
    LIBFPTR_PARAM_CHECK_SUM,
    LIBFPTR_PARAM_COMMODITY_NAME,
    LIBFPTR_PARAM_PRICE,
    LIBFPTR_PARAM_QUANTITY,
    LIBFPTR_PARAM_POSITION_SUM,
    LIBFPTR_PARAM_FN_TYPE,
    LIBFPTR_PARAM_FN_VERSION,
    LIBFPTR_PARAM_REGISTRATIONS_REMAIN,
    LIBFPTR_PARAM_REGISTRATIONS_COUNT,
    LIBFPTR_PARAM_NO_ERROR_IF_NOT_SUPPORTED,
    LIBFPTR_PARAM_OFD_EXCHANGE_STATUS,
    LIBFPTR_PARAM_FN_ERROR_DATA,
    LIBFPTR_PARAM_FN_ERROR_CODE,
    LIBFPTR_PARAM_ENVD_MODE,
    LIBFPTR_PARAM_DOCUMENT_CLOSED,
    LIBFPTR_PARAM_JSON_DATA,
    LIBFPTR_PARAM_COMMAND_SUBSYSTEM,
    LIBFPTR_PARAM_FN_OPERATION_TYPE,
    LIBFPTR_PARAM_FN_STATE,
    LIBFPTR_PARAM_ENVD_MODE_ENABLED,
    LIBFPTR_PARAM_SETTING_ID,
    LIBFPTR_PARAM_SETTING_VALUE,
    LIBFPTR_PARAM_MAPPING_KEY,
    LIBFPTR_PARAM_MAPPING_VALUE,
    LIBFPTR_PARAM_COMMODITY_PIECE,
    LIBFPTR_PARAM_POWER_SOURCE_TYPE,
    LIBFPTR_PARAM_BATTERY_CHARGE,
    LIBFPTR_PARAM_VOLTAGE,
    LIBFPTR_PARAM_USE_BATTERY,
    LIBFPTR_PARAM_BATTERY_CHARGING,
    LIBFPTR_PARAM_CAN_PRINT_WHILE_ON_BATTERY,
    LIBFPTR_PARAM_MAC_ADDRESS,
    LIBFPTR_PARAM_FN_FISCAL,
    LIBFPTR_PARAM_NETWORK_ERROR,
    LIBFPTR_PARAM_OFD_ERROR,
    LIBFPTR_PARAM_FN_ERROR,
    LIBFPTR_PARAM_COMMAND_CODE,
    LIBFPTR_PARAM_PRINTER_TEMPERATURE,
    LIBFPTR_PARAM_RECORDS_TYPE,
    LIBFPTR_PARAM_OFD_FISCAL_SIGN,
    LIBFPTR_PARAM_HAS_OFD_TICKET,
    LIBFPTR_PARAM_NO_SERIAL_NUMBER,
    LIBFPTR_PARAM_RTC_FAULT,
    LIBFPTR_PARAM_SETTINGS_FAULT,
    LIBFPTR_PARAM_COUNTERS_FAULT,
    LIBFPTR_PARAM_USER_MEMORY_FAULT,
    LIBFPTR_PARAM_SERVICE_COUNTERS_FAULT,
    LIBFPTR_PARAM_ATTRIBUTES_FAULT,
    LIBFPTR_PARAM_FN_FAULT,
    LIBFPTR_PARAM_INVALID_FN,
    LIBFPTR_PARAM_HARD_FAULT,
    LIBFPTR_PARAM_MEMORY_MANAGER_FAULT,
    LIBFPTR_PARAM_SCRIPTS_FAULT,
    LIBFPTR_PARAM_FULL_RESET,
    LIBFPTR_PARAM_WAIT_FOR_REBOOT,
    LIBFPTR_PARAM_SCALE_PERCENT,
    LIBFPTR_PARAM_FN_NEED_REPLACEMENT,
    LIBFPTR_PARAM_FN_RESOURCE_EXHAUSTED,
    LIBFPTR_PARAM_FN_MEMORY_OVERFLOW,
    LIBFPTR_PARAM_FN_OFD_TIMEOUT,
    LIBFPTR_PARAM_FN_CRITICAL_ERROR,
    LIBFPTR_PARAM_OFD_MESSAGE_READ,
    LIBFPTR_PARAM_DEVICE_MIN_FFD_VERSION,
    LIBFPTR_PARAM_DEVICE_MAX_FFD_VERSION,
    LIBFPTR_PARAM_DEVICE_UPTIME,
    LIBFPTR_PARAM_NOMENCLATURE_TYPE,
    LIBFPTR_PARAM_GTIN,
    LIBFPTR_PARAM_FN_DOCUMENT_TYPE,
    LIBFPTR_PARAM_NETWORK_ERROR_TEXT,
    LIBFPTR_PARAM_FN_ERROR_TEXT,
    LIBFPTR_PARAM_OFD_ERROR_TEXT,
    LIBFPTR_PARAM_USER_SCRIPT_ID,
    LIBFPTR_PARAM_USER_SCRIPT_PARAMETER,
    LIBFPTR_PARAM_USER_MEMORY_OPERATION,
    LIBFPTR_PARAM_USER_MEMORY_DATA,
    LIBFPTR_PARAM_USER_MEMORY_STRING,
    LIBFPTR_PARAM_USER_MEMORY_ADDRESS,
    LIBFPTR_PARAM_FN_PRESENT,
    LIBFPTR_PARAM_BLOCKED,
    LIBFPTR_PARAM_DOCUMENT_PRINTED,
    LIBFPTR_PARAM_DISCOUNT_SUM,
    LIBFPTR_PARAM_SURCHARGE_SUM,
    LIBFPTR_PARAM_LK_USER_CODE,
    LIBFPTR_PARAM_LICENSE_COUNT,
    LIBFPTR_PARAM_DEFER,
    LIBFPTR_PARAM_CAP_54FZ,
    LIBFPTR_PARAM_CAP_MANUAL_CLICHE_CONTROL,

    LIBFPTR_PARAM_LAST
};

enum libfptr_model
{
    LIBFPTR_MODEL_UNKNOWN = 0,
    LIBFPTR_MODEL_ATOL_AUTO = 500,
    LIBFPTR_MODEL_ATOL_11F = 67,
    LIBFPTR_MODEL_ATOL_15F = 78,
    LIBFPTR_MODEL_ATOL_20F = 81,
    LIBFPTR_MODEL_ATOL_22F = 63,
    LIBFPTR_MODEL_ATOL_25F = 57,
    LIBFPTR_MODEL_ATOL_30F = 61,
    LIBFPTR_MODEL_ATOL_42FS = 77,
    LIBFPTR_MODEL_ATOL_50F = 80,
    LIBFPTR_MODEL_ATOL_52F = 64,
    LIBFPTR_MODEL_ATOL_55F = 62,
    LIBFPTR_MODEL_ATOL_60F = 75,
    LIBFPTR_MODEL_ATOL_77F = 69,
    LIBFPTR_MODEL_ATOL_90F = 72,
    LIBFPTR_MODEL_ATOL_91F = 82,
    LIBFPTR_MODEL_ATOL_92F = 84,
    LIBFPTR_MODEL_ATOL_SIGMA_10 = 86,
};

#define LIBFPTR_SETTING_LIBRARY_PATH L"LibraryPath"

#define LIBFPTR_SETTING_MODEL L"Model"

#define LIBFPTR_SETTING_PORT L"Port"

#define LIBFPTR_SETTING_BAUDRATE L"BaudRate"

#define LIBFPTR_SETTING_BITS L"Bits"

#define LIBFPTR_SETTING_PARITY L"Parity"

#define LIBFPTR_SETTING_STOPBITS L"StopBits"

#define LIBFPTR_SETTING_IPADDRESS L"IPAddress"

#define LIBFPTR_SETTING_IPPORT L"IPPort"

#define LIBFPTR_SETTING_MACADDRESS L"MACAddress"

#define LIBFPTR_SETTING_COM_FILE L"ComFile"

#define LIBFPTR_SETTING_USB_DEVICE_PATH L"UsbDevicePath"

#define LIBFPTR_SETTING_BT_AUTOENABLE L"AutoEnableBluetooth"

#define LIBFPTR_SETTING_BT_AUTODISABLE L"AutoDisableBluetooth"

#define LIBFPTR_SETTING_ACCESS_PASSWORD L"AccessPassword"

#define LIBFPTR_SETTING_USER_PASSWORD L"UserPassword"

#define LIBFPTR_SETTING_OFD_CHANNEL L"OfdChannel"

#define LIBFPTR_SETTING_EXISTED_COM_FILES L"ExistedComFiles"

enum libfptr_port
{
    LIBFPTR_PORT_COM = 0,
    LIBFPTR_PORT_USB,
    LIBFPTR_PORT_TCPIP,
    LIBFPTR_PORT_BLUETOOTH,
};

enum libfptr_baudrate
{
    LIBFPTR_PORT_BR_1200 = 1200,
    LIBFPTR_PORT_BR_2400 = 2400,
    LIBFPTR_PORT_BR_4800 = 4800,
    LIBFPTR_PORT_BR_9600 = 9600,
    LIBFPTR_PORT_BR_19200 = 19200,
    LIBFPTR_PORT_BR_38400 = 38400,
    LIBFPTR_PORT_BR_57600 = 57600,
    LIBFPTR_PORT_BR_115200 = 115200,
    LIBFPTR_PORT_BR_230400 = 230400,
    LIBFPTR_PORT_BR_460800 = 460800,
    LIBFPTR_PORT_BR_921600 = 921600,
};

enum libfptr_bits
{
    LIBFPTR_PORT_BITS_7 = 7,
    LIBFPTR_PORT_BITS_8 = 8,
};

enum libfptr_parity
{
    LIBFPTR_PORT_PARITY_NO = 0,
    LIBFPTR_PORT_PARITY_ODD,
    LIBFPTR_PORT_PARITY_EVEN,
    LIBFPTR_PORT_PARITY_MARK,
    LIBFPTR_PORT_PARITY_SPACE,
};

enum libfptr_stopbits
{
    LIBFPTR_PORT_SB_1 = 0,
    LIBFPTR_PORT_SB_1_5,
    LIBFPTR_PORT_SB_2
};

enum libfptr_barcode_type
{
    LIBFPTR_BT_EAN_8 = 0,
    LIBFPTR_BT_EAN_13,
    LIBFPTR_BT_UPC_A,
    LIBFPTR_BT_UPC_E,
    LIBFPTR_BT_CODE_39,
    LIBFPTR_BT_CODE_93,
    LIBFPTR_BT_CODE_128,
    LIBFPTR_BT_CODABAR,
    LIBFPTR_BT_ITF,
    LIBFPTR_BT_ITF_14,
    LIBFPTR_BT_GS1_128,
    LIBFPTR_BT_QR,
    LIBFPTR_BT_PDF417,
    LIBFPTR_BT_AZTEC,
};

enum libfptr_barcode_correction
{
    LIBFPTR_BC_DEFAULT = 0,
    LIBFPTR_BC_0,
    LIBFPTR_BC_1,
    LIBFPTR_BC_2,
    LIBFPTR_BC_3,
    LIBFPTR_BC_4,
    LIBFPTR_BC_5,
    LIBFPTR_BC_6,
    LIBFPTR_BC_7,
    LIBFPTR_BC_8,
};

enum libfptr_tax_mode
{
    LIBFPTR_TM_POSITION = 0,
    LIBFPTR_TM_UNIT,
};

enum libfptr_step_counter_type
{
    LIBFPTR_SCT_OVERALL = 0,
    LIBFPTR_SCT_FORWARD,
};

enum libfptr_counter_type
{
    LIBFPTR_CT_ROLLUP = 0,
    LIBFPTR_CT_RESETTABLE,
};

enum libfptr_shift_state
{
    LIBFPTR_SS_CLOSED = 0,
    LIBFPTR_SS_OPENED,
    LIBFPTR_SS_EXPIRED,
};

enum libfptr_cut_type
{
    LIBFPTR_CT_FULL = 0,
    LIBFPTR_CT_PART,
};

enum libfptr_alignment
{
    LIBFPTR_ALIGNMENT_LEFT = 0,
    LIBFPTR_ALIGNMENT_CENTER,
    LIBFPTR_ALIGNMENT_RIGHT,
};

enum libfptr_text_wrap
{
    LIBFPTR_TW_NONE = 0,
    LIBFPTR_TW_WORDS,
    LIBFPTR_TW_CHARS,
};

enum libfptr_fn_type
{
    LIBFPTR_FNT_DEBUG = 0,
    LIBFPTR_FNT_RELEASE,
    LIBFPTR_FNT_UNKNOWN,
};

enum libfptr_fn_state
{
    LIBFPTR_FNS_INITIAL = 0,
    LIBFPTR_FNS_CONFIGURED = 1,
    LIBFPTR_FNS_FISCAL_MODE = 3,
    LIBFPTR_FNS_POSTFISCAL_MODE = 7,
    LIBFPTR_FNS_ACCESS_ARCHIVE = 15,
};

enum libfptr_receipt_type
{
    LIBFPTR_RT_CLOSED = 0,
    LIBFPTR_RT_SELL = 1,
    LIBFPTR_RT_SELL_RETURN = 2,
    LIBFPTR_RT_SELL_CORRECTION = 7,
    LIBFPTR_RT_SELL_RETURN_CORRECTION = 8,
    LIBFPTR_RT_BUY = 4,
    LIBFPTR_RT_BUY_RETURN = 5,
    LIBFPTR_RT_BUY_CORRECTION = 9,
    LIBFPTR_RT_BUY_RETURN_CORRECTION = 10,
};

enum libfptr_report_type
{
    LIBFPTR_RT_CLOSE_SHIFT = 0,
    LIBFPTR_RT_X,
    LIBFPTR_RT_LAST_DOCUMENT,
    LIBFPTR_RT_OFD_EXCHANGE_STATUS,
    LIBFPTR_RT_KKT_DEMO,
    LIBFPTR_RT_KKT_INFO,
    LIBFPTR_RT_OFD_TEST,
    LIBFPTR_RT_FN_DOC_BY_NUMBER,
    LIBFPTR_RT_QUANTITY,
    LIBFPTR_RT_DEPARTMENTS,
    LIBFPTR_RT_OPERATORS,
    LIBFPTR_RT_HOURS,
    LIBFPTR_RT_FN_REGISTRATIONS,
    LIBFPTR_RT_FN_SHIFT_TOTAL_COUNTERS,
    LIBFPTR_RT_FN_TOTAL_COUNTERS,
    LIBFPTR_RT_FN_NOT_SENT_DOCUMENTS_COUNTERS,
    LIBFPTR_RT_COMMODITIES_BY_TAXATION_TYPES,
    LIBFPTR_RT_COMMODITIES_BY_DEPARTMENTS,
    LIBFPTR_RT_COMMODITIES_BY_SUMS,
    LIBFPTR_RT_START_SERVICE
};

enum libfptr_payment_type
{
    LIBFPTR_PT_CASH = 0,
    LIBFPTR_PT_ELECTRONICALLY,
    LIBFPTR_PT_PREPAID,
    LIBFPTR_PT_CREDIT,
    LIBFPTR_PT_OTHER,
    LIBFPTR_PT_6,
    LIBFPTR_PT_7,
    LIBFPTR_PT_8,
    LIBFPTR_PT_9,
    LIBFPTR_PT_10
};

enum libfptr_tax_type
{
    LIBFPTR_TAX_DEPARTMENT = 0,
    LIBFPTR_TAX_VAT18 = 1,
    LIBFPTR_TAX_VAT10,
    LIBFPTR_TAX_VAT118,
    LIBFPTR_TAX_VAT110,
    LIBFPTR_TAX_VAT0,
    LIBFPTR_TAX_NO,
};

enum libfptr_external_device_type
{
    LIBFPTR_EXTERNAL_DEVICE_DISPLAY = 0,
    LIBFPTR_EXTERNAL_DEVICE_PINPAD,
    LIBFPTR_EXTERNAL_DEVICE_MODEM,
    LIBFPTR_EXTERNAL_DEVICE_BARCODE_SCANNER,
};

enum libfptr_kkt_data_type
{
    LIBFPTR_DT_STATUS = 0,
    LIBFPTR_DT_CASH_SUM,
    LIBFPTR_DT_UNIT_VERSION,
    LIBFPTR_DT_PICTURE_INFO,
    LIBFPTR_DT_LICENSE_ACTIVATED,
    LIBFPTR_DT_REGISTRATIONS_SUM,
    LIBFPTR_DT_REGISTRATIONS_COUNT,
    LIBFPTR_DT_PAYMENT_SUM,
    LIBFPTR_DT_CASHIN_SUM,
    LIBFPTR_DT_CASHIN_COUNT,
    LIBFPTR_DT_CASHOUT_SUM,
    LIBFPTR_DT_CASHOUT_COUNT,
    LIBFPTR_DT_REVENUE,
    LIBFPTR_DT_DATE_TIME,
    LIBFPTR_DT_SHIFT_STATE,
    LIBFPTR_DT_RECEIPT_STATE,
    LIBFPTR_DT_SERIAL_NUMBER,
    LIBFPTR_DT_MODEL_INFO,
    LIBFPTR_DT_RECEIPT_LINE_LENGTH,
    LIBFPTR_DT_CUTTER_RESOURCE,
    LIBFPTR_DT_STEP_RESOURCE,
    LIBFPTR_DT_TERMAL_RESOURCE,
    LIBFPTR_DT_ENVD_MODE,
    LIBFPTR_DT_SHIFT_TAX_SUM,
    LIBFPTR_DT_RECEIPT_TAX_SUM,
    LIBFPTR_DT_NON_NULLABLE_SUM,
    LIBFPTR_DT_RECEIPT_COUNT,
    LIBFPTR_DT_CANCELLATION_COUNT_ALL,
    LIBFPTR_DT_CANCELLATION_SUM,
    LIBFPTR_DT_CANCELLATION_SUM_ALL,
    LIBFPTR_DT_POWER_SOURCE_STATE,
    LIBFPTR_DT_CANCELLATION_COUNT,
    LIBFPTR_DT_NON_NULLABLE_SUM_BY_PAYMENTS,
    LIBFPTR_DT_PRINTER_TEMPERATURE,
    LIBFPTR_DT_FATAL_STATUS,
    LIBFPTR_DT_MAC_ADDRESS,
    LIBFPTR_DT_DEVICE_UPTIME,
    LIBFPTR_DT_RECEIPT_BYTE_COUNT,
    LIBFPTR_DT_DISCOUNT_AND_SURCHARGE_SUM,
    LIBFPTR_DT_LK_USER_CODE,
    LIBFPTR_DT_LAST_SENT_OFD_DOCUMENT_DATE_TIME
};

enum libfptr_fn_data_type
{
    LIBFPTR_FNDT_TAG_VALUE,
    LIBFPTR_FNDT_OFD_EXCHANGE_STATUS,
    LIBFPTR_FNDT_FN_INFO,
    LIBFPTR_FNDT_LAST_REGISTRATION,
    LIBFPTR_FNDT_LAST_RECEIPT,
    LIBFPTR_FNDT_LAST_DOCUMENT,
    LIBFPTR_FNDT_SHIFT,
    LIBFPTR_FNDT_FFD_VERSIONS,
    LIBFPTR_FNDT_VALIDITY,
    LIBFPTR_FNDT_REG_INFO,
    LIBFPTR_FNDT_DOCUMENTS_COUNT_IN_SHIFT,
    LIBFPTR_FNDT_ERRORS,
    LIBFPTR_FNDT_TICKET_BY_DOC_NUMBER,
    LIBFPTR_FNDT_DOCUMENT_BY_NUMBER
};

enum libfptr_ffd_version
{
    LIBFPTR_FFD_UNKNOWN = 0,
    LIBFPTR_FFD_1_0 = 100,
    LIBFPTR_FFD_1_0_5 = 105,
    LIBFPTR_FFD_1_1 = 110,
};

enum libfptr_taxation_type
{
    LIBFPTR_TT_DEFAULT = 0x00,
    LIBFPTR_TT_OSN = 0x01,
    LIBFPTR_TT_USN_INCOME = 0x02,
    LIBFPTR_TT_USN_INCOME_OUTCOME = 0x04,
    LIBFPTR_TT_ENVD = 0x08,
    LIBFPTR_TT_ESN = 0x10,
    LIBFPTR_TT_PATENT = 0x20,
};

enum libfptr_unit_type
{
    LIBFPTR_UT_FIRMWARE,
    LIBFPTR_UT_CONFIGURATION,
    LIBFPTR_UT_TEMPLATES,
    LIBFPTR_UT_CONTROL_UNIT,
    LIBFPTR_UT_BOOT,
};

enum libfptr_fn_operation_type
{
    LIBFPTR_FNOP_REGISTRATION = 0,
    LIBFPTR_FNOP_CHANGE_FN,
    LIBFPTR_FNOP_CHANGE_PARAMETERS,
    LIBFPTR_FNOP_CLOSE_ARCHIVE,
};

enum libfptr_agent_type
{
    LIBFPTR_AT_NONE = 0x00,
    LIBFPTR_AT_BANK_PAYING_AGENT = 0x01,
    LIBFPTR_AT_BANK_PAYING_SUBAGENT = 0x02,
    LIBFPTR_AT_PAYING_AGENT = 0x04,
    LIBFPTR_AT_PAYING_SUBAGENT = 0x08,
    LIBFPTR_AT_ATTORNEY = 0x10,
    LIBFPTR_AT_COMMISSION_AGENT = 0x20,
    LIBFPTR_AT_ANOTHER = 0x40,
};

enum libfptr_ofd_channel
{
    LIBFPTR_OFD_CHANNEL_NONE = 0,
    LIBFPTR_OFD_CHANNEL_USB,
    LIBFPTR_OFD_CHANNEL_PROTO
};

enum libfptr_power_source_type
{
    LIBFPTR_PST_POWER_SUPPLY = 0,
    LIBFPTR_PST_RTC_BATTERY,
    LIBFPTR_PST_BATTERY
};

enum libfptr_records_type
{
    LIBFPTR_RT_LAST_DOCUMENT_LINES,
    LIBFPTR_RT_FN_DOCUMENT_TLVS,
    LIBFPTR_RT_EXEC_USER_SCRIPT
};

enum libfptr_nomenclature_type
{
    LIBFPTR_NT_FURS = 0,
    LIBFPTR_NT_MEDICINES,
    LIBFPTR_NT_TOBACCO,
};

enum libfptr_fn_document_type
{
    LIBFPTR_FN_DOC_REGISTRATION = 1,
    LIBFPTR_FN_DOC_OPEN_SHIFT = 2,
    LIBFPTR_FN_DOC_RECEIPT = 3,
    LIBFPTR_FN_DOC_BSO = 4,
    LIBFPTR_FN_DOC_CLOSE_SHIFT = 5,
    LIBFPTR_FN_DOC_CLOSE_FN = 6,
    LIBFPTR_FN_DOC_OPERATOR_CONFIRMATION = 7,
    LIBFPTR_FN_DOC_REREGISTRATION = 11,
    LIBFPTR_FN_DOC_EXCHANGE_STATUS = 21,
    LIBFPTR_FN_DOC_CORRECTION = 31,
    LIBFPTR_FN_DOC_BSO_CORRECTION = 41,
};

enum libfptr_log_level
{
    LIBFPTR_LOG_ERROR = 0,
    LIBFPTR_LOG_WARN,
    LIBFPTR_LOG_INFO,
    LIBFPTR_LOG_DEBUG
};

enum libfptr_user_memory_operation
{
    LIBFPTR_UMO_GET_SIZE = 0,
    LIBFPTR_UMO_READ_DATA,
    LIBFPTR_UMO_WRITE_DATA,
    LIBFPTR_UMO_READ_STRING,
    LIBFPTR_UMO_WRITE_STRING,
    LIBFPTR_UMO_COMMIT,
};

enum libfptr_gui_parent
{
    LIBFPTR_GUI_PARENT_NATIVE = 0,
    LIBFPTR_GUI_PARENT_QT,
};

enum libfptr_defer_type
{
    LIBFPTR_DEFER_NONE = 0,
    LIBFPTR_DEFER_PRE,
    LIBFPTR_DEFER_POST
};

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_init_library(void *params);

DTOX_SHARED_EXPORT const char *DTOX_SHARED_CCA libfptr_get_version_string();

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_create(libfptr_handle *handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_set_settings(libfptr_handle handle,
                                                            const wchar_t *settings);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_destroy(libfptr_handle *handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_get_settings(libfptr_handle handle, wchar_t *value,
                                                            int size);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_get_single_setting(libfptr_handle handle,
                                                                  const wchar_t *key,
                                                                  wchar_t *value, int size);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_single_setting(libfptr_handle handle,
                                                                   const wchar_t *key,
                                                                   const wchar_t *value);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_apply_single_settings(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_open(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_close(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_is_opened(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_error_code(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_error_description(libfptr_handle handle,
                                                                 wchar_t *value, int size);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_bool(libfptr_handle handle, int param_id,
                                                               int value);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_int(libfptr_handle handle, int param_id,
                                                              uint value);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_double(libfptr_handle handle,
                                                                 int param_id,
                                                                 double value);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_str(libfptr_handle handle, int param_id,
                                                              const wchar_t *value);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_datetime(libfptr_handle handle,
                                                                   int param_id,
                                                                   int year, int month, int day,
                                                                   int hour, int minute,
                                                                   int second);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_set_param_bytearray(libfptr_handle handle,
                                                                    int param_id,
                                                                    const uchar *value, int size);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_get_param_bool(libfptr_handle handle, int param_id);

DTOX_SHARED_EXPORT uint DTOX_SHARED_CCA libfptr_get_param_int(libfptr_handle handle, int param_id);

DTOX_SHARED_EXPORT double DTOX_SHARED_CCA libfptr_get_param_double(libfptr_handle handle,
                                                                   int param_id);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_get_param_str(libfptr_handle handle, int param_id,
                                                             wchar_t *value, int size);

DTOX_SHARED_EXPORT void DTOX_SHARED_CCA libfptr_get_param_datetime(libfptr_handle handle,
                                                                   int param_id,
                                                                   int *year, int *month, int *day,
                                                                   int *hour, int *minute,
                                                                   int *second);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_get_param_bytearray(libfptr_handle handle,
                                                                   int param_id,
                                                                   uchar *value, int size);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_reset_params(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_run_command(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_beep(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_open_drawer(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_cut(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_device_poweroff(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_device_reboot(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_open_shift(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_reset_summary(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_init_device(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_query_data(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_cash_income(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_cash_outcome(libfptr_handle handle);


DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_open_receipt(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_cancel_receipt(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_close_receipt(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_check_document_closed(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_receipt_total(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_receipt_tax(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_registration(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_payment(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_report(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_print_text(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_print_cliche(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_begin_nonfiscal_document(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_end_nonfiscal_document(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_print_barcode(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_print_picture(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_print_picture_by_number(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_upload_picture_from_file(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_clear_pictures(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_write_device_setting_raw(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_read_device_setting_raw(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_commit_settings(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_init_settings(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_reset_settings(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_write_date_time(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_write_license(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_fn_operation(libfptr_handle handle);


DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_fn_query_data(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_fn_write_attributes(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_external_device_power_on(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_external_device_power_off(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_external_device_write_data(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_external_device_read_data(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_operator_login(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_process_json(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_read_device_setting(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_write_device_setting(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_begin_read_records(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_read_next_record(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_end_read_records(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_user_memory_operation(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_continue_print(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_init_mgm(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_util_form_tlv(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_util_mapping(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_util_form_nomenclature(libfptr_handle handle);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_log_write(const wchar_t *tag, int level,
                                                         const wchar_t *message);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_show_properties(libfptr_handle handle,
                                                               int parentType,
                                                               void *parent);

DTOX_SHARED_EXPORT int DTOX_SHARED_CCA libfptr_read_model_flags(libfptr_handle handle);

#ifdef __cplusplus
}
#endif

#endif // ATOL_DTOX_FPTR_H
