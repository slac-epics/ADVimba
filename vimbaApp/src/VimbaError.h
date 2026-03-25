#ifndef VIMBA_ERROR_H
#define VIMBA_ERROR_H

#include <string>

#include "VmbC/VmbCommonTypes.h"

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
        VIMBA_ERROR(VmbErrorIncomplete);
        VIMBA_ERROR(VmbErrorIO);
        VIMBA_ERROR(VmbErrorValidValueSetNotPresent);
        VIMBA_ERROR(VmbErrorGenTLUnspecified);
        VIMBA_ERROR(VmbErrorUnspecified);
        VIMBA_ERROR(VmbErrorBusy);
        VIMBA_ERROR(VmbErrorNoData);
        VIMBA_ERROR(VmbErrorParsingChunkData);
        VIMBA_ERROR(VmbErrorInUse);
        VIMBA_ERROR(VmbErrorUnknown);
        VIMBA_ERROR(VmbErrorXml);
        VIMBA_ERROR(VmbErrorNotAvailable);
        VIMBA_ERROR(VmbErrorNotInitialized);
        VIMBA_ERROR(VmbErrorInvalidAddress);
        VIMBA_ERROR(VmbErrorAlready);
        VIMBA_ERROR(VmbErrorNoChunkData);
        VIMBA_ERROR(VmbErrorUserCallbackException);
        VIMBA_ERROR(VmbErrorFeaturesUnavailable);
        VIMBA_ERROR(VmbErrorTLNotFound);
        VIMBA_ERROR(VmbErrorAmbiguous);
        VIMBA_ERROR(VmbErrorRetriesExceeded);
        VIMBA_ERROR(VmbErrorInsufficientBufferCount);
        VIMBA_ERROR(VmbErrorCustom);
        default: return "Unknown error";
    }
}
#undef VIMBA_ERROR

std::string VimbaErrorCodes::desc(VmbError_t err) {
    switch (err) {
        case VmbErrorSuccess:                 return "Success";
        case VmbErrorInternalFault:           return "Unexpected fault in VmbApi or driver";
        case VmbErrorApiNotStarted:           return "API not started";
        case VmbErrorNotFound:                return "Not found";
        case VmbErrorBadHandle:               return "Invalid handle";
        case VmbErrorDeviceNotOpen:           return "Device not open";
        case VmbErrorInvalidAccess:           return "Invalid access";
        case VmbErrorBadParameter:            return "Bad parameter";
        case VmbErrorStructSize:              return "Wrong library version";
        case VmbErrorMoreData:                return "More data returned than memory provided";
        case VmbErrorWrongType:               return "Wrong type";
        case VmbErrorInvalidValue:            return "Invalid value";
        case VmbErrorTimeout:                 return "Timeout";
        case VmbErrorOther:                   return "TL error";
        case VmbErrorResources:               return "Resource not available";
        case VmbErrorInvalidCall:             return "Invalid call";
        case VmbErrorNoTL:                    return "TL not loaded";
        case VmbErrorNotImplemented:          return "Not implemented";
        case VmbErrorNotSupported:            return "Not supported";
        case VmbErrorIncomplete:              return "Incomplete";
        case VmbErrorIO:                      return "I/O";
        case VmbErrorValidValueSetNotPresent: return "Valid value set not present";
        case VmbErrorGenTLUnspecified:        return "GenTL unspecified";
        case VmbErrorUnspecified:             return "Unspecified";
        case VmbErrorBusy:                    return "Busy";
        case VmbErrorNoData:                  return "No data";
        case VmbErrorParsingChunkData:        return "Failed to Parse chunk data";
        case VmbErrorInUse:                   return "In use";
        case VmbErrorUnknown:                 return "Unknown";
        case VmbErrorXml:                     return "Xml";
        case VmbErrorNotAvailable:            return "Not Available";
        case VmbErrorNotInitialized:          return "Not Initialized";
        case VmbErrorInvalidAddress:          return "Invalid Address";
        case VmbErrorAlready:                 return "Already";
        case VmbErrorNoChunkData:             return "No chunk data";
        case VmbErrorUserCallbackException:   return "User callback exception";
        case VmbErrorFeaturesUnavailable:     return "Features unavailable";
        case VmbErrorTLNotFound:              return "TL not found";
        case VmbErrorAmbiguous:               return "Ambiguous";
        case VmbErrorRetriesExceeded:         return "Retries exceeded";
        case VmbErrorInsufficientBufferCount: return "Insufficient buffer count";
        case VmbErrorCustom:                  return "Custom";
        default:                              return "Unknown";
    }
}

#endif
