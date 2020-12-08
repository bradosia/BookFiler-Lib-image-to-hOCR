/*
 * @name BookFiler™ Library - Image to hOCR
 * @version 1.00
 * @license GNU LGPL v3
 * @brief Converts an image to hOCR. hOCR is data representation from running
 * an OCR .
 */

// Local Project
#include "OcrMonitor.hpp"

/*
 * bookfiler = BookFiler™
 */
namespace bookfiler {

OcrMonitorInternal::OcrMonitorInternal() {
  monitor = std::make_shared<ETEXT_DESC>();
}
OcrMonitorInternal::OcrMonitorInternal(std::shared_ptr<ETEXT_DESC> monitor_)
    : monitor(monitor_) {}
OcrMonitorInternal::~OcrMonitorInternal() {}
unsigned long OcrMonitorInternal::getAvailable() { return monitor->count; }
unsigned long OcrMonitorInternal::getTotal() { return monitor->progress; }

} // namespace bookfiler
