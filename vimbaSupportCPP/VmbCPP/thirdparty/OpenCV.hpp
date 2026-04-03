/*=============================================================================
  Copyright (C) 2025 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        OpenCV.hpp

  Description: Header file for OpenCV helper functions

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/
#ifndef VMBCPP_OPENCV_HPP
#define VMBCPP_OPENCV_HPP
#include <VmbCPP/Frame.h>
#include <opencv2/core.hpp>

namespace VmbCPP
{
namespace
{
/**
 * \brief     Map the given vmbFormat to a compatible OpenCV format
 *
 * \param[in ]   vmbFormat  The Pixelformat that should be mapped
 * \param[out]   cvFormat   The compatible OpenCV format for the given vmbFormat
 *
 * \returns ::VmbErrorType
 *
 * \retval ::VmbErrorSuccess       If no error
 * \retval ::VmbErrorInvalidValue  If the vmbFormat has no equivalent OpenCV format
 */
VmbErrorType VmbPixelFormatToCvFormat( VmbPixelFormatType vmbFormat, int& cvFormat )
{
    switch( vmbFormat )
    {
    case VmbPixelFormatMono8:
    case VmbPixelFormatBayerGR8:
    case VmbPixelFormatBayerRG8:
    case VmbPixelFormatBayerGB8:
    case VmbPixelFormatBayerBG8:
        cvFormat = CV_8UC1;
        break;
    case VmbPixelFormatMono10:
    case VmbPixelFormatMono12:
    case VmbPixelFormatMono14:
    case VmbPixelFormatMono16:
    case VmbPixelFormatBayerGR10:
    case VmbPixelFormatBayerRG10:
    case VmbPixelFormatBayerGB10:
    case VmbPixelFormatBayerBG10:
    case VmbPixelFormatBayerGR12:
    case VmbPixelFormatBayerRG12:
    case VmbPixelFormatBayerGB12:
    case VmbPixelFormatBayerBG12:
    case VmbPixelFormatBayerGR16:
    case VmbPixelFormatBayerRG16:
    case VmbPixelFormatBayerGB16:
    case VmbPixelFormatBayerBG16:
        cvFormat = CV_16UC1;
        break;
    case VmbPixelFormatRgb8:
    case VmbPixelFormatBgr8:
        cvFormat = CV_8UC3;
        break;
    case VmbPixelFormatRgba8:
    case VmbPixelFormatBgra8:
        cvFormat = CV_8UC4;
        break;
    case VmbPixelFormatRgb10:
    case VmbPixelFormatBgr10:
    case VmbPixelFormatRgb12:
    case VmbPixelFormatBgr12:
    case VmbPixelFormatRgb14:
    case VmbPixelFormatBgr14:
    case VmbPixelFormatRgb16:
    case VmbPixelFormatBgr16:
        cvFormat = CV_16UC3;
        break;
    case VmbPixelFormatRgba10:
    case VmbPixelFormatBgra10:
    case VmbPixelFormatRgba12:
    case VmbPixelFormatBgra12:
    case VmbPixelFormatRgba14:
    case VmbPixelFormatBgra14:
    case VmbPixelFormatRgba16:
    case VmbPixelFormatBgra16:
        cvFormat = CV_16UC4;
        break;
    default:
        return VmbErrorType::VmbErrorInvalidValue;
    }
    return VmbErrorType::VmbErrorSuccess;
}

} // namespace

/**
 * \brief     Create an OpenCV Mat image from the passed frame by reusing the same memory
 *
 * This function creates an OpenCV Mat instance that reuses the same memory for pixel data as the
 * passed frame. This means that the frame should not be reused for further frame transmissions
 * until the Mat instance has gone out of scope. This function does not perform any kind of
 * transformations. The pixel data will have the same layout that the passed frame has.
 *
 * \param[in ]   vmbFrame   The frame that holds the image data that should be used
 * \param[out]   cvImage    The OpenCV Mat that points to the same memory as the passed frame
 *
 * \returns ::VmbErrorType
 *
 * \retval ::VmbErrorSuccess       If no error
 * \retval ::VmbErrorNotAvailable  If the vmbFrames width or height could not be read
 * \retval ::VmbErrorInvalidValue  If the vmbFrame has an unsupported PixelFormat
 */
inline VmbErrorType VmbFrameToMat( VmbCPP::FramePtr vmbFrame, cv::Mat& cvImage )
{
    VmbErrorType err = VmbErrorType::VmbErrorSuccess;
    VmbUint32_t width = 0, height = 0;
    err = vmbFrame->GetWidth( width );
    if( err != VmbErrorType::VmbErrorSuccess )
    {
        return err;
    }
    err = vmbFrame->GetHeight( height );
    if( err != VmbErrorType::VmbErrorSuccess )
    {
        return err;
    }
    assert( width > 0 );
    assert( height > 0 );
    VmbPixelFormatType vmbFormat;
    err = vmbFrame->GetPixelFormat( vmbFormat );
    if( err != VmbErrorType::VmbErrorSuccess )
    {
        return err;
    }
    VmbUchar_t* imageData;
    err = vmbFrame->GetImage( imageData );
    if( err != VmbErrorType::VmbErrorSuccess )
    {
        return err;
    }
    assert( imageData != nullptr );
    // Convert everything to expected types for OpenCV function call
    int cvFormat;
    auto cols = static_cast<int>( width );
    auto rows = static_cast<int>( height );
    err = VmbPixelFormatToCvFormat( vmbFormat, cvFormat );
    if( err != VmbErrorType::VmbErrorSuccess )
    {
        return err;
    }
    cvImage = cv::Mat{ cv::Size{ cols, rows }, cvFormat, imageData };
    return VmbErrorType::VmbErrorSuccess;
}

} // namespace VmbCPP

#endif
