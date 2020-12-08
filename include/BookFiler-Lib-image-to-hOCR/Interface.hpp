/*
 * @name BookFiler™ Module for OCR
 * @author Branden Lee
 * @version 1.00
 * @license GNU LGPL v3
 * @brief OCR Module
 */

#ifndef BOOKFILER_LIB_IMAGE_TO_HOCR_INTERFACE_H
#define BOOKFILER_LIB_IMAGE_TO_HOCR_INTERFACE_H

// c++17
#include <functional>
#include <memory>
#include <string_view>
#include <vector>

/* rapidjson v1.1 (2016-8-25)
 * Developed by Tencent
 * License: MITs
 */
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>

/*
 * bookfiler = BookFiler™
 */
namespace bookfiler {

#ifndef BOOKFILER_MODULE_HTTP_H
#define BOOKFILER_MODULE_HTTP_H
class Http {
public:
  void get(std::string);
  void onSocket(std::function<void(Http)>);
  void onResponse(std::function<void(Http, std::string_view)>);
  void onClose(std::function<void(Http)>);
};
#endif // end BOOKFILER_MODULE_HTTP_H

#ifndef BOOKFILER_PIXMAP_H
#define BOOKFILER_PIXMAP_H
class Pixmap {
public:
  unsigned char *data;
  // created for debugging
  unsigned int *dataUINT;
  /* @param width pixel width
   * @param height pixel height
   * @param widthBytes The number of bytes in each scan line.
   * @param pixelBytes bytes in a pixel. Usually 8, 24 or 32.
   */
  long width;
  long height;
  long widthBytes;
  long bitsPerPixel;
  long informat;
  long samplesPerPixel;
};
#endif // end BOOKFILER_PIXMAP_H

} // namespace bookfiler

#endif // end BOOKFILER_LIB_IMAGE_TO_HOCR_INTERFACE_H
