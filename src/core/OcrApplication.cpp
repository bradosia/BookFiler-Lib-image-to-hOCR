/*
 * @name BookFiler™ Library - Image to hOCR
 * @version 1.00
 * @license GNU LGPL v3
 * @brief Converts an image to hOCR. hOCR is data representation from running
 * an OCR .
 */

// Local Project
#include "OcrApplication.hpp"

/*
 * bookfiler = BookFiler™
 */
namespace bookfiler {

void OcrApplication::setHttpInterface(std::shared_ptr<Http>) {}
/* installing uses the HTTP interface to install data
 * from the internet
 */
void OcrApplication::installMode(std::string) {}
void OcrApplication::installType(std::string) {}
void OcrApplication::installLanguage(std::vector<std::string>) {}

} // namespace bookfiler
