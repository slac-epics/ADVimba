#ifndef VIMBA_ERROR_H
#define VIMBA_ERROR_H

#include <string>

#include "VimbaC/Include/VmbCommonTypes.h"

class VimbaErrorCodes
{
public:
    static std::string name(VmbError_t err);
    static std::string desc(VmbError_t err);
};

#define VIMBA_ERROR(x)  case x: return #x
std::string VimbaErrorCodes::name(VmbError_t err) {
    switch (err) {
        VIMBA_ERROR(VmbErrorSuccess);
        VIMBA_ERROR(VmbErrorInternalFault);
        VIMBA_ERROR(VmbErrorApiNotStarted);
        VIMBA_ERROR(VmbErrorNotFound);
        VIMBA_ERROR(VmbErrorBadHandle);
        VIMBA_ERROR(VmbErrorDeviceNotOpen);
        VIMBA_ERROR(VmbErrorInvalidAccess);
        VIMBA_ERROR(VmbErrorBadParameter);
        VIMBA_ERROR(VmbErrorStructSize);
        VIMBA_ERROR(VmbErrorMoreData);
        VIMBA_ERROR(VmbErrorWrongType);
        VIMBA_ERROR(VmbErrorInvalidValue);
        VIMBA_ERROR(VmbErrorTimeout);
        VIMBA_ERROR(VmbErrorOther);
        VIMBA_ERROR(VmbErrorResources);
        VIMBA_ERROR(VmbErrorInvalidCall);
        VIMBA_ERROR(VmbErrorNoTL);
        VIMBA_ERROR(VmbErrorNotImplemented);
        VIMBA_ERROR(VmbErrorNotSupported);
        default: return "Unknown error";
    }
}
#undef VIMBA_ERROR

std::string VimbaErrorCodes::desc(VmbError_t err) {
    switch (err) {
        case VmbErrorSuccess:           return "Success";
        case VmbErrorInternalFault:     return "Unexpected fault in VmbApi or driver";
        case VmbErrorApiNotStarted:     return "API not started";
        case VmbErrorNotFound:          return "Not found";
        case VmbErrorBadHandle:         return "Invalid handle";
        case VmbErrorDeviceNotOpen:     return "Device not open";
        case VmbErrorInvalidAccess:     return "Invalid access";
        case VmbErrorBadParameter:      return "Bad parameter";
        case VmbErrorStructSize:        return "Wrong library version";
        case VmbErrorMoreData:          return "More data returned than memory provided";
        case VmbErrorWrongType:         return "Wrong type";
        case VmbErrorInvalidValue:      return "Invalid value";
        case VmbErrorTimeout:           return "Timeout";
        case VmbErrorOther:             return "TL error";
        case VmbErrorResources:         return "Resource not available";
        case VmbErrorInvalidCall:       return "Invalid call";
        case VmbErrorNoTL:              return "TL not loaded";
        case VmbErrorNotImplemented:    return "Not implemented";
        case VmbErrorNotSupported:      return "Not supported";
        default:                        return "Unknown";
    }
}

#endif
