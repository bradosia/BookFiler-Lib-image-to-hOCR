/*
 * @name BookFiler™ Library - Image to hOCR
 * @version 1.00
 * @license GNU LGPL v3
 * @brief Converts an image to hOCR. hOCR is data representation from running
 * an OCR .
 */

#ifndef BOOKFILER_LIB_IMAGE_TO_HOCR_OCR_H
#define BOOKFILER_LIB_IMAGE_TO_HOCR_OCR_H

// config
#include "config.hpp"

// c++17
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>

/* boost 1.72.0
 * License: Boost Software License (similar to BSD and MIT)
 */
#include <boost/signals2.hpp>

/* rapidjson v1.1 (2016-8-25)
 * Developed by Tencent
 * License: MITs
 */
#include <rapidjson/document.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/reader.h> // rapidjson::ParseResult
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

/* leptonica 1.79.0
 * License: BSD
 */
#include <leptonica/allheaders.h>

/* tesseract 4.1.1
 * License: Apache License 2.0
 */
#include <tesseract/baseapi.h>
#include <tesseract/ocrclass.h>

// Local Project
#include <BookFiler-Lib-image-to-hOCR/Interface.hpp>

/*
 * bookfiler = BookFiler™
 */
namespace bookfiler {

class OcrInternal : public std::enable_shared_from_this<OcrInternal> {
private:
  std::shared_ptr<tesseract::TessBaseAPI> api;
  std::shared_ptr<OcrMonitorInternal> monitor;
  std::shared_ptr<Pixmap> pixmap;
  Pix *image;
  boost::signals2::signal<void(std::shared_ptr<OcrInternal>)>
      signalRecognizeDone;

public:
  OcrInternal();
  ~OcrInternal();
  bool openImageFile(std::string);
  bool openImagePixmap(unsigned char *data, long width, long height,
                       long pixelBytes);
  bool openImagePixmapPtr(std::shared_ptr<Pixmap>);
  std::shared_ptr<Pixmap> getPixmap();
  void setMode(std::string);
  void setType(std::string);
  void setLanguage(std::vector<std::string>);
  void setDataPath(std::string);
  void recognize();
  void recognizeThread();
  void connectRecognizeDone(std::function<void(std::shared_ptr<OcrInternal>)>);
  std::shared_ptr<OcrMonitor> getRecognizeMonitor();
  std::shared_ptr<OcrMonitor> getHocrMonitor();
  std::string getHocr();

  void setHttpInterface(std::shared_ptr<Http>);
  void installMode(std::string);
  void installType(std::string);
  void installLanguage(std::vector<std::string>);
};

} // namespace bookfiler

#endif
// end BOOKFILER_LIB_IMAGE_TO_HOCR_OCR_H
